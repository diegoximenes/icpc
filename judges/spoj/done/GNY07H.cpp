#include<bits/stdc++.h>
using namespace std;

#define MAX 1005

int dp[MAX], dpG[MAX], dpH[MAX];

int opt(int n);
int optG(int n);
int optH(int n);

int opt(int n)
{
	if(n == 0) return 1;
	if(n < 0) return 0;
	int &state = dp[n];
	if(state != -1) return state;

	return state = opt(n-1) + 4*opt(n-2) + 2*optG(n) + optH(n);
}

int optG(int n)
{
	if(n <= 2) return 0;
	int &state = dpG[n];
	if(state != -1) return state;
	
	return state = opt(n-4) + opt(n-3) + optG(n-2);
}

int optH(int n)
{
	if(n <= 3) return 0;
	int &state = dpH[n];
	if(state != -1) return state;
	
	return state = opt(n-4) + optH(n-2);
}

int main()
{
	int t, n;

	memset(dp, -1, sizeof(dp));
	memset(dpG, -1, sizeof(dpG));
	memset(dpH, -1, sizeof(dpH));
	
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf("%d", &n);
		printf("%d %d\n", tc, opt(n));
	}
	
	return 0;
}
