#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 105

int dist[MAX][MAX];
double cnt[MAX][MAX];

int main()
{
	int n, m;
	memset(dist, INF, sizeof(dist));
	memset(cnt, 0, sizeof(cnt));
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
	{
		int u, v; scanf("%d %d", &u, &v);
		dist[u][v] = dist[v][u] = cnt[u][v] = cnt[v][u] = 1;
	}
	for(int i=0; i<=n; ++i) dist[i][i] = 0;

	for(int k=1; k<=n; ++k)
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=n; ++j)
			{
				if(dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					cnt[i][j] = cnt[i][k] * cnt[k][j];
				}
				else if(dist[i][j] == dist[i][k] + dist[k][j])
					cnt[i][j] += cnt[i][k] * cnt[k][j];
			}
	
	int s = 1, t = n;
	double sol = 1.0;
	for(int u=1; u<=n; ++u)
		if(dist[s][t] == dist[s][u] + dist[u][t])
			sol = max(sol, 2.0*cnt[s][u]*cnt[u][t]/cnt[s][t]);
	
	printf("%.7lf\n", sol);

	return 0;
}
