#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 205
#define INF 1e9

vector<int> g[MAX];
int n, flow[MAX][MAX], cap[MAX][MAX], dist[MAX], dad[MAX];
bool mark[MAX];

bool bfs(int s, int t)
{
	queue<int> q;
	memset(mark, 0, n*sizeof(bool));
	mark[s] = 1; dad[s] = -1;
	q.push(s);
	while(!q.empty())
	{
		int v = q.front(); q.pop();
		if(v == t)
			return 1;
		for(int i=0; i<(int)g[v].size(); ++i)
		{
			int u = g[v][i];
			if(!mark[u] && cap[v][u] - flow[v][u] > 0)
			{
				mark[u] = 1;
				dad[u] = v;
				q.push(u);
			}
		}
	}
	return 0;
}

int edmondsKarp(int s, int t)
{
	int bottleneck, f = 0;
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			flow[i][j] = 0;
	
	while(bfs(s, t))
	{
		bottleneck = INF;
		for(int v = t; dad[v] != -1; v = dad[v])
			bottleneck = min(bottleneck, cap[dad[v]][v] - flow[dad[v]][v]);
		
		for(int v = t; dad[v] != -1; v = dad[v])
		{
			flow[dad[v]][v] += bottleneck;
			flow[v][dad[v]] -= bottleneck;
		}
		
		f += bottleneck;
		
	}
	return f;
}

int main()
{
	int s, t, m, u, v, ns, nc;

	for(int tc=1; scanf("%d %d %d", &nc, &ns, &m) == 3; ++tc)
	{
		for(int i=0; i<n; ++i) g[i].clear();
		memset(cap, 0, sizeof(cap));
		
		s = 0; t = nc + ns + 1;
		n = t + 1;
		for(int i=ns+1; i<n-1; ++i)
		{
			scanf("%d", &cap[i][t]);
			g[i].pb(t); g[t].pb(i);
		}
		for(int i=1; i<=ns; ++i)
		{
			cap[s][i] = 1;
			g[i].pb(s); g[s].pb(i);
		}
		while(m--)
		{
			scanf("%d %d", &u, &v);
			cap[v][ns + u] = 1;
			g[v].pb(ns + u); g[ns + u].pb(v);
		}
		printf("Instancia %d\n%d\n\n", tc, edmondsKarp(s, t));
	}
	
	return 0;
}
