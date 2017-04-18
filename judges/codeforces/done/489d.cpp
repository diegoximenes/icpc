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
#define MAX 3005

vector<int> g[MAX];
int cnt[MAX];

int main()
{
	int n, m;
	
	scanf("%d %d", &n, &m);
	while(m--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		g[v].pb(u);
	}
	
	memset(cnt, 0, sizeof(cnt));
	ll sol = 0;
	for(int u=0; u<n; ++u)
	{
		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int dadu = g[u][i];
			for(int j=0; j<(int)g[dadu].size(); ++j)
			{
				int v = g[dadu][j];
				if(v == u) continue;
				cnt[v]++;
			}
		}

		for(int v=0; v<n; ++v)
		{
			//printf("u= %d, v= %d, cnt[v]= %d\n", u, v, cnt[v]);
			sol += cnt[v]*(cnt[v]-1)/2, cnt[v] = 0;
		}
	}
	
	cout << sol << endl;

	return 0;
}
