#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define BMAX 21
#define GMAX 8
#define MAX (1 << BMAX)
#define INF 0x3f3f3f3f

int stones[MAX][BMAX], dp[MAX][2], cntg[MAX][GMAX], cntg2[BMAX][GMAX], g, b, s;

/*int opt(int mask, int p)
{
	if(__builtin_popcount(mask) == b) return 0;
	int &state = dp[mask][p];
	if(state != -1) return state;
	
	int sol = -INF;
	if(p) sol = INF;
	for(int i=0; i<b; ++i)
		if(!(mask & (1 << i)))
		{
			if(p == 0) sol = max(sol, stones[mask][i] + opt(mask | (1 << i), (stones[mask][i] > 0 ? p : 1 - p)));
			else sol = min(sol, -stones[mask][i] + opt(mask | (1 << i), (stones[mask][i] > 0 ? p : 1 - p)));
		}
	
	return state = sol;
}*/

int main()
{
	while(scanf("%d %d %d", &g, &b, &s) && g)
	{
		memset(cntg2, 0, sizeof(cntg2));

		for(int i=0; i<b; ++i)
		{
			int n, x;
			scanf("%d", &n);
			while(n--) scanf("%d", &x), cntg2[i][x-1]++;
		}
		
		for(int i=0; i<g; ++i) cntg[0][i] = 0;

		for(int i=0; i<b; ++i) 
		{
			stones[0][i] = 0;
			for(int j=0; j<g; ++j) stones[0][i] += cntg2[i][j]/s;
		}
		for(int mask=1, upper=(1 << b); mask<upper; ++mask)
		{
			int lowest;
			for(int j=0; j<b; ++j)
				if(mask & (1 << j))
				{
					lowest = j;
					break;
				}
			int aux = mask - (1 << lowest);
			
			for(int j=0; j<g; ++j) cntg[mask][j] = (cntg2[lowest][j] + cntg[aux][j])%s;

			for(int j=0; j<b; ++j)
				if(!(mask & (1 << j)))
				{
					stones[mask][j] = 0;
					for(int k=0; k<g; ++k) stones[mask][j] += (cntg[mask][k] + cntg2[j][k])/s;
				}
		}
		
		dp[(1 << b) - 1][0] = dp[(1 << b) - 1][1] = 0;
		for(int mask=(1<<b)-2; mask>=0; --mask)
			for(int p=0; p<2; ++p)
			{
				int sol = -INF;
				if(p) sol = INF;
				for(int i=0; i<b; ++i)
					if(!(mask & (1 << i)))
					{
						if(p == 0) sol = max(sol, stones[mask][i] + dp[mask | (1 << i)][stones[mask][i] > 0 ? p : 1 - p]);
						else sol = min(sol, -stones[mask][i] + dp[mask | (1 << i)][stones[mask][i] > 0 ? p : 1 - p]);
					}

				dp[mask][p] = sol;
			}
		
		printf("%d\n", dp[0][0]);
	}
	

	return 0;
}
