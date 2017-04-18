#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define NMAX 150005
#define MMAX 305
#define INF 0x3f3f3f3f3f3f3f3fLL

ll dp[2][NMAX], d, a[MMAX], b[MMAX], t[MMAX];
int n, m;

inline void insertWindow(deque< pair<ll, ll> > &window, ll windowSize, pair<ll, ll> v)
{
	while(!window.empty() && window.back().first <= v.first) window.pop_back();
	window.push_back(v);

	while(window.front().second <= v.second-windowSize) window.pop_front();

}

inline ll getWindowMax(deque< pair<ll, ll> > &window) { return window.front().first; }

int main()
{
	cin >> n >> m >> d;
	for(int i=0; i<m; ++i) cin >> a[i] >> b[i] >> t[i];
	
	for(int j=1; j<=n; ++j) dp[(m-1)%2][j] = b[m-1] - abs(a[m-1] - (ll)j);
	for(int i=m-2; i>=0; --i)
	{
		ll dt = t[i+1] - t[i];
		
		deque< pair<ll, ll> > window;
		ll lower = (ll)1 - dt*d, upper = (ll)1 + dt*d;
		ll windowSize = upper-lower+1LL;
		lower = max(1LL, lower); upper = min((ll)n, upper);
		
		for(int k=lower; k<=(int)upper; ++k) insertWindow(window, windowSize, mp(dp[(i+1)%2][k], k));
		
		int k = upper;
		for(int j=1; j<=n; ++j)
		{
			dp[i%2][j] = b[i] - abs(a[i] - (ll)j) + getWindowMax(window);
			
			++k;
			insertWindow(window, windowSize, mp(dp[(i+1)%2][min(k, n)], k));
		}

	}
	
	ll sol = -INF;
	for(int j=1; j<=n; ++j) sol = max(sol, dp[0][j]);
	cout << sol << endl;

	return 0;
}
