#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 1e9
#define MAX 1000000

int n, k, l, m, dp[MAX][2];

int main()
{
	scanf("%d %d %d", &k, &l, &m);
	
	dp[0][0] = -INF; dp[0][1] = INF;
	for(int i=1; i<=MAX; ++i)
	{
		dp[i][0] = -INF; dp[i][1] = INF;
		if(i - 1 >= 0)
		{
			dp[i][0] = max(dp[i][0], dp[i-1][1]);
			dp[i][1] = min(dp[i][1], dp[i-1][0]);
		}
		if(i - l >= 0)
		{
			dp[i][0] = max(dp[i][0], dp[i-l][1]);
			dp[i][1] = min(dp[i][1], dp[i-l][0]);
		}
		if(i - k >= 0)
		{
			dp[i][0] = max(dp[i][0], dp[i-k][1]);
			dp[i][1] = min(dp[i][1], dp[i-k][0]);
		}
	}

	while(m--)
	{
		scanf("%d", &n);

		if(dp[n][0] > 0) putchar('A');
		else putchar('B');
	}
	puts("");

	return 0;
}
