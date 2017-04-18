#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF (int) 1e9

const int n = 11;
int t, dp[(1 << 11)], g[12][12];

int opt(int mask, int i)
{
	if(i == n) return 0;
	int &state = dp[mask];
	if(state != -1) return state;
	
	int sol = -INF;
	for(int j=0; j<n; ++j)
		if(!((1 << j) & mask) && g[i][j] != 0)
			sol = max(sol, opt(mask | (1 << j), i + 1) + g[i][j]);

	return state = sol;
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				scanf("%d", &g[i][j]);
		
		memset(dp, -1, sizeof(dp));
		printf("%d\n", opt(0, 0));
	}

	return 0;
}
