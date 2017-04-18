#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define MAX 100005
#define KMAX 505
#define INF 0x3f3f3f3f

int color[MAX], n, m, k, dist[KMAX][KMAX];
vector<int> g[MAX];
set<int> component[KMAX];
bool mark[MAX];

void dfs(int u, int comp)
{
	component[color[u]].insert(comp);
	mark[u] = 1;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(!mark[v]) dfs(v, comp);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	int u = 0, v, w;
	for(int i=0; i<k; ++i)
	{
		int qtd;
		scanf("%d", &qtd);
		for(int j=0; j<qtd; ++j, ++u) color[u] = i;
	}
			
	vector< pair< pair<int, int>, int > > edge;
	for(int i=0; i<m; ++i)
	{
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		edge.pb(mp(mp(u, v), w));
		if(w == 0) g[u].pb(v), g[v].pb(u);
	}
	
	memset(mark, 0, sizeof(mark));
	int comp = 0;
	for(int i=0; i<n; ++i)
		if(!mark[i])
			dfs(i, comp++);
	
	bool can = 1;
	for(int i=0; i<k; ++i)
		if((int)component[i].size() > 1)
			can = 0;

	if(!can) puts("No");
	else
	{
		memset(dist, INF, sizeof(dist));
		for(int i=0; i<k; ++i) dist[i][i] = 0;

		for(int i=0; i<m; ++i)
		{
			int u = color[edge[i].fi.fi], v = color[edge[i].fi.se], w = edge[i].se;
			dist[v][u] = dist[u][v] = min(dist[u][v], w);
		}
		
		for(int l=0; l<k; ++l)
			for(int i=0; i<k; ++i)
				for(int j=0; j<k; ++j)
					dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);

		puts("Yes");
		for(int i=0; i<k; ++i, puts(""))
		{
			if(dist[i][0] == INF) printf("-1");
			else printf("%d", dist[i][0]);

			for(int j=1; j<k; ++j)
			{
				if(dist[i][j] == INF) printf(" -1");
				else printf(" %d", dist[i][j]);
			}	
		}
	}
	return 0;
}
