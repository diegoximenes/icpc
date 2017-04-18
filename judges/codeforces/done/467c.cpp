#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 0x3f3f3f3f3f3f3f3fLL
#define MAX 5005

int n, m, k;
ll dp[MAX][MAX], p[MAX], cum[MAX];

ll opt(int i, int cntPairs)
{
	if(cntPairs > k) return -INF;
	if(i > n)
	{
		if(cntPairs == k) return 0;
		return -INF;
	}
	ll &state = dp[i][cntPairs];
	if(state != -1) return state;
	
	state = opt(i+1, cntPairs);
	if(i+m-1 <= n) state = max(state, cum[i+m-1] - cum[i-1] + opt(i+m, cntPairs+1));
	
	return state;
}

int main()
{
	scanf("%d %d %d", &n, &m ,&k);
	cum[0] = 0;
	for(int i=1; i<=n; ++i)
	{
		cin >> p[i];
		cum[i] = cum[i-1] + p[i];
	}

	memset(dp, -1, sizeof(dp));
	cout << opt(1, 0) << endl;

	return 0;
}
