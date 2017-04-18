#include<cstdio>
#include<climits>
#include<cstring>
#include<list>
#include<set>
#include<vector>
using namespace std;

#define MAX 20100

typedef struct
{
	int v, w;
}Vertex;

int main()
{
	int t, n, m, s, d, dist[MAX], vmin, p, v1, v2, w;
	bool marc[MAX];
	vector< list<Vertex> > g;
	list<Vertex> l;
	list<Vertex>::iterator it;
	Vertex v;
	
	l.clear();
	g.resize(MAX);
	
	scanf("%d", &t);
	
	for(p=1; p<=t; ++p)
	{
		scanf("%d %d %d %d", &n, &m, &s, &d);
		
		g.assign(n, l);
		
		while(m--)
		{
			scanf("%d %d %d", &v1, &v2, &w);
			
			v.v = v2;
			v.w = w;
			g[v1].push_front(v);
			
			v.v = v1;
			v.w = w;
			g[v2].push_front(v);
		}
		
		memset(marc, 0, n*sizeof(bool));
		for(int i=0; i<n; ++i)
			dist[i] = INT_MAX;
		
		dist[s] = 0;
		
		set< pair<int, int> > heap;
		heap.clear();
		heap.insert(make_pair(0, s));
		while(1)
		{
			/*vmin = -1;
			wmin = INT_MAX;
			for(int i=0; i<n; ++i)
			{
				if(!marc[i] && (dist[i] < wmin))
				{
					vmin = i;
					wmin = dist[i];
				}
			}*/
			
			if(heap.empty())
				break;
			
			vmin = (heap.begin())->second;
			heap.erase(heap.begin());
			
			if((vmin == -1) || (vmin == d))
				break;
			
			marc[vmin] = 1;
			
			for(it=g[vmin].begin(); it!=g[vmin].end(); ++it)
				if(!marc[it->v] && (dist[vmin] + it->w < dist[it->v]))
				{
					heap.erase(make_pair(dist[it->v], it->v));
					dist[it->v] = dist[vmin] + it->w;
					heap.insert(make_pair(dist[it->v], it->v));
				}
		}
		
		if(dist[d] == INT_MAX)
			printf("Case #%d: unreachable\n", p);
		else
			printf("Case #%d: %d\n", p, dist[d]);
	}

	return 0;
}