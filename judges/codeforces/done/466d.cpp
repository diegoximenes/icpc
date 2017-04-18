#include<bits/stdc++.h>
using namespace std;

#define MAX 2005
#define MOD 1000000007

typedef long long ll;

int a[MAX], n, h;
ll dp[MAX][MAX];

ll opt(int i, int opened)
{
	if(opened < 0) return 0;
	if(i == n) return (opened <= 1);
	ll &state = dp[i][opened];
	if(state != -1)  return state;
	
	state = 0;
	if(opened + a[i] == h) state = (opt(i+1, opened) + opt(i, opened-1) * (ll)opened)%MOD;
	else if(opened + a[i] == h-1) state = opt(i+1, opened+1)%MOD;
	else if(opened + a[i] == h+1) state = (opt(i+1, opened-1) * (ll)opened)%MOD;

	return state;
}

int main()
{
	scanf("%d %d", &n, &h);
	for(int i=0; i<n; ++i) scanf("%d", &a[i]);

	memset(dp, -1, sizeof(dp));
	cout << opt(0, 0) << endl;

	return 0;
}
