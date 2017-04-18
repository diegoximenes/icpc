#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3fLL
#define MAX (2*205)

int n;
ll dp[MAX][MAX], cum[MAX], size[MAX];
double f;

ll opt(int i, int j)
{
	if(i == j) return 0;
	ll &state = dp[i][j];
	if(state != -1) return state;

	ll sol = INF;
	for(int k=i; k<j; ++k) 
	{
		ll c = max(cum[k] - cum[i-1], cum[j] - cum[k]);
		sol = min(sol, opt(i, k) + opt(k+1, j) + c);
	}

	return state = sol;
}

int main()
{
	while(scanf("%d %lf", &n, &f) && n)
	{
		for(int i=1; i<=n; ++i)
		{
			scanf("%lld", &size[i]);
			size[i+n] = size[i];
		}

		if(n == 1)
		{
			puts("0.00");
			continue;
		}

		cum[0] = 0;
		for(int i=1; i<=2*n; ++i) cum[i] = cum[i-1] + size[i];
		
		double sol = 1.0/0.0;
		memset(dp, -1, sizeof(dp));
		for(int i=1; i<=n; ++i)
			for(int j=1; j<n; ++j)
			{
				ll c = max(cum[i+j-1] - cum[i-1], cum[i+j + (n-j) - 1] - cum[i+j-1]);
				sol = min(sol, f * (opt(i, i+j-1) + opt(i+j, i+j + (n-j) - 1) + c));
			}

		printf("%.2lf\n", sol);

	}	
	return 0;
}
