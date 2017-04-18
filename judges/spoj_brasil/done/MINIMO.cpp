#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 102
#define INF (int) 1e9
int main()
{
	int n, m, dist[MAX][MAX][MAX], q, u, v, w, t;

	for(int tc=1; scanf("%d %d", &n, &m) == 2; ++tc)
	{
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
			{
				if(i == j) dist[i][i][0] = 0;
				else dist[i][j][0] = INF;
			}
		
		for(int i=0; i<m; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			if(w < dist[u][v][0]) dist[u][v][0] = w;
		}

		for(int k=1; k<=n; ++k)
			for(int i=1; i<=n; ++i)
				for(int j=1; j<=n; ++j)
					dist[i][j][k] = min(dist[i][j][k-1], dist[i][k][k-1] + dist[k][j][k-1]);

		printf("Instancia %d\n", tc);
		scanf("%d", &q);
		for(int i=0; i<q; ++i)
		{
			scanf("%d %d %d", &u, &v, &t);
			if(dist[u][v][t] == INF) puts("-1");
			else printf("%d\n", dist[u][v][t]);
		}
		puts("");
	}

	return 0;
}
