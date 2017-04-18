#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 2000000
#define NMAX 21

int t, n, dp[MAX], g[NMAX][NMAX], sum[NMAX];
bool can[NMAX];

void opt(int mask)
{
	if(dp[mask] != -1) return;
	if(__builtin_popcount(mask) == n - 1)
	{
		for(int i=0; i<n; ++i)
			if(!((1 << i) & mask))
			{
				can[i] = 1;
				return;
			}
	}
	else
	{
		int sumaux[NMAX];
		for(int i=0; i<n; ++i)
			if(!((1 << i) & mask) && sum[i] > 0)
			{
				memcpy(sumaux, sum, sizeof(sumaux));
				for(int j=0; j<n; ++j) if(i != j) sum[j] -= g[j][i];
				opt(mask | (1 << i));
				memcpy(sum, sumaux, sizeof(sum));
			}
	}

	dp[mask] = 1;
}

int main()
{
	
	scanf("%d", &t);
	while(t--)
	{
		memset(sum, 0, sizeof(sum));
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				scanf("%d", &g[i][j]), sum[i] += g[i][j];
		
		memset(can, 0, sizeof(can));
		memset(dp, -1, sizeof(dp));
		opt(0);
		
		bool print = 0;
		for(int i=0; i<n; ++i)
			if(can[i])
				print = 1;
		if(!print) puts("0");
		else
		{
			int i;
			for(i=0; i<n; ++i) 
				if(can[i])
				{
					printf("%d", i + 1);
					i++;
					break;
				}
			for(; i<n; ++i) if(can[i]) printf(" %d", i + 1);
			puts("");
		}
	}

	return 0;
}
