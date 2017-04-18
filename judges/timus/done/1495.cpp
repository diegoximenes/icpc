#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define INF 0x3f
#define DMAX 30
#define NMAX 1000005

char dp[DMAX][NMAX];
int myexp[DMAX], n;
vector<int> out;

char opt(int i, int v)
{
	if(v == 0 && i > 0) return 0;
	if(i == DMAX)
	{
		if(v == 0) return 0;
		return INF;
	}
	char &state = dp[i][v];
	if(state != -1) return state;
	
	return state = 1 + min(opt(i+1, (v + myexp[i])%n), opt(i+1, (v + 2*myexp[i])%n));
}

char opt2(int i, int v)
{
	if(i == -1)
	{
		if(v) return 0;
		return 1;
	}
	char &state = dp[i][v];	
	if(state != -1) return state;
	
	int mod1 = (v - myexp[i])%n;
	if(mod1 < 0) mod1 += n;
	int mod2 = (v - 2*myexp[i])%n;
	if(mod2 < 0) mod2 += n;
	
	return state = (opt2(i-1, mod1) || opt2(i-1, mod2));
}

void build(int i, int v)
{
	if(i == -1) return;

	int mod1 = (v - myexp[i])%n;
	if(mod1 < 0) mod1 += n;
	int mod2 = (v - 2*myexp[i])%n;
	if(mod2 < 0) mod2 += n;
	
	if(opt2(i-1, mod1)) out.pb(1), build(i-1, mod1);
	else out.pb(2), build(i-1, mod2);
}

int main()
{
	scanf("%d", &n);

	myexp[0] = 1;
	for(int i=1; i<DMAX; ++i) myexp[i] = (myexp[i-1] * 10)%n;
	
	memset(dp, -1, sizeof(dp));
	char sol = opt(0, 0);
	if(sol >= INF) puts("Impossible");
	else
	{
		memset(dp, -1, sizeof(dp));
		opt2(sol-1, 0); build(sol-1, 0);
		for(int i=0; i<(int)out.size(); ++i) printf("%d", out[i]);
		puts("");
	}

	return 0;
}
