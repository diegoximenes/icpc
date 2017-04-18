#include<cstdio>
#include<list>
#include<queue>
using namespace std;

#define MAX 310

typedef struct
{
	int player, match;
	double p;
}Element;

typedef struct
{
	int next, a , b;
	
	list< Element > l;
}Vertex;

int main()
{
	int n, gent[2*MAX], a, b;;
	double p[MAX][MAX], paux[MAX];
	vector < Vertex > g;
	list< Element >::iterator it, it2;
	
	g.resize(2*MAX);
	
	while(scanf("%d", &n) && n)
	{
		Vertex v;
		v.l.clear();
		
		g.assign(2*n, v);
		
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
				scanf("%lf", &p[i][j]);
		
		queue<int> f;
		for(int i=n+1; i<=2*n-1; ++i)
			g[i].next = 0;
		for(int i=n+1; i<=2*n-1; ++i)
		{			
			gent[i] = 0;
			
			scanf("%d %d", &a, &b);
			
			if(a > n)
				++gent[i];
			if(b > n)
				++gent[i];

			g[a].next = i;
			g[b].next = i;
			g[i].a = a;
			g[i].b = b;
			
			if(!gent[i])
				f.push(i);
			
			//printf("i= %d, a= %d, b= %d, gent[i]= %d\n", i, a, b, gent[i]);
		}
		
		while(!f.empty())
		{
			Element e;
			int v = f.front();
			f.pop();
			
			a = g[v].a;
			b = g[v].b;
			
			if(a <= n)
			{
				e.player = a;
				e.match = a;
				e.p = 1.0;
				g[v].l.push_front(e);
			}
			else
			{
				for(it=g[a].l.begin(); it!=g[a].l.end(); ++it)
				{
					e.player = it->player;
					e.match = a;
					e.p = it->p;
					g[v].l.push_front(e);
				}
			}
				
			if(b <= n)
			{
				e.player = b;
				e.match = b;
				e.p = 1.0;
				g[v].l.push_front(e);
			}
			else
			{
				for(it=g[b].l.begin(); it!=g[b].l.end(); ++it)
				{
					e.player = it->player;
					e.match = b;
					e.p = it->p;
					g[v].l.push_front(e);
				}
			}
			
			if(g[v].next != 0)
			{
				--gent[g[v].next];
				if(!gent[g[v].next])
					f.push(g[v].next);
				//printf("v = %d, a= %d, b= %d, g[v].next= %d, gent[g[v].next]=%d\n", v, a, b, g[v].next, gent[g[v].next]);
			}
			//printf("v= %d\n" ,v);
			//calc. prob. of players win this match
			for(it=g[v].l.begin(); it!=g[v].l.end(); ++it)
			{
				//printf("it->player= %d", it->player);
				
				paux[it->player] = 0.0;
				for(it2=g[v].l.begin(); it2!=g[v].l.end(); ++it2)
					if(it->match != it2->match)
						paux[it->player] += p[it->player][it2->player] * (it->p) * (it2->p);
				
					
				if((f.empty()) && (it->player == 1))
				{
					printf("%.6lf\n", paux[1]);
					break;
				}
					
				//printf(", paux[it->player]= %lf\n", paux[it->player]);
			}
			//puts("");
			for(it=g[v].l.begin(); it!=g[v].l.end(); ++it)
				it->p = paux[it->player];
		}
	}
	
	return 0;
}