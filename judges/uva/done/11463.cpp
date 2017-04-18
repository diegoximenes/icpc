#include<cstdio>
#include<vector>
#include<climits>
#include<list>
#include<algorithm>
using namespace std;

#define MAX 110

int main()
{
	int t, n, m, v1, v2;
	vector< list<int> > g;
	list<int> l;
	list<int>::iterator it;
	int dist[MAX][MAX];
	
	g.resize(MAX);
	l.clear();
	
	scanf("%d", &t);
	
	for(int p=1; p<=t; ++p)
	{
		scanf("%d %d", &n, &m);
		
		g.assign(n, l);
		
		while(m--)
		{
			scanf("%d %d", &v1, &v2);
			
			g[v1].push_front(v2);
			g[v2].push_front(v1);
		}
		
		scanf("%d %d", &v1, &v2);
		
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
			{
				if(i == j)
					dist[i][j] = 0;
				else
					dist[i][j] = INT_MAX;
			}
			
		for(int v=0; v<n; ++v)			
			for(it=g[v].begin(); it!=g[v].end(); ++it)
				dist[v][*it] = 1;
		
		for(int k=0; k<n; ++k)
			for(int i=0; i<n; ++i)
				for(int j=0; j<n; ++j)
					if((dist[i][k] != INT_MAX) && (dist[k][j] != INT_MAX))
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		
		int maxi = 0;
		for(int i=0; i<n; ++i)
			if((dist[v1][i] != INT_MAX) && (dist[i][v2] != INT_MAX))
				maxi = max(dist[v1][i]+dist[i][v2], maxi);
			
			
		printf("Case %d: %d\n", p, maxi);
	}
	
	return 0;
}
