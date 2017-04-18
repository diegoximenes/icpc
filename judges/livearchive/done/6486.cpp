#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
#define MAX 5005
#define MOD (ll)(1e9 + 7)

ll dpCombination[MAX][MAX], dp[MAX][MAX];

ll combination(int n, int k)
{
	if(k > n || n < 0 || k < 0) return 0;
	if(n == k) return 1;
	ll &state = dpCombination[n][k];
	if(state != -1) return state;

	return state = (combination(n-1, k-1) + combination(n-1, k))%MOD;
}

ll opt(int n, int k)
{
	if(k > n || n < 0 || k < 0) return 0;
	if(n == k) return 1;
	ll &state = dp[n][k];
	if(state != -1) return state;

	return state = (opt(n-1, k-1) + ((ll)(n-1) * opt(n-1, k))%MOD)%MOD;
}

int main()
{
	int n, left, right;
	
	memset(dpCombination, -1, sizeof(dpCombination));
	memset(dp, -1, sizeof(dp));

	while(scanf("%d %d %d", &n, &left, &right) && n)
	{
		ll sol = 0;
		for(int i=0; i<n; ++i)
			sol = (sol + ((combination(n-1, i) * opt(i, left - 1)) % MOD * opt(n - i - 1, right - 1)) % MOD) % MOD;
		printf("%lld\n", sol);
	}

	return 0;
}
