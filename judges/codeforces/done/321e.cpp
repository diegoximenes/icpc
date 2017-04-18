#include<bits/stdc++.h>
using namespace std;

#define NMAX 4005
#define KMAX 805
#define INF 0x3f3f3f3f

int u[NMAX][NMAX];
int dp[KMAX][NMAX], bestk[KMAX][NMAX];
int cost[NMAX][NMAX], sumRow[NMAX][NMAX];

void compute(int i, int left, int right, int bestkLeft, int bestkRight)
{
	if(right < left) return;
	int mid = (left + right)/2;
		
	dp[i][mid] = INF;
	for(int k=bestkLeft; k<=min(bestkRight, mid); ++k)
		if(cost[k][mid] + dp[i-1][k-1] < dp[i][mid])
		{
			dp[i][mid] = cost[k][mid] + dp[i-1][k-1];
			bestk[i][mid] = k;
		}
	
	if(left != right)
	{
		compute(i, left, mid-1, bestkLeft, bestk[i][mid]);
		compute(i, mid+1, right, bestk[i][mid], bestkRight);
	}
}

int main()
{
	ios::sync_with_stdio(false);

	int n, k;

	cin >> n >> k;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			cin >> u[i][j];
	
	for(int i=1; i<=n; ++i)
	{
		sumRow[i][i] = 0;
		for(int j=i+1; j<=n; ++j) sumRow[i][j] = u[i][j] + sumRow[i][j-1];
	}
	cost[n][n] = u[n][n];
	for(int i=n-1; i>=1; --i)
		for(int j=i+1; j<=n; ++j)
			cost[i][j] = sumRow[i][j] + cost[i+1][j];

	dp[0][0] = 0;
	for(int i=1; i<=n; ++i) dp[0][i] = INF;
	for(int i=1; i<=k; ++i) compute(i, 1, n, 1, n);
	
	cout << dp[k][n] << endl;

	return 0;
}
