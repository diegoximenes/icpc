#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 50005
#define INF 0x3f3f3f3f

vector<int> component;
vector<int> lout, out;
vector< pair<int, int> > g[MAX];
int dp[MAX], n, k, a[MAX], dad[MAX];
bool mark[MAX];

int opt(int u, int dadu)
{
	component.pb(u);
	mark[u] = 1;

	int &state = dp[u];
	if(state != -1) return state;
	
	int sol = a[u];
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i].first, w = g[u][i].second;
		if(v == dadu) continue;

		sol = max(sol, a[u] + w + opt(v, u));
	}

	return state = sol;
}

void getFarthest(int u, int dadu)
{
	lout.pb(u);
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i].first, w = g[u][i].second;
		if(v == dadu) continue;

		if(opt(u, dadu) == a[u] + w + opt(v, u))
		{
			getFarthest(v, u);
			return;
		}
	}
}

int main()
{
	int m;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i) scanf("%d", &a[i]);
	while(m--)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		g[u].pb(mp(v, w)); g[v].pb(mp(u, w));
	}
	
	memset(dp, -1, sizeof(dp));
	memset(mark, 0, sizeof(mark));
	
	int sol = -INF;
	for(int i=0; i<n; ++i)
		if(!mark[i])
		{
			for(int j=0; j<(int)component.size(); ++j) dp[component[j]] = -1;

			component.clear();
			opt(i, -1);
			getFarthest(i, -1);
			int u = lout.back();
	
			for(int j=0; j<(int)component.size(); ++j) dp[component[j]] = -1;
			lout.clear();
			int lsol = opt(u, -1);
			getFarthest(u, -1);

			if(lsol > sol) sol = lsol, out = lout;
	}
		
	printf("%d\n%d\n%d", sol, (int)out.size(), out[0]+1);
	for(int i=1; i<(int)out.size(); ++i) printf(" %d", out[i]+1);
	puts("");

	return 0;
}
