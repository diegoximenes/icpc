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
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MAX 105

int n;
char g[MAX][MAX];
const int neigh[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline bool can(int i, int j)
{
	return (i>=0 && i<n && j>=0 && j<n);
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf(" %s ", g[i]);
	
	bool sol = 1;
	for(int i=0; sol && i<n; ++i)
		for(int j=0; sol && j<n; ++j)
		{
			int cnt = 0;
			for(int k=0; k<4; ++k)
			{
				int i2 = i + neigh[k][0], j2 = j + neigh[k][1];
				if(can(i2, j2) && g[i2][j2] == 'o') ++cnt;
			}

			if(cnt%2) sol = 0;
		}
	
	puts(sol ? "YES" : "NO");

	return 0;
}
