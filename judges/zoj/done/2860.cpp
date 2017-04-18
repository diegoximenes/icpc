#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 1010
#define INF (int) 1e9

int dp[MAX][MAX], n, m, v[MAX], bestk[MAX][MAX];

int opt(int i, int j)
{
	if(j == i+1) return 0;
	if(j <= i) return INF;
	if(dp[i][j] != -1) return dp[i][j];
	
	opt(i, j-1); opt(i+1, j);
	int l = (j - i == 2) ? j-1 : bestk[i][j-1], r = (j - i == 2) ? j - 1: bestk[i+1][j], mincost = INF;
	for(int k=l; k<=r; ++k) 
	{
		int cost = opt(i, k) + opt(k, j) + v[j] - v[i];
		if(cost < mincost) bestk[i][j] = k, mincost = cost;
	}
	
	return dp[i][j] = mincost;
}

int main()
{
	while(scanf("%d %d", &n, &m) == 2)
	{
		for(int i=1; i<=m; ++i) scanf("%d", &v[i]);
		v[0] = 0; v[m+1] = n; m += 2;
		memset(dp, -1, sizeof(dp));
		printf("%d\n", opt(0, m-1));
	}

	return 0;
}
