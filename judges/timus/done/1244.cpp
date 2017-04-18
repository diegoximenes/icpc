#include<bits/stdc++.h>
using namespace std;

#define NMAX 105
#define VMAX 1005

int dp[NMAX][NMAX * VMAX], w[NMAX], n;
bool mark[NMAX], moreThanOneSolution;

int opt(int i, int v)
{
	if(v < 0) return 0;
	if(i == n)
	{
		if(v == 0) return 1;
		return 0;
	}
	int &state = dp[i][v];
	if(state != -1) return state;

	return state = max(opt(i+1, v), opt(i+1, v - w[i]));
}

void build(int i, int v)
{
	if(i == n) return;

	if(opt(i+1, v) == 1 && opt(i+1, v) == opt(i+1, v - w[i])) moreThanOneSolution = 1;
	else if(opt(i+1, v)) mark[i] = 0, build(i+1, v);
	else mark[i] = 1, build(i+1, v - w[i]);
}

int main()
{
	int v;

	scanf("%d %d", &v, &n);
	for(int i=0; i<n; ++i) scanf("%d", &w[i]);
	
	memset(dp, -1, sizeof(dp));
	int sol = opt(0, v);

	if(!sol) puts("0");
	else
	{
		moreThanOneSolution = 0;
		build(0, v);
		if(moreThanOneSolution) puts("-1");
		else
		{
			bool first = 1;
			for(int i=0; i<n; ++i)
				if(!mark[i])
				{
					if(!first) putchar(' ');
					printf("%d", i+1);
					first = 0;
				}
			puts("");
		}
	}

	return 0;
}
