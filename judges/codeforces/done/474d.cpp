#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 100005
#define MOD 1000000007LL

ll dp[MAX], cumDp[MAX];
int a, b, t, k;

ll opt(int n)
{
	if(n == 0) return 1;
	if(n < 0) return 0;
	ll &state = dp[n];
	if(state != -1) return state;
	
	return state = (opt(n-1) + opt(n-k))%MOD;
}

int main()
{
	scanf("%d %d", &t, &k);

	memset(dp, -1, sizeof(dp));
	cumDp[0] = 0;
	for(int i=1; i<MAX; ++i) cumDp[i] = (cumDp[i-1] + opt(i))%MOD;

	for(int i=0; i<t; ++i)
	{
		scanf("%d %d", &a, &b);
		ll sol = (cumDp[b] - cumDp[a-1])%MOD;
		if(sol < 0) sol += MOD;
		cout << sol << endl;
	}

	return 0;
}
