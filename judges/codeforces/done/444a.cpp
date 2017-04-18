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
#define INF 1e9
#define EPS 1e-9
#define MAX 105

int main()
{
	int n, m;
	char g[MAX][MAX];
	
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i) scanf(" %s ", g[i]);

	for(int i=0; i<n; ++i, puts(""))
		for(int j=0; j<m; ++j)
		{
			if(g[i][j] == '.')
			{
				if((i+j)%2) g[i][j] = 'W';
				else g[i][j] = 'B';
			}
			putchar(g[i][j]);
		}

	return 0;

}
