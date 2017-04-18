#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 300005

vector< pair<int, int> > edgeByWeight[MAX];
int n, m, dp[MAX], dpAux[MAX], maxWeight;
bool changed[MAX];

int main()
{
	maxWeight = -1;
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edgeByWeight[w].pb(mp(u, v));
		maxWeight = max(maxWeight, w);
	}

	memset(dp, 0, sizeof(dp));
	memset(dpAux, 0, sizeof(dpAux));
	memset(changed, 0, sizeof(changed));

	for(int w=1; w<=maxWeight; ++w)
	{
		for(int i=0; i<(int)edgeByWeight[w].size(); ++i)
		{
			int v = edgeByWeight[w][i].second;
			dpAux[v] = 0;
		}
		for(int i=0; i<(int)edgeByWeight[w].size(); ++i)
		{
			int u = edgeByWeight[w][i].first, v = edgeByWeight[w][i].second;
			dpAux[v] = max(dpAux[v], dp[u] + 1);
		}
		for(int i=0; i<(int)edgeByWeight[w].size(); ++i)
		{
			int v = edgeByWeight[w][i].second;
			dp[v] = max(dp[v], dpAux[v]);
		}
	}

	int sol = 0;
	for(int i=1; i<=n; ++i) sol = max(sol, dp[i]);
	printf("%d\n", sol);

	return 0;
}
