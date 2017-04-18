#include<cstdio>
#include<climits>
#include<vector>
#include<list>
using namespace std;

#define MAX 1100

typedef struct
{
	int n, w;
}Vertex;

bool relaxa(int *dist, int v, int u, int w)
{
	if(dist[v] + w < dist[u])
	{
		dist[u] = dist[v] + w;
		return 1;
	}
	return 0;
}

int main()
{
	int dist[MAX], v1, v2, w, t, n, m;
	bool negcicl;
	vector< list<Vertex> > g;
	list<Vertex> l;
	list<Vertex>::iterator it;
	Vertex v;
	
	g.resize(MAX);
	l.clear();
	
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d %d", &n, &m);
		
		g.assign(n, l);
		
		while(m--)
		{
			scanf("%d %d %d", &v1, &v2, &w);
			v.n = v2;
			v.w = w;
			
			g[v1].push_front(v);
		}
		
		for(int i=0; i<n; ++i)
			dist[i] = INT_MAX;
		
		dist[0] = 0;
		
		for(int i=0; i<n-1; ++i)
			for(int u=0; u<n; ++u)
				for(it=g[u].begin(); it!=g[u].end(); ++it)
					relaxa(dist, u, it->n, it->w);
		
		negcicl = 0;
		for(int u=0; !negcicl && (u<n); ++u)
			for(it=g[u].begin(); it!=g[u].end(); ++it)
				if(relaxa(dist, u, it->n, it->w))
				{
					negcicl = 1;
					break;
				}
		
		if(negcicl)
			puts("possible");
		else
			puts("not possible");
	}
	
	return 0;
}