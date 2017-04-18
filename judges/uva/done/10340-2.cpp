//http://stackoverflow.com/questions/16987670/dynamic-programming-why-knuths-improvement-to-optimal-binary-search-tree-on2

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 255
#define INF (int) 1e9

int n, p[MAX], dp[MAX][MAX], root[MAX][MAX];

int opt(int i, int j)
{
	if(j == i-1) return 0;
	if(i > j) return INF;
	if(dp[i][j] != -1) return dp[i][j];

	opt(i, j-1); opt(i+1, j);
	int lroot = (i == j) ? i :root[i][j-1], rroot = (i == j) ? i : root[i+1][j];
	int mincost = INF;
	for(int r=lroot; r<=rroot; ++r) 
	{
		int cost = opt(i, r-1) + opt(r+1, j) + (p[j]-p[i-1]) - (p[r]-p[r-1]);
		if(cost < mincost)
		{
			mincost = cost;
			root[i][j] = r;
		}
	}

	return dp[i][j] = mincost;
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		p[0] = 0;
		for(int i=1; i<=n; ++i) scanf("%d", &p[i]), p[i] += p[i-1], root[i][i] = i;
		memset(dp, -1, sizeof(dp));
		printf("%d\n", opt(1, n));
	}

	return 0;
}
