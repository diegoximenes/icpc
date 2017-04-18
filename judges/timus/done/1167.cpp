#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 505
#define INF 0x3f3f3f3f

int dp[MAX][MAX], sum[MAX];
int n, k, color[MAX];

int opt(int i, int stable)
{
	if(i == n+1)
	{
		if(stable == k+1) return 0;
		return INF;
	}
	int &state = dp[i][stable];
	if(state != -1) return state;
	
	int sol = INF;
	for(int j=i; j<=n; ++j)
	{
		int black = sum[j] - sum[i-1], white = j - i + 1 - black;

		sol = min(sol, black*white + opt(j+1, stable+1));
	}

	return state = sol;
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; ++i) scanf("%d", &color[i]), sum[i] = sum[i-1] + color[i];
	
	memset(dp, -1, sizeof(dp))	;
	printf("%d\n", opt(1, 1));
}
