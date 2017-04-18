#include<cstdio>
#include<set>
#include<vector>
using namespace std;

#define MAX 260
#define INF (int) 1e9
#define mp make_pair
int main()
{
	int n, m, c, k, dist[MAX], u, v, w, g2[MAX][MAX];
	bool mark[MAX];
	vector< vector< pair<int, int> > > g;
	vector< pair<int, int> > ve;
	set< pair<int, int> > heap;
	
	ve.clear();
	
	while(scanf("%d %d %d %d", &n, &m, &c, &k) && n)
	{
		--c;
		g.assign(n, ve);
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				g2[i][j] = INF;
		while(m--)
		{
			scanf("%d %d %d", &v, &u, &w);
			g[u].push_back(mp(v, w));
			g[v].push_back(mp(u, w));
			g2[u][v] = g2[v][u] = w;
		}
		for(int i=0; i<n; ++i)
		{
			mark[i] = 0;
			dist[i] = INF;
		}
		
		heap.clear();
		dist[c] = 0;
		heap.insert(mp(0, c));
		for(int i=c-1; i>=0; --i)
		{
			dist[i] = g2[i+1][i] + dist[i+1];
			mark[i] = 1;
			heap.insert(mp(dist[i], i));
		}
		while(!heap.empty())
		{
			v = (heap.begin())->second;
			heap.erase(heap.begin());
			if(v == k)
				break;
			mark[v] = 1;
			
			for(int i=0; i<(int)g[v].size(); ++i)
			{
				u = g[v][i].first; w = g[v][i].second;
				if(!mark[u] && dist[u] > dist[v] + w)
				{
					heap.erase(mp(dist[u], u));
					dist[u] = dist[v] + w;
					heap.insert(mp(dist[u], u));
				}
			}
		}
		printf("%d\n", dist[k]);
	}
	
	return 0;
}