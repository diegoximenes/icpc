#include<bits/stdc++.h>
using namespace std;

#define MAX 55

int n, m, t, dp[MAX][MAX], g[MAX][MAX];
const int neigh[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

inline bool can(int i, int j) { return (i>=0 && i<n && j>=0 && j<m); }

int opt(int i, int j)
{
	int &state = dp[i][j];
	if(state != -1) return state;

	int isLeaf = 1;
	int sol = 0;
	for(int k=0; k<4; ++k)
	{
		int ni = i + neigh[k][0], nj = j + neigh[k][1];
		if(can(ni, nj) && g[ni][nj] < g[i][j])
		{
			sol += opt(ni, nj);
			isLeaf = 0;
		}
	}
	
	return state = sol + isLeaf;
}

int main()
{
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				scanf("%d", &g[i][j]);
		
		memset(dp, -1, sizeof(dp));
		
		int sol = 0;
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
			{
				bool bigger = 1;
				for(int k=0; k<4; ++k)
				{
					int ni = i + neigh[k][0], nj = j + neigh[k][1];
					if(can(ni, nj) && g[ni][nj] > g[i][j]) bigger = 0;
				}

				if(bigger) sol += opt(i, j);
			}

		printf("Case #%d: %d\n", tc, sol);
	}

	return 0;
}
