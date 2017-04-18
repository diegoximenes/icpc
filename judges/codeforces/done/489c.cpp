#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define EPS 1e-7
#define NMAX 105
#define SMAX 905

int dp[NMAX][SMAX];

int opt(int i, int s)
{
	if(s < 0) return 0;
	if(i == -1) return (s == 0);
	int &state = dp[i][s];
	if(state != -1) return state;
	
	for(int j=0; j<=9; ++j)
		if(opt(i-1, s-j))
			return state = 1;
	return state = 0;
}

int main()
{
	int n, s, saux;
	
	scanf("%d %d", &n, &s);
	saux = s;
	memset(dp, -1, sizeof(dp));
	
	if(n == 1 && s == 0)
	{
		puts("0 0");
		return 0;
	}

	bool solved = 0;
	for(int i=n-1; i>=0; --i)
	{
		int lower = 0;
		if(i == n-1) lower = 1;
		for(int j=lower; j<=9; ++j)
			if(opt(i-1, s-j))
			{
				solved = 1;
				printf("%d", j);
				s -= j;
				break;
			}
		if(!solved) break;
	}
	if(!solved) printf("-1");
	putchar(' ');

	s = saux;
	solved = 0;
	for(int i=n-1; i>=0; --i)
	{
		int lower = 0;
		if(i == n-1) lower = 1;
		for(int j=9; j>=lower; --j)
			if(opt(i-1, s-j))
			{
				solved = 1;
				printf("%d", j);
				s -= j;
				break;
			}
		if(!solved) break;
	}
	if(!solved) printf("-1");
	
	puts("");

	return 0;
}
