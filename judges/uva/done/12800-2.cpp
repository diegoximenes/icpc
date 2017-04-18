#include<bits/stdc++.h>
using namespace std;

#define MAX 205
const double INF = 1.0/0.0;

int n;
double dp[MAX][MAX], x[MAX], y[MAX], dist[MAX][MAX];

double opt(int i, int j)
{
	double &state = dp[i][j];
	state = INF;

	for(int k=i+1; k<j-1; ++k)
		for(int l=k+1; l<j; ++l)
		{
			if((k-i+1)&1 || (l-k+1)&1 || (j-l+1)&1) continue;

			double lsol = 0;
			if(k-i+1 > 4)
			{
				if(dp[i][k] < 0) lsol += opt(i, k);
				else lsol += dp[i][k];
			}
			if(l-k+1 > 4)
			{
				if(dp[k][l] < 0) lsol += opt(k, l);
				else lsol += dp[k][l];
			}
			if(j-l+1 > 4)
			{
				if(dp[l][j] < 0) lsol += opt(l, j);
				else lsol += dp[l][j];
			}
			
			if(i+1 != k) lsol += dist[i][k];
			if(k+1 != l) lsol += dist[k][l];
			if(l+1 != j) lsol += dist[l][j];
			state = min(state, lsol);
		}

	return state;
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		n *= 2;
		for(int i=0; i<n; ++i) scanf("%lf %lf", &x[i], &y[i]);

		for(int i=0; i<n; ++i)
			for(int j=i+1; j<n; ++j)
			{
				dist[i][j] = hypot(x[i]-x[j], y[i]-y[j]);
				dp[i][j] = -1;
			}
		
		printf("%.4lf\n", opt(0, n-1));
	}

	return 0;
}
