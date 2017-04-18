#include<bits/stdc++.h>
using namespace std;

#define MAX 5005
#define MOD 1000000007

int dp[MAX], cum[MAX];

int main()
{
	int a, b, n, k;

	scanf("%d %d %d %d", &n, &a, &b, &k);
	
	cum[0] = 0;
	for(int i=1; i<=n; ++i) dp[i] = 1, cum[i] = (dp[i] + cum[i-1])%MOD;
	dp[b] = 0;

	for(int trips=1; trips<=k; ++trips)
	{
		for(int floor=1; floor<=n; ++floor)
		{
			if(floor == b) continue;

			int l = max(0, floor - abs(floor-b) + 1);
			int r = min(n, floor + abs(floor-b) - 1);		
			
			int s1 = cum[r] - cum[l-1];
			int s2 = cum[floor] - cum[floor-1];
			if(s1 < 0) s1 += MOD;
			if(s2 < 0) s2 += MOD;

			dp[floor] = s1 - s2;
			if(dp[floor] < 0) dp[floor] += MOD;
		}
		
		for(int floor=1; floor<=n; ++floor) cum[floor] = (dp[floor] + cum[floor-1])%MOD;
	}
	
	printf("%d\n", dp[a]);
	
	return 0;
}
