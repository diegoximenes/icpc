#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 1005
#define INF 1e9

int t, n, m, k, dp[MAX][MAX], color[MAX], b[MAX][MAX], c[MAX][MAX], best[MAX];

int opt(int i, int paints)
{
	if(i == n) return 0;
	int &state = dp[i][paints];
	if(state != -1) return state;

	int sol = b[i][color[i]] + opt(i+1, paints);
	if(paints > 0) sol = max(sol, best[i] + opt(i+1, paints-1));

	return state = sol;
}	

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &m, &k);
		for(int i=0; i<n; ++i) scanf("%d", &color[i]), --color[i];
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				scanf("%d", &b[i][j]);
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				scanf("%d", &c[i][j]);

		for(int i=0; i<n; ++i)
		{
			best[i] = -INF;
			for(int j=0; j<m; ++j)
				if(j != color[i])
					best[i] = max(best[i], b[i][j] - c[i][j]);
		}

		for(int i=0; i<n; ++i)
			for(int j=0; j<=k; ++j)
				dp[i][j] = -1;

		printf("%d\n", opt(0, k));
	}

	return 0;
}
