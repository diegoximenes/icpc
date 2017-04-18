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
#define MAX 30005

int a[MAX];
bool mark[MAX];

int main()
{
	int n, t;
	
	memset(a, 0, sizeof(a));
	scanf("%d %d", &n, &t); t--;
	for(int i=0; i<n-1; ++i) scanf("%d", &a[i]);
	
	memset(mark, 0, sizeof(mark));
	queue<int> q;
	q.push(0); mark[0] = 1;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(u == t)
		{
			puts("YES");
			return 0;
		}

		int v = u + a[u];
		if(!mark[v]) mark[v] = 1, q.push(v);
	}
	
	puts("NO");

	return 0;
}
