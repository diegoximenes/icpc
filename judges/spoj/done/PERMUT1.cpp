#include<cstdio>
#include<cstring>
using namespace std;

#define MAXK 100
#define MAXMASK (1 << 12)

int t, n, k, dp[MAXMASK][MAXK];

int opt(int mask, int actualK)
{
	if(actualK > k) return 0;
	if(__builtin_popcount(mask) == n)
	{
		if(actualK != k) return 0;
		return 1;
	}
	int &state = dp[mask][actualK];
	if(state != -1) return state;
	
	int cntLower = 0, sol = 0;
	for(int i=0; i<n; ++i)
		if(!(mask & (1 << i)))
		{
			sol += opt(mask | (1 << i), actualK + cntLower);
			++cntLower;
		}

	return state = sol;
}

int main()
{
	int t;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &k);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", opt(0, 0));
	}

	return 0;
}
