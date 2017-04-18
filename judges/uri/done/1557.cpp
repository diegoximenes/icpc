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
#define MAX 20

int cntDig(int n)
{
	int cnt = 0;
	while(n != 0)
	{
		cnt++;
		n /= 10;
	}
	return cnt;
}

int main()
{
	int n, g[MAX][MAX];
	
	while(scanf("%d", &n) && n)
	{
		for(int i=0; i<n; ++i)
		{
			g[i][0] = (1 << i);
			for(int j=1; j<n; ++j) g[i][j] = g[i][j-1]*2;
		}
		
		int maxdig = cntDig(g[n-1][n-1]);
	
		for(int i=0; i<n; ++i, puts(""))
			for(int j=0; j<n; ++j)
			{
				int dig = cntDig(g[i][j]);
				for(; dig<maxdig; ++dig) putchar(' ');
				printf("%d", g[i][j]);
				
				if(j != n-1) putchar(' ');
			}

		puts("");
	}

	return 0;
}
