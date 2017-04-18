#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 105
#define INF (int) 1e9

int g[MAX][MAX], dp[MAX][MAX], n, m;

int opt(int i, int j)
{
	if(i == n) return 0;
	if(j < 0 || j == m) return INF;
	if(dp[i][j] != -1) return dp[i][j];

	return dp[i][j] = g[i][j] + min(opt(i+1, j), min(opt(i+1, j-1), opt(i+1, j+1)));
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			scanf("%d", &g[i][j]);
	
	int sol = INF;
	for(int i=0; i<m; ++i)
		sol = min(sol, opt(0, i));
	printf("%d\n", sol);

	return 0;
}
