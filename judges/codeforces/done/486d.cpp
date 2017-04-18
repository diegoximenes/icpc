#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define MAX 2005
#define MOD 1000000007

ll cnt[MAX];
int a[MAX], d, n;
vector<int> g[MAX];

int dfs(int u, int dadu, int root)
{
	ll cnt = 1;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(v == dadu) continue;
		if(a[v] == a[root] && v > root) continue;
		if(a[v] >= a[root] && a[v]-a[root] <= d) cnt = (cnt * (dfs(v, u, root) + 1))%MOD;
	}

	return cnt%MOD;
}

int main()
{
	scanf("%d %d", &d, &n);
	for(int i=0; i<n; ++i) scanf("%d", &a[i]);
	for(int i=0; i<n-1; ++i)
	{
		int u, v; scanf("%d %d", &u, &v); 
		--u; --v;
		g[v].pb(u); g[u].pb(v);
	}
	
	int sol = 0;
	for(int u=0; u<n; ++u) sol = (sol + dfs(u, -1, u))%MOD;
	
	printf("%d\n", sol);

	return 0;
}
