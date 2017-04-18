#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define MAX 100005
#define INF 0x3f3f3f3f

int dist[MAX];
bool mark[MAX];
vector< pair<int, int> > g[MAX];

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);
	while(m--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		g[u].pb(mp(v, 0));
		g[v].pb(mp(u, 1));
	}
	
	memset(dist, INF, sizeof(dist));
	memset(mark, 0, sizeof(mark));
	set< pair<int, int> > heap;
	dist[0] = 0; heap.insert(mp(dist[0], 0));
	while(!heap.empty())
	{
		int u = heap.begin()->second;
		heap.erase(heap.begin());
		mark[u] = 1;
		if(u == n-1) break;

		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int v = g[u][i].first, reversed = g[u][i].second;
			if(!mark[v] && dist[v] > dist[u] + reversed)
			{
				heap.erase(mp(dist[v], v));
				dist[v] = dist[u] + reversed;
				heap.insert(mp(dist[v], v));
			}
		}
	}
	
	if(!mark[n-1]) puts("-1");
	else printf("%d\n", dist[n-1]);

	return 0;
}
