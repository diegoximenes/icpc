#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 105
#define MAXK 105

int t, tc, n, k, dp[MAXN][MAXK][2];

int opt(int i, int actualK, int last)
{
	if(actualK > k) return 0;
	if(i == n)
	{
		if(actualK == k) return 1;
		return 0;
	}
	int &state = dp[i][actualK][last];
	if(state != -1) return state;
	
	int sol1;
	if(last == 1) sol1 = opt(i+1, actualK + 1, 1);
	else sol1 = opt(i+1, actualK, 1);
	int sol2 = opt(i+1, actualK, 0); 

	return state = sol1 + sol2;
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &tc, &n, &k);	

		memset(dp, -1, sizeof(dp));
		printf("%d %d\n", tc, opt(0, 0, 0));
	}

	return 0;
}
