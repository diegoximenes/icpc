#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

#define INF 1000000000

int main()
{
	int n, k, t[5], v, u, mark[100*5+1], dist[100*5+1], w;
	char c;
	vector< vector< pair<int, int> > > g;
	vector< pair<int, int> > ve;
	ve.clear();
	
	g.resize(100*5+1);
	
	while(scanf("%d %d", &k, &n) != EOF)
	{
		g.assign(100*5+1, ve);
		
		for(int i=0; i<k; ++i)
		{
			scanf("%d", &t[i]);
			
			g[500].push_back(make_pair(100*i, 0));
		}
		
		for(int i=0; i<k; ++i)
		{
			scanf("%d", &v);
			for(int j=0; j<k; ++j)
				if(j != i)
				{
					g[v+100*j].push_back(make_pair(v+100*i, 60)); 
					g[v+100*i].push_back(make_pair(v+100*j, 60));
				}

			while(1)
			{
				if(scanf("%c", &c) == EOF)
					break;
				if(c == '\n')
					break;
				
				scanf("%d", &u);
				
				g[u+100*i].push_back(make_pair(v+100*i,(u-v)*t[i])); 
				g[v+100*i].push_back(make_pair(u+100*i, (u-v)*t[i])); 
				
				for(int j=0; j<k; ++j)
					if(j != i)
					{
						g[u+100*j].push_back(make_pair(u+100*i, 60)); 
						g[u+100*i].push_back(make_pair(u+100*j, 60)); 
					}
					
				v = u;
			}
		}
		
		memset(mark, 0, sizeof(mark));
		for(int i=0; i<100*5; ++i)
			dist[i] = INF;
		set< pair<int, int> > heap;
		
		dist[500] = 0;
		heap.clear();
		heap.insert(make_pair(0, 500));
		
		while(1)
		{
			if(heap.empty())
				break;
			
			v = (heap.begin())->second;
			mark[v] = 1;
			
			for(int i=0; i<5; ++i)
				if(v == n+(100*i))
					break;
			
			heap.erase(heap.begin());
			
			for(int i=0; i<g[v].size(); ++i)
			{
				u = g[v][i].first;
				w = g[v][i].second;
				if(!mark[u] && (dist[u] > dist[v] + w))
				{
					heap.erase(make_pair(dist[u], u));
					dist[u] = dist[v] + w;
					heap.insert(make_pair(dist[u], u));
				}
			}
		}
		
		/*for(int i=0; i<100*5+1; ++i)
		{
			printf("(%d):%d ->", i, dist[i]);
			for(int j=0; j<g[i].size(); ++j)
				printf("%d(%d), ", g[i][j].first, g[i][j].second);
			puts("");
		}*/
		
		int distmin = INF;
		for(int i=0; i<5; ++i)
			distmin = min(distmin, dist[n+(100*i)]);
		
		if(distmin == INF)
			puts("IMPOSSIBLE");
		else
			printf("%d\n", distmin);
	}
	
	return 0;
}