#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 100010
#define INF (int) 1e9

int n, tx, ty, g[MAX][3], dp[MAX][3];

const int neigh[3][4][2] = {{{-1, 0}, {-1, 1}, {0, 0}, {0, 0}}, {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}}, {{0, -1}, {-1, -1}, {-1, 0}, {0, 0}}};

inline bool can(int i, int j)
{
	if(i>=0 && i<n && j>=0 && j<3) return 1;
	return 0;
}

int main()
{
	int upper;

	for(int tc=1; scanf("%d", &n) && n; ++tc)
	{
		for(int i=0; i<n; ++i) scanf("%d %d %d", &g[i][0], &g[i][1], &g[i][2]);
		
		dp[0][0] = INF; dp[0][1] = g[0][1]; dp[0][2] = dp[0][1] + g[0][2];
		for(int i=1; i<n; ++i)
			for(int j=0; j<3; ++j)
			{
				dp[i][j] = INF;
				if(j == 0) upper = 2;
				else if(j == 1) upper = 4;
				else upper = 3;
				for(int k=0; k<upper; ++k)
				{
					int ni = i + neigh[j][k][0], nj = j + neigh[j][k][1];
					if(can(ni, nj)) dp[i][j] = min(dp[i][j], g[i][j] + dp[ni][nj]);
				}
			}	

		printf("%d. %d\n", tc, dp[n-1][1]);
	}

	return 0;
}
