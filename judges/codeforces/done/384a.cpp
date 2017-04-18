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
#define pb push_back
#define mp make_pair
#define INF 1e9
#define MAX 1005

int n;
char g[MAX][MAX];

inline bool can(int i, int j)
{
	if(i>=0 && i<n && j>=0 && j<n) return 1;
	return 0;
}

int main()
{	
	int cnt = 0;

	scanf("%d", &n);
	memset(g, 0, sizeof(g));
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			g[i][j] = '.';

	for(int i=0; i<n; ++i)
		for(int j=0;j<n; ++j)
			if(((can(i, j-1) && g[i][j-1] == '.') || !can(i, j-1)) && ((can(i-1, j) && g[i-1][j] == '.') || !can(i-1, j)))
				g[i][j] = 'C', ++cnt;
	
	printf("%d\n", cnt);
	for(int i=0; i<n; ++i) printf("%s\n", g[i]);

	return 0;
}
