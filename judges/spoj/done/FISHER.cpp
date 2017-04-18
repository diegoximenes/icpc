#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 1e9
#define MAXT 1005
#define MAXN 55

int dpRisk[MAXT][MAXN], dpTime[MAXT][MAXN], n, T, time[MAXN][MAXN], risk[MAXN][MAXN];

int optRisk(int t, int i)
{
	if(i == n-1) return 0;
	int &state = dpRisk[t][i];
	if(state != -1) return state;
		
	int sol = INF;
	for(int j=0; j<n; ++j)
		if(j != i && t + time[i][j] <= T)
			sol = min(risk[i][j] + optRisk(t + time[i][j], j), sol);
	
	return state = sol;
}

int optTime(int t, int i)
{
	if(i == n-1) return 0;
	int &state = dpTime[t][i];
	if(state != -1) return state;

	int sol = INF;
	for(int j=0; j<n; ++j)
		if(j != i && t + time[i][j] <= T && optRisk(t, i) == risk[i][j] + optRisk(t + time[i][j], j))
			sol = min(sol, time[i][j] + optTime(t + time[i][j], j));

	return state = sol;
}

int main()
{
	while(scanf("%d %d", &n, &T) && n)
	{
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				scanf("%d", &time[i][j]);
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				scanf("%d", &risk[i][j]);

		memset(dpRisk, -1, sizeof(dpRisk));
		memset(dpTime, -1, sizeof(dpTime));
			
		int solt = optTime(0, 0), solr = optRisk(0, 0);
		if(solr >= INF) puts("-1");
		else printf("%d %d\n", solr, solt);
	}

	return 0;
}
