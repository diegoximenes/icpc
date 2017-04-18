#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define MOD 1000000007LL
#define MAX 100005

vector<int> g[MAX];
ll dp[MAX][2];
int color[MAX];

void dfs(int u, int dad)
{
	dp[u][0] = dp[u][1] = 0;
	dp[u][color[u]] = 1;

	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(v == dad) continue;

		ll aux[2]; aux[0] = dp[u][0]; aux[1] = dp[u][1];
		dp[u][0] = dp[u][1] = 0;
			
		dfs(v, u);

		dp[u][0] += dp[v][0] * aux[0];
		dp[u][1] += dp[v][1] * aux[0];
		dp[u][1] += dp[v][0] * aux[1];
		
		dp[u][0] += dp[v][1] * aux[0];
		dp[u][1] += dp[v][1] * aux[1];

		dp[u][0] %= MOD;
		dp[u][1] %= MOD;
	}
}

int main()
{
	int n;

	cin >> n;
	for(int i=1; i<n; ++i)
	{
		int u; cin >> u;
		g[i].pb(u);
		g[u].pb(i);
	}
	for(int i=0; i<n; ++i) cin >> color[i];
	
	dfs(0, -1);	
	cout << dp[0][1] << endl; 

	return 0;
}
