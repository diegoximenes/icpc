#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 255
#define INF (int) 1e9

int n, p[MAX], dp[MAX][MAX];

int opt(int i, int j)
{
	if(j == i-1) return 0;
	if(i > j) return INF;
	if(dp[i][j] != -1) return dp[i][j];

	int mincost = INF;
	for(int r=i; r<=j; ++r) mincost = min(mincost, opt(i, r-1) + opt(r+1, j) + (p[j]-p[i-1]) - (p[r]-p[r-1]));

	return dp[i][j] = mincost;
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		p[0] = 0;
		for(int i=1; i<=n; ++i) scanf("%d", &p[i]), p[i] += p[i-1];
		memset(dp, -1, sizeof(dp));
		printf("%d\n", opt(1, n));
	}

	return 0;
}
