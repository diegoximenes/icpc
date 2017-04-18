#include<cstdio>
#include<cstring>
#include<climits>
#include<set>
#include<vector>
#include<list>
using namespace std;

#define MAX 1000100
#define INF INT_MAX

int dist[MAX];
bool mark[MAX];

int main()
{
	int n, u, v, w, cost, p, q;
	vector< list< pair<int, int> > > g;
	vector< list< pair<int, int> > > grev;
	set< pair<int, int> > heap;
	list< pair<int, int> > l;
	list< pair<int, int> >::iterator it;
	
	g.resize(MAX);
	grev.resize(MAX);
	l.clear();
	
	scanf("%d", &n);
	
	while(n--)
	{
		scanf("%d %d", &p, &q);
		
		g.assign(p+1, l);
		grev.assign(p+1, l);
		
		while(q--)
		{
			scanf("%d %d %d", &u, &v, &w);
			
			g[u].push_front(make_pair(v, w));
			grev[v].push_front(make_pair(u, w));
		}
		
		cost = 0;
		
		memset(mark, 0, (p+1)*sizeof(bool));
		for(int i=1; i<=p; ++i)
			dist[i] = INF;
		heap.clear();
		
		dist[1] = 0;
		heap.insert(make_pair(0, 1));
		
		while(!heap.empty())
		{
			v = (heap.begin())->second;
			heap.erase(heap.begin());
			mark[v] = 1;
			
			cost += dist[v];
			
			for(it=g[v].begin(); it!=g[v].end(); ++it)
			{
				u = it->first;
				w = it->second;
				if(!mark[u] && (dist[u] > dist[v] + w))
				{
					heap.erase(make_pair(dist[u], u));
					dist[u] = dist[v] + w;
					heap.insert(make_pair(dist[u], u));
				}
			}
		}
		
		memset(mark, 0, (p+1)*sizeof(bool));
		for(int i=1; i<=p; ++i)
			dist[i] = INF;
		heap.clear();
		
		dist[1] = 0;
		heap.insert(make_pair(0, 1));
		
		while(!heap.empty())
		{
			v = (heap.begin())->second;
			heap.erase(heap.begin());
			mark[v] = 1;
			
			cost += dist[v];
			
			for(it=grev[v].begin(); it!=grev[v].end(); ++it)
			{
				u = it->first;
				w = it->second;
				if(!mark[u] && (dist[u] > dist[v] + w))
				{
					heap.erase(make_pair(dist[u], u));
					dist[u] = dist[v] + w;
					heap.insert(make_pair(dist[u], u));
				}
			}
		}
		
		printf("%d\n", cost);
	}
	
	return 0;
}