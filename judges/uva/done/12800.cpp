#include<bits/stdc++.h>
using namespace std;

#define MAX 205
const double INF = 1.0/0.0;

int n;
double dp[MAX][MAX], x[MAX], y[MAX], dist[MAX][MAX];

double opt(int i, int j)
{
	if(j-i+1 == 4 || i+1 == j) return 0.0;
	if((j-i+1)%2 != 0) return INF;
	double &state = dp[i][j];
	if(state > -1) return state;

	state = INF;
	for(int k=i+1; k<j-1; ++k)
		for(int l=k+1; l<j; ++l)
		{
			//if(k-i+1 < 4 || l-k+1 < 4 || j-l+1 < 4) continue;

			double lsol = opt(i, k) + opt(k, l) + opt(l, j);
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
