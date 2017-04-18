#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 105

bool mark[MAX];
int n, m, s, dist[MAX], g2[MAX][MAX];
vector< pair<int, int> > g[MAX];

bool dfs(int u, int dad)
{
	mark[u] = 1;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i].first;
		if(v != dad)
		{
			if(mark[v]) return 1;
			dist[v] = dist[u] + g2[u][v];
			if(dfs(v, u)) return 1;
		}
	}

	return 0;
}

int main()
{
	memset(g2, 0, sizeof(g2));
	scanf("%d %d %d", &n, &m, &s);
	for(int i=0; i<m; ++i)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		g[u].pb(mp(v, w));
		g[v].pb(mp(u, w));
		g2[u][v] = max(g2[u][v], w);
		g2[v][u] = max(g2[v][u], w);
	}
	
	for(int i=0; i<n; ++i)
	{
		memset(mark, 0, sizeof(mark));
		dist[i] = 0;
		if(dfs(i, -1))
		{
			puts("YES");
			return 0;
		}
		for(int j=0; j<n; ++j)
			if(dist[j] >= s)
			{
				puts("YES");
				return 0;
			}
	}
	puts("NO");

	return 0;
}
