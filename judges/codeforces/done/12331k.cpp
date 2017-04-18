#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 250010

int main()
{
	int n, maxdp, dp[MAX], v[MAX];

	while(scanf("%d", &n) && n)
	{
		for(int i=0; i<n; ++i) scanf("%d", &v[i]);
		maxdp = dp[0] = v[0];
		for(int i=1; i<n; ++i)
		{
			dp[i] = max(dp[i-1] + v[i], v[i]);
			maxdp = max(maxdp, dp[i]);
		}
		printf("%d\n", maxdp);
	}

	return 0;
}
