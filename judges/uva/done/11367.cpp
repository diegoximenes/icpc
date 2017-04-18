#include<cstdio>
#include<vector>
#include<set>
#include<bitset>
#include<queue>
using namespace std;

#define mp make_pair
#define MAX 1010
#define MAXC 110
#define INF 1e9

int dist[MAX][MAXC], p[MAX];
bool mark[MAX][MAXC];
vector< pair<int, int> > g[MAX];

void init(int n, int c)
{
	for(int i=0; i<n; ++i)
		for(int j=0; j<=c; ++j)
		{
			dist[i][j] = INF;
			mark[i][j] = 0;
		}
}

int dijkstra(int s, int t, int c)
{
	set< pair< int, pair<int, int> > > heap;
	heap.insert(mp(0, mp(s, 0)));
	dist[s][0] = 0;
	while(!heap.empty())
	{
		int v = heap.begin()->second.first, f = heap.begin()->second.second;
		heap.erase(heap.begin());
		mark[v][f] = 1;
		if(v == t)
			return dist[v][f];
		
		if(f+1<=c && !mark[v][f+1] && dist[v][f+1] > dist[v][f] + p[v])
		{
			heap.erase(mp(dist[v][f+1], mp(v, f+1)));
			dist[v][f+1] = dist[v][f] + p[v];
			heap.insert(mp(dist[v][f+1], mp(v, f+1)));
		}
		for(int i=0; i<(int)g[v].size(); ++i)
		{
			int u = g[v][i].first, w = g[v][i].second;
			
			if(f-w>=0 && !mark[u][f-w] && dist[u][f-w] > dist[v][f])
			{
				heap.erase(mp(dist[u][f-w], mp(u, f-w)));
				dist[u][f-w] = dist[v][f];
				heap.insert(mp(dist[u][f-w], mp(u, f-w)));
			}
		}
	}
	
	return INF;
}

int main()
{	
	int n, m, s, t, c, v, u, w, q;
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		scanf("%d", &p[i]);
	while(m--)
	{
		scanf("%d %d %d", &v, &u, &w);
		g[v].push_back(mp(u, w));
		g[u].push_back(mp(v, w));
	}
	
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d %d %d", &c, &s, &t);
		
		init(n, c);
		int d = dijkstra(s, t, c);
		if(d == INF)
			puts("impossible");
		else
			printf("%d\n", d);
		
	}
	
	return 0;
}
