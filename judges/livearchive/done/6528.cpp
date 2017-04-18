#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define pb push_back
#define MAX 1005

int n, m, dp[MAX][MAX];
vector<int> g[MAX];

int opt(int u, int v)
{
	if(u == v)
	{
		if(u != 0) return dp[u][v] = 0;
		else return dp[u][v] = 1;
	}
	if(u > v) swap(u, v);
	if(dp[u][v] != -1) return dp[u][v];

	int sol = 0;
	for(int i=0; !sol && i<(int)g[v].size(); ++i)
		sol = sol || opt(u, g[v][i]);

	return dp[u][v] = sol;
}

int main()
{
	while(scanf("%d %d", &n, &m) == 2)
	{
		for(int i=0; i<n; ++i) g[i].clear();
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				dp[i][j] = -1;

		while(m--)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			g[v].pb(u);
		}
		
		int cnt = 0;
		for(int i=0; i<n; ++i)
			for(int j=i+1; j<n; ++j)
				cnt += opt(i, j);
		printf("%d\n", cnt);
	}

	return 0;
}
