#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF 1e9
#define MAXN 105
#define MAXB 10005
#define MAXT 6

vector< pair<int, int> > v[MAXT];
int n, b, dp[MAXT][MAXB][MAXN];

int opt(int type, int b, int i)
{
	if(type == MAXT) return INF;
	if(i == (int)v[type].size() || b < 0) return -INF;
	int &state = dp[type][b][i];
	if(state != -1) return state;

	return state = max(opt(type, b, i+1), min(v[type][i].second, opt(type + 1, b - v[type][i].first, 0)));
}

int main()
{
	scanf("%d %d", &n, &b);
	for(int i=0; i<n; ++i)
	{
		int t, p, q;
		scanf("%d %d %d", &t, &p, &q);
		v[t-1].pb(mp(p, q));
	}
	
	memset(dp, -1, sizeof(dp));
	int sol = opt(0, b, 0);
	if(sol < 0) puts("0");
	else printf("%d\n", sol);

	return 0;
}
