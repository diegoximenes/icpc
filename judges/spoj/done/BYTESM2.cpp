#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 105

int dp[MAX][MAX], g[MAX][MAX], h, w;

bool in(int i, int j)
{
	if(i>=0 && i<h && j>=0 && j<w)
		return 1;
	return 0;
}

int solve(int i, int j)
{
	if(dp[i][j] != -1)
		return dp[i][j];
	
	int gij = g[i][j], res = gij;
	for(int k=-1; k<=1; ++k)
	{
		int i2 = i+1, j2 = j+k; 
		if(in(i2, j2))
			res = max(res, gij + solve(i2, j2));
	}

	return dp[i][j] = res;
}

int main()
{
	int t, res;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &h, &w);
		for(int i=0; i<h; ++i)
			for(int j=0; j<w; ++j)
			{
				scanf("%d", &g[i][j]);
				dp[i][j] = -1;
			}
		
		res = -1;
		for(int i=0; i<w; ++i)
			res = max(res, solve(0, i));
		printf("%d\n", res);
	}
	
	return 0;
}