#include<cstdio>
using namespace std;

typedef long long ll;

int main()
{
	int t, n; 
	ll dp[35];
	
	dp[1] = 1;
	for(ll i=2; i<=30; ++i) dp[i] = dp[i-1]*2 + 1;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
		
	return 0;
}
