#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define EPS 1e-7
#define MAX 501

ll mod, dp[MAX][MAX];
char line[MAX];
int cntCol[MAX], n, m;

ll opt(int cnt0, int cnt1)
{
	if(cnt0 == 0 && cnt1 == 0) return 1;
	ll &state = dp[cnt0][cnt1];
	if(state != -1) return state;

	state = 0;
	if(cnt0 >= 1 && cnt1 >= 1)
	{
		ll aux = (cnt0 * cnt1) % mod;
		state = (state + aux*opt(cnt0-1, cnt1)) % mod;
	}
	if(cnt0 >= 2)
	{
		ll aux = (cnt0 * (cnt0-1)/2) % mod;
		state = (state + aux*opt(cnt0-2, cnt1+2)) % mod;
	}
	if(cnt1 >= 2)
	{
		ll aux = (cnt1 * (cnt1-1)/2) % mod;
		state = (state + aux*opt(cnt0, cnt1-2)) % mod;
	}

	return state;
}

int main()
{
	cin >> n >> m >> mod;
	memset(cntCol, 0, sizeof(cntCol));
	for(int i=0; i<m; ++i)
	{
		cin >> line;
		for(int j=0; j<n; ++j) cntCol[j] += line[j] - '0';
	}
	
	int cnt0 = 0, cnt1 = 0;
	for(int i=0; i<n; ++i)
	{
		if(cntCol[i] == 0) cnt0++;
		else if(cntCol[i] == 1) cnt1++;
	}
	
	memset(dp, -1, sizeof(dp));
	cout << opt(cnt0, cnt1) << endl;

	return 0;
}
