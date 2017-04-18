#include<cstdio>
#include<cstring>
#include<cfloat>
#include<cmath>
#include<map>
#include<vector>
#include<list>
using namespace std;

#define MAX 110

typedef struct
{
	int v;
	double w;
}Vertex;

typedef struct
{
	double x, y;
}Ponto;

int main()
{
	vector< list<Vertex> > g;
	list<Vertex> l;
	list<Vertex>::iterator it;
	int t, vmin, n;
	double wmin, cost[MAX], total;
	bool marc[MAX];
	Ponto vpt[MAX];
	Vertex v;
	
	l.clear();
	g.resize(MAX);
	
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d", &n);
		
		g.assign(n, l);
		
		for(int i=0; i<n; ++i)
		{
			Ponto pt;
			scanf("%lf %lf", &(pt.x), &(pt.y));
			
			vpt[i] = pt;
		}
		
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				if(i != j)
				{
					double h = hypot(abs(vpt[i].x-vpt[j].x), abs(vpt[i].y-vpt[j].y));
					
					v.v = j;
					v.w = h;
					
					g[i].push_front(v);
					
					v.v = i;
					v.w = h;
					
					g[j].push_front(v);
				}
		
		
		for(int i=0; i<n; ++i)
			cost[i] = DBL_MAX;
		
		cost[0] = 0.0;
		
		memset(marc, 0, (n)*sizeof(bool));
		
		total = 0.0;
		while(1)
		{
			vmin = -1;
			wmin = DBL_MAX;
			for(int i=0; i<n; ++i)
			{
				if(!marc[i] && (cost[i] < wmin))
				{
					wmin = cost[i];
					vmin = i;
				}
			}
			
			if(vmin == -1)
				break;
			
			marc[vmin] = 1;
			total += wmin;
			
			for(it=g[vmin].begin(); it!=g[vmin].end(); ++it)
				if((!marc[it->v]) && (cost[it->v] > it->w))
					cost[it->v] = it->w;
		}
		
		printf("%.2lf\n", total);
		
		if(t)
			puts("");
	}
	
	return 0;
}
