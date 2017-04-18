//O(|E|*sqrt(|V|))

#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define mp make_pair
#define pb push_back

#define MAX 2010
#define INF (int)1e9
#define NIL 0

vector<int> g[MAX];
int match[MAX], dist[MAX], n, m;
bool sett[MAX]; //used in vertex cover algorithm, if sett[u] == 0 and u is in the left side so u is in the vertex cover. If sett[u] == 1 and u is in the right side so u is in the vertex cover;
bool mark[MAX];
//n == number of vertices in the left side, m == number of vertices in the right side
//indices for left side: 1...n, indices for right side: n+1...m
//only need edge from left to right

bool bfs()
{	
	int i, u, v;
	queue<int> q;
	
	for(i=1; i<=n; ++i)
	{
		if(match[i] == NIL)
		{
			dist[i] = 0;
			q.push(i);
		}
		else dist[i] = INF;
	}

	dist[NIL] = INF;
	while(!q.empty())
	{
		u = q.front(); q.pop();
		if(u != NIL)
		{
			for(i=0; i<(int)g[u].size(); ++i)
			{
				v = g[u][i];
				if(dist[match[v]] == INF)
				{
					dist[match[v]] = dist[u] + 1;
					q.push(match[v]);
				}
			}
		}
	}
	
	return (dist[NIL] != INF);
}

bool dfs(int u)
{
	int i, v;
	
	if(u != NIL)
	{
		for(i=0; i<(int)g[u].size(); ++i)
		{
			v = g[u][i];
			if(dist[match[v]] == dist[u] + 1 && dfs(match[v]))
			{
				match[v] = u; match[u] = v;
				return 1;
			}
		}
		
		dist[u] = INF;
		return 0;
	}
	
	return 1;
}

int hopcroftKarp()
{
	int matching = 0, i;
	for(int i=0; i<=n+m; ++i) match[i] = NIL;
	while(bfs())
		for(i=1; i<=n; ++i)
			if(match[i] == NIL && dfs(i))
				++matching;
	return matching;
}

//return indice of vertices from right side. indice of vertices of the vertice side don't need adjusts
inline int indm(int u)
{
	return n + u;
}

void increaseSet(int u)
{
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		sett[v] = mark[v] = 1;
		if(!mark[match[v]])
		{
			sett[match[v]] = mark[match[v]] = 1;
			increaseSet(match[v]);
		}
	}
}

void vertexCoverBipartite()
{
	for(int i=1; i<=n; ++i)
	{
		if(match[i] == NIL) sett[i] = 1;
		else sett[i] = 0;
	}
	for(int i=1; i<=m; ++i) sett[indm(i)] = 0;
	memset(mark, 0, sizeof(mark));
	
	for(int i=1; i<=n; ++i)
		if(sett[i] && !mark[i])
			mark[i] = 1, increaseSet(i);
	
	//print solution
	for(int i=1; i<=n; ++i)
		if(sett[i] == 0)
			printf(" r%d", i);
	for(int i=1; i<=m; ++i)
		if(sett[indm(i)] == 1)
			printf(" c%d", i);
	puts("");
}

int main()
{
	int e, u, v;

	while(scanf("%d %d %d", &n, &m, &e) && (n && m && e))
	{
		for(int i=0; i<=n+m; ++i) g[i].clear();
		while(e--)
		{
			scanf("%d %d", &u, &v);
			g[u].pb(indm(v));
			g[indm(v)].pb(u);
		}
		
		printf("%d", hopcroftKarp());
		vertexCoverBipartite();
	}

	return 0;
}

