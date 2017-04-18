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
#define MAX 1005

int w[MAX], book[MAX];
bool mark[MAX];

int main()
{
	int n, m;
	
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", &w[i]);
	
	int sol = 0;
	map<int, int> last;
	for(int i=1; i<=m; ++i)
	{
		scanf("%d", &book[i]);
		
		memset(mark, 0, sizeof(mark));
		int l = last[book[i]] + 1;
		if(!l) l = 1;
		for(int j=l; j<i; ++j)
		{
			if(!mark[book[j]]) sol += w[book[j]];
			mark[book[j]] = 1;
		}

		last[book[i]] = i;
	}

	printf("%d\n", sol);

	return 0;
}
