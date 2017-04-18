#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

#define MAX 1010
#define INF (int) 1e9
#define pb push_back

int n, root, cost, prev[MAX], g[MAX][MAX];
bool gb[MAX][MAX], cycle[MAX], mark[MAX];
vector<int> ga[MAX];

void addEdge(int u, int v, int w)
{
	if(gb[u][v]) g[u][v] = min(g[u][v], w);
	else
	{
		ga[u].pb(v);
		g[u][v] = w;
	}
	gb[u][v] = 1;
}

void dfs(int v)
{
	mark[v] = 1;
	for(int i=0; i<(int)ga[v].size(); ++i)
	{
		int u = ga[v][i];
		if(!mark[u] && gb[v][u]) dfs(u);
	}
}

bool check()
{
	memset(mark, 0, sizeof(mark));
	dfs(root);

	for(int i=0; i<n; ++i)
		if(!mark[i])
			return 0;
	return 1;
}

int existCycle()
{
	prev[root] = root;
	for(int i=0; i<n; ++i)
		if(!cycle[i] && i!=root)
		{
			prev[i] = i;
			g[i][i] = INF;

			for(int j=0; j<n; ++j)
				if(!cycle[j] && gb[j][i] && g[j][i] < g[prev[i]][i])
					prev[i] = j;
		}
	
	for(int i=0, j; i<n; ++i)
	{
		if(cycle[i]) continue;
		memset(mark, 0, sizeof(mark));
		
		j = i;
		while(!mark[j])
		{
			mark[j] = 1;
			j = prev[j];
		}

		if(j == root) continue;
		return j;
	}

	return -1;
}

void update(int v)
{
	cost += g[prev[v]][v];

	for(int i=prev[v]; i!=v; i = prev[i])
	{
		cost += g[prev[i]][i];
		cycle[i] = 1;
	}

	for(int i=0; i<n; ++i)
		if(!cycle[i] && gb[i][v])
			g[i][v] -= g[prev[v]][v];
	
	for(int j=prev[v]; j!=v; j=prev[j])
		for(int i=0; i<n; ++i)
		{
			if(cycle[i]) continue;

			if(gb[i][j])
			{
				if(gb[i][v]) g[i][v] = min(g[i][v], g[i][j] - g[prev[j]][j]);
				else g[i][v] = g[i][j] - g[prev[j]][j];
				gb[i][v] = 1;
			}
		
			if(gb[j][i])
			{
				if(gb[v][i]) g[v][i] = min(g[v][i], g[j][i]);
				else g[v][i] = g[j][i];
				gb[v][i] = 1;
			}
		}
}

bool minCostArborescense(int _root)
{
	root = _root;
	if(!check()) return 0;

	memset(cycle, 0, sizeof(cycle));
	cost = 0;
	
	int v;
	while((v = existCycle()) != -1) update(v);

	for(int i=0; i<n; ++i)
		if(i!=root && !cycle[i])
			cost += g[prev[i]][i];

	return 1;
}

int main()
{
	int t, m, u, v, w;

	scanf("%d", &t);	
	for(int tc=1; tc<=t; ++tc)
	{
		for(int i=0; i<n; ++i) ga[i].clear();
		memset(g, 0, sizeof(g)); 
		memset(gb, 0, sizeof(gb)); 
		cost = 0;

		scanf("%d %d", &n, &m);
		while(m--)
		{
			scanf("%d %d %d", &u, &v, &w);
			addEdge(u, v, w);
		}
		printf("Case #%d: ", tc);
		if(minCostArborescense(0)) printf("%d\n", cost);
		else puts("Possums!");
	}

	return 0;
}
