#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

#define mp make_pair
#define MAX 200
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
	int m, u, v, w, s, t, taux;
	
	while(scanf("%d %d", &n, &m) && n)
	{
		s = 0; t = 1+2*(n-2); taux = n-1;
		for(int i=s; i<=t; ++i)
		{
			for(int j=s; j<=t; ++j)
				cap[i][j] = 0;
			g[i].clear();
		}
			
		for(int i=0; i<n-2; ++i)
		{
			scanf("%d %d", &v, &w);
			--v;
			g[2*v-1].push_back(2*v);
			g[2*v].push_back(2*v-1);
			cap[2*v-1][2*v] = w;
		}
		
		while(m--)
		{
			scanf("%d %d %d", &u, &v, &w);
			--u; --v;
			if((u==s && v==taux) || (u==taux && v==s))
			{
				g[s].push_back(t);
				cap[s][t] = w;
			}
			else if(u == s)
			{
				g[s].push_back(2*v-1);
				cap[s][2*v-1] = w;
			}
			else if(v == s)
			{
				g[s].push_back(2*u-1);
				cap[s][2*u-1] = w;
			}
			else if(u == taux)
			{
				g[2*v].push_back(t);
				cap[2*v][t] = w;
			}
			else if(v == taux)
			{
				g[2*u].push_back(t);
				cap[2*u][t] = w;
			}
			else
			{
				g[2*v].push_back(2*u-1); g[2*u-1].push_back(2*v);
				g[2*u].push_back(2*v-1); g[2*v-1].push_back(2*u);
				cap[2*v][2*u-1] = w;
				cap[2*u][2*v-1] = w;
			}
		}
		
		n = t+1;
		printf("%d\n", edmondsKarp(s, t));
	}
	
	return 0;
}