#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
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
#define INF 1e9
#define EPS 1e-9
#define MAX 10010 

int main()
{
	int n, dp[MAX];
	
	for(int x=0; x<=10000; ++x)
	{
		int a = (int)sqrt(x) + 1;
		bool solved = 0;
		for(int i=-a; !solved && i<=a; ++i)
			for(int j=-a; !solved && j<=a; ++j)
				if(i*i + j*j == x)
				{
					dp[x] = 1;
					solved = 1;
				}
		if(!solved) dp[x] = 0;
	}

	while(scanf("%d", &n) == 1)
	{
		if(n < 0) puts("NO");
		else if(dp[n]) puts("YES");
		else puts("NO");
	}

	return 0;
}
