#include<cstdio>
#include<climits>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

#define MAX 200100

typedef struct
{
	int n, w;
}Vertex;

int main()
{
	int n, m, v1, v2, w, cost[MAX], total1, total2, vmin, wmin;
	bool marc[MAX];
	vector< list<Vertex> > g;
	list<Vertex> l;
	list<Vertex>::iterator it;
	Vertex v;
	
	l.clear();
	g.resize(MAX);
	
	while(1)
	{
		scanf("%d %d", &n, &m);
		if(!n && !m)
			break;
		
		g.assign(n, l);
		total1 = 0;
		
		while(m--)
		{
			scanf("%d %d %d", &v1, &v2, &w);
			v.n = v2;
			v.w = w;
			
			g[v1].push_front(v);
			
			v.n = v1;
			v.w = w;
			
			g[v2].push_front(v);
			
			total1 += w;
		}
		
		memset(marc, 0, n*sizeof(bool));
		
		for(int i=0; i<n; ++i)
			cost[i] = INT_MAX;
		
		cost[0] = 0;

		total2 = 0;
		
		while(1)
		{
			wmin = INT_MAX;
			vmin = -1;
			for(int i=0; i<n; ++i)
				if(!marc[i] && (cost[i] < wmin))
				{
					wmin = cost[i];
					vmin = i;
				}
			
			if(vmin == -1)
				break;
			
			//printf("wmin= %d, vmin=%d\n", wmin, vmin);
			
			marc[vmin] = 1;
		
			total2 += wmin;
			
			for(it=g[vmin].begin(); it!=g[vmin].end(); ++it)
			{
				if(!marc[it->n] && (it->w < cost[it->n]))
					cost[it->n] = it->w;
			}
		}
		
		printf("%d\n", total1 - total2);
	}
	 
	return 0;
}