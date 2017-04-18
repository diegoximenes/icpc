#include<cstdio>
#include<cstring>
using namespace std;

#define MAXS 160
#define MAXK 15
#define MAXN 25

int n, k, s, dp[MAXK][MAXN][MAXS];

int opt(int i, int next, int sum)
{
	if(sum > s) return 0;
	if(i == k)
	{
		if(sum == s) return 1;
		return 0;
	}
	int &state = dp[i][next][sum];
	if(state != -1) return state;

	int sol = 0;
	for(int j=next; j<=n; ++j) sol += opt(i+1, j+1, sum+j);

//	printf("i= %d, last= %d, sum= %d, sol= %d\n", i,last, sum, sol);

	return state = sol;
}


int main()
{
	while(scanf("%d %d %d", &n, &k, &s) && n)
	{
		memset(dp, -1, sizeof(dp));
		printf("%d\n", opt(0 , 1, 0));
	}

	return 0;
}
