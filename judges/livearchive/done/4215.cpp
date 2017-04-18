#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
#define MAX 101

int main()
{
	int n;
	
	ll dp[MAX];
	dp[0] = 0;
	for(ll i=1; i<MAX; ++i) dp[i] = dp[i-1] + i*i;

	while(scanf("%d", &n) && n) printf("%lld\n", dp[n]);

	return 0;
}

