#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 110
#define INF (int) 1e9

int dist[2][MAX][MAX];

int newdist(int shortest, int *temp, int size)
{
	for(int i=0; i<size; ++i)
		if(temp[i] == shortest)
			temp[i] = INF;
	return *min_element(temp, temp + size);
}

void floydWarshall1(int n)
{
	for(int k=0; k<n; ++k)
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				dist[0][i][j] = min(dist[0][i][j], dist[0][i][k] + dist[0][k][j]);
}

void floydWarshall2(int n)
{
	for(int k=0; k<n; ++k)
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
			{
				int temp[4] = {dist[1][i][j], dist[0][i][k] + dist[1][k][j], dist[1][i][k] + dist[0][k][j], dist[0][i][k] + dist[0][k][j]};
				dist[1][i][j] = newdist(dist[0][i][j], temp, 4);
			}
}

int main()
{
	int n, m, q, u, v, w;

	for(int tc=1; scanf("%d %d", &n, &m) == 2; ++tc)
	{
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
			{
				if(i == j) dist[0][i][j] = dist[1][i][j] = 0;
				else dist[0][i][j] = dist[1][i][j] = INF;
			}

		while(m--)
		{
			scanf("%d %d %d", &u, &v, &w);
			dist[0][u][v] = dist[0][v][u] = dist[1][u][v] = dist[1][v][u] = w;
		}

		floydWarshall1(n);
		floydWarshall2(n);
		printf("Set #%d\n", tc);
		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d", &u, &v);
			if(dist[1][u][v] == INF) puts("?");
			else printf("%d\n", dist[1][u][v]);
		}
	}

	return 0;
}

