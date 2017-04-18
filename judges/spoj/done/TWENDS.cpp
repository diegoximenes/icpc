#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 1010

int v[MAX], dp[MAX][MAX];

int solve(int i, int j, int p)
{
	if(i == j)
	{
		if(p == 1)
			return -v[i];
		else
			return v[i];
	}
	if(p == 2)
	{
		int res = 0;
		if(v[i] >= v[j])
			res = v[i] - solve(i+1, j, 1);
		else
			res = v[j] - solve(i, j-1, 1);
		return res;
	}
	
	if(dp[i][j] != -1)
		return dp[i][j];
	return dp[i][j] = max(v[i] - solve(i+1, j, 2), v[j] - solve(i, j-1, 2));
}

int main()
{
	int n;
	for(int t=1; scanf("%d", &n) && n; ++t)
	{
		for(int i=0; i<n; ++i)
			scanf("%d", &v[i]);
		for(int i=0; i<=n; ++i)
			for(int j=0; j<=n; ++j)
				dp[i][j] = -1;
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", t, solve(0, n-1, 1));
	}
	
	return 0;
}