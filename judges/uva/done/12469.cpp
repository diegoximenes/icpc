#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 1010
#define INF (int)1e9

int dp[MAX][2*MAX][2];

int opt(int n, int maxRemove, int player)
{
	int &state = dp[n][maxRemove][player];
	if(state != -1) return state;
		
	int sol;
	if(player) sol = -INF;
	else sol = INF;

	if(n == 0) return state = sol;
	
	for(int i=min(maxRemove, n); i>=1; --i)
	{
		if(player) 
		{
			sol = max(sol, opt(n-i, 2*i, 0));
			if(sol == INF) return state = sol;
		}
		else
		{ 
			sol = min(sol, opt(n-i, 2*i, 1));
			if(sol == -INF) return state = sol;
		}
	}
	return state = sol;
}

int main()
{
	int n;
	
	memset(dp, -1, sizeof(dp));
	while(scanf("%d", &n) && n)
	{
		if(opt(n, n-1, 1) == INF) puts("Alicia");
		else puts("Roberto");
	}

	return 0;
}
