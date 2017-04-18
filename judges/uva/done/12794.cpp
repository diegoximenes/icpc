#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define MAX 10005
#define INF 0x3f3f3f3f

vector< pair<int, int> > g[MAX];
bool mark[MAX];
int cycleLen[MAX], dist[MAX];
pair<int, int> dad[MAX];

void dfs(int u, int dadu, int lastw)
{
	dad[u] = mp(dadu, lastw);
	mark[u] = 1;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i].first, w = g[u][i].second;
		
		if(!mark[v]) dfs(v, u, w);
		else if(mark[v] && v != dadu && cycleLen[v] == -1)
		{
			int len = w;
			vector<int> cycle; cycle.pb(u); cycle.pb(v);
			int x = dad[u].first; 
			len += dad[u].second;
			while(x != v)
			{
				len += dad[x].second;
				cycle.pb(x);
				x = dad[x].first;
			}
				
			for(int i=0; i<(int)cycle.size(); ++i) cycleLen[cycle[i]] = len;
		}
	}
}

int main()
{
	int n, m;

	while(scanf("%d %d", &n, &m) == 2)
	{
		for(int i=0; i<n; ++i) g[i].clear();

		while(m--)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			--u; --v;
			g[u].pb(mp(v, w));
			g[v].pb(mp(u, w));
		}
		
		for(int i=0; i<n; ++i) mark[i] = 0, cycleLen[i] = -1;
		for(int i=0; i<n; ++i)
			if(!mark[i])
				dfs(i, -1, -1);
		
		int q;
		scanf("%d", &q);
		while(q--)
		{
			int s, len;
			scanf("%d %d", &s, &len);
			--s;
			
			int sol = INF;
			
			set< pair<int, int> > heap;
			for(int i=0; i<n; ++i) dist[i] = INF, mark[i] = 0;
			dist[s] = 0;
			heap.insert(mp(dist[s], s));
			while(!heap.empty())
			{
				int u = heap.begin()->second;
				mark[u] = 1;
				heap.erase(heap.begin());
				
				if(cycleLen[u] >= len) sol = min(sol, 2*dist[u] + cycleLen[u]);

				for(int i=0; i<(int)g[u].size(); ++i)
				{
					int v = g[u][i].first, w = g[u][i].second;
					if(!mark[v] && dist[v] > dist[u] + w)
					{
						heap.erase(mp(dist[v], v));
						dist[v] = dist[u] + w;
						heap.insert(mp(dist[v], v));
					}
				}
			}

			if(sol == INF) puts("-1");
			else printf("%d\n", sol);
		}
	}

	return 0;
}
