#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 1005
#define INF 0x3f3f3f3f3f3f3f3fLL

ll dp[MAX][MAX], cost[MAX][MAX], x[MAX], w[MAX];
int bestk[MAX][MAX];

void compute(int i, int left, int right, int bestkLeft, int bestkRight)
{
	if(left > right) return;

	int mid = (left + right)/2;
	dp[i][mid] = INF;
	for(int k=bestkLeft; k<=min(bestkRight, mid); ++k)
		if(cost[k][mid] + dp[i-1][k-1] < dp[i][mid])
		{
			dp[i][mid] = cost[k][mid] + dp[i-1][k-1];
			bestk[i][mid] = k;
		}

	if(left != right)
	{
		compute(i, left, mid-1, bestkLeft, bestk[i][mid]);
		compute(i, mid+1, right, bestk[i][mid], bestkRight);
	}
}

int main()
{
	int n, k;

	while(scanf("%d %d", &n, &k) == 2)
	{
		for(int i=1; i<=n; ++i) scanf("%lld %lld", &x[i], &w[i]);

		for(int j=1; j<=n; ++j)
		{
			cost[j][j] = 0;
			for(int i=j-1; i>=0; --i) cost[i][j] = w[i]*(x[j]-x[i]) + cost[i+1][j];
		}
		
		dp[0][0] = 0;
		for(int i=1; i<=n; ++i) dp[0][i] = INF;
		for(int i=1; i<=k; ++i) compute(i, 1, n, 1, n);

		printf("%lld\n", dp[k][n]);
	}

	return 0;
}
