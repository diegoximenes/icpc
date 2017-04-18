#include<cstdio>
#include<map>
using namespace std;

typedef long long ll;

map<ll, ll> dp;

ll opt(ll n)
{
	if(n == 0) return 0;
	if(dp.find(n) != dp.end()) return dp[n];

	return dp[n] = max(n, opt(n/2) + opt(n/3) + opt(n/4));
}

int main()
{
	ll n;
	while(scanf("%lld", &n) == 1) printf("%lld\n", opt(n));

	return 0;
}
