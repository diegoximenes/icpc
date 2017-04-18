#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 1e9
#define MAX 605

int dp[MAX][MAX];
bool mark[MAX][MAX];

/*int opt(int n, int m)
{
	if(mark[n][m]) return 0;
	if(n == 1 && m == 1) return 1;
	int &state = dp[n][m];
	if(state != - 1) return state;

	int sol = INF;
	for(int i=1; i<n; ++i) sol = min(sol, opt(i, m) + opt(n-i, m));
	for(int i=1; i<m; ++i) sol = min(sol, opt(n, i) + opt(n, m-i));

	return state = sol;
}*/

int main()
{
	int t, q, n, m;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &m, &q);

		for(int i=0; i<=n; ++i)
			for(int j=0; j<=m; ++j)
				mark[i][j] = 0;//, dp[i][j] = -1;
		while(q--)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			mark[x][y] = 1;
		}
		
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j)
			{
				if(mark[i][j]) dp[i][j] = 0;
				else if(i == 1 && j == 1) dp[i][j] = 1;
				else
				{
					dp[i][j] = INF;
					for(int k=1; k<i; ++k) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]);
					for(int k=1; k<j; ++k) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k]);
				}
			}
			
		printf("%d\n", dp[n][m]);
	}

	return 0;
}

