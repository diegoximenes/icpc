#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 100005

int n, m, dp[MAX][2], g[MAX];

inline int id(int i, int j) { return (i*m + j); } 

int opt(int i, int j, int canNextRow)
{
	if(i == n) return 0;
	if(j >= m) return opt(i+1, 0, canNextRow);
	int &state = dp[id(i, j)][canNextRow];
	if(state != -1) return state;
	
	int sol = 0;
	if(j == 0 && !canNextRow) sol = opt(i+1, 0, 1);
	else sol = max(g[id(i, j)] + opt(i, j+2, 0), opt(i, j+1, canNextRow));
	
	return state = sol;
}

int main()
{
	while(scanf("%d %d", &n, &m) && n)
	{
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				scanf("%d", &g[id(i, j)]);

		memset(dp, -1, sizeof(dp));
		printf("%d\n", opt(0, 0, 1));
	}

	return 0;
}
