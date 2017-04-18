#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define MAX 100005
#define INF 0x3f3f3f3f3f3f3f3fLL

int n, next[MAX];
ll a[MAX], dp[MAX][2];

ll opt(int i, int choosed)
{
	if(i == n) return 0;
	ll &state = dp[i][choosed];
	if(state != -1) return state;
	
	state = -INF;	
	if(i+1 < n && a[i] == a[i+1]) state = max(state, a[i] + opt(i+1, 1));
	else state = max(state, a[i] + opt(next[i], 0));
	
	if(choosed) state = max(state, opt(next[i], 0));
	else state = max(state, opt(i+1, 0));
	
	return state;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i) cin >> a[i];
	sort(a, a+n);
	
	set< pair<ll, int> > tree;
	set< pair<ll, int> >::iterator it;

	for(int i=n-1; i>=0; --i)
	{
		it = tree.upper_bound(mp(a[i]+1, INF));
		if(it != tree.end()) next[i] = it->second;
		else next[i] = n;
		tree.insert(mp(a[i], i));
	}
	
	memset(dp, -1, sizeof(dp));
	cout << opt(0, 0) << endl;

	return 0;
}
