#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 1e9
#define MAX 505

int s[MAX][MAX], dp[MAX][MAX], n, m;

int opt(int i, int j)
{
	if(i == n-1 && j == m-1)
	{
		if(s[i][j] > 0) return 0;
		return -s[i][j];
	}
	if(i == n || j == m) return INF;
	int &state =  dp[i][j];
	if(state != -1) return state;
	
	int sol;
	if(s[i][j] <= 0) sol = -s[i][j] + min(opt(i+1, j), opt(i, j+1));
	else
	{
		sol = s[i][j] - min(opt(i+1, j), opt(i, j+1));
		if(sol > 0) sol = 0;
		else sol = -sol;
	}
	
	return state = sol;
}

int main()
{
	int t;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				scanf("%d", &s[i][j]);
		
		memset(dp, -1, sizeof(dp));
		printf("%d\n", 1 + opt(0, 0));
	}

	return 0;
}
