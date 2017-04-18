#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 50005
#define MAX2 105
#define INF (int) 1e9

int coin[MAX2], m, dp[MAX];

int dfs(int v)
{
	if(solved) return INF;
	if(dp[v] != -1) return dp[v];

	int count = INF;
	if(v == 0)
		return 0;
	for(int i=0; i<m; ++i)
	{
		int u = v - coin[i];
		if(u >= 0)
			count = min(count, 1 + dfs(u));
	}

	return dp[v] = count;
}

bool cmp(int a, int b)
{
	if(a > b) return 1;
	return 0;
}

int main()
{
	int v;

	while(scanf("%d %d", &v, &m) && v)
	{
		memset(dp, -1, sizeof(dp));
		for(int i=0; i<m; ++i)
			scanf("%d", &coin[i]);
		sort(coin, coin + m, cmp);

		int count = dfs(v);
		if(count == INF) puts("Impossivel");
		else printf("%d\n", count);
	}

	return 0;
}
