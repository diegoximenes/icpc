#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX 50005

vector< pair<int, int> > g[MAX];
ll cnt[MAX];
bool mark[MAX];
int n;
double sol;

ll dfs(int u)
{
	mark[u] = 1;
	cnt[u] = 1;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i].first;
		ll w = g[u][i].second;
		if(!mark[v])
		{
			cnt[u] += dfs(v);
			sol += (double)((cnt[v] * ((ll)n - cnt[v])) * w)/(double)((ll)n * (ll)(n-1));
		}
	}
	
	return cnt[u];
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n-1; ++i)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		g[u].pb(mp(v, w));
		g[v].pb(mp(u, w));
	}
	
	sol = 0;
	memset(mark, 0, sizeof(mark));
	dfs(0);
	printf("%.5lf\n", 2.0*sol);

	return 0;
}
