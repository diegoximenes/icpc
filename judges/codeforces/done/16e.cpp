#include<bits/stdc++.h>
using namespace std;

#define MAX 18
#define MASKMAX (1 << 18)

int n;
double p[MAX][MAX], dp[MASKMAX];

double opt(int mask)
{
	int cnt = __builtin_popcount(mask);
	if(cnt == n) return 1.0;
	double &state = dp[mask];
	if(state > -1) return state;
	
	state = 0.0;
	for(int i=0; i<n; ++i)
		if(mask & (1 << i))
			for(int j=0; j<n; ++j)
				if(!(mask & (1 << j)))
					state += 2.0 * p[i][j] * opt(mask | (1 << j)) / (double)((cnt+1)*cnt);
	return state;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			scanf("%lf", &p[i][j]);
	
	for(int mask=0, upper=(1<<n)-1; mask<=upper; ++mask) dp[mask] = -1;

	printf("%.6lf", opt(1));
	for(int i=1; i<n; ++i) printf(" %.6lf", opt(1<<i));
	puts("");
	
	return 0;
}
