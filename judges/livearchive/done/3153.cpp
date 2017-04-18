#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f
#define NMAX 21
#define MASKMAX (1 << 20)

int dp[MASKMAX][NMAX], dist[NMAX][NMAX], visitTime[NMAX], n;
vector<int> museums[NMAX];
const int maxTime = 7*60;

int main()
{
	while(scanf("%d", &n) && n)
	{
		for(int i=0; i<n; ++i) scanf("%d", &visitTime[i]);
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				scanf("%d", &dist[i][j]);
		
		for(int i=0; i<=n; ++i) museums[i].clear();
		for(int mask=0, upper=(1<<n); mask<upper; ++mask) museums[__builtin_popcount(mask)].pb(mask);
		
		int sol = 0;
		
		for(int u=0; u<n; ++u) dp[0][u] = 0;
		for(int j=0; j<(int)museums[1].size(); ++j)
		{
			int mask = museums[1][j];
			for(int u=0; u<n; ++u)
				if(mask & (1 << u))
				{
					dp[mask][u] = visitTime[u];
					if(dp[mask][u] <= maxTime) sol = max(sol, 1);
					break;
				}
		}

		for(int cnt=2; cnt<=n; ++cnt)
		{
			int actualCntSol = sol;

			for(int j=0; j<(int)museums[cnt].size(); ++j)
			{
				int mask = museums[cnt][j];
				
				for(int u=0; u<n; ++u)
					if((1 << u) & mask)
					{
						dp[mask][u] = INF;

						for(int v=0; v<n; ++v)
							if(v != u && ((1 << v) & mask))
								dp[mask][u] = min(dp[mask][u], dp[mask & ~((1 << u))][v] + dist[u][v] + visitTime[u]);

						if(dp[mask][u] <= maxTime) sol = max(sol, cnt);
					}
			}

			if(sol == actualCntSol) break;
		}

		printf("%d\n", sol);
	}

	return 0;
}
