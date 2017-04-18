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
#define EPS 1e-7
#define MAX 1005

vector< pair<int, int> > g[MAX];
int dist[MAX][MAX];

int main()
{
	int t, n, m, k;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &m, &k);
		for(int i=0; i<n; ++i) g[i].clear();

		while(m--)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			g[v].pb(mp(u, w));
		}

		int s = 0, t = n-1;
		for(int i=0; i<n; ++i) dist[i][0] = INF;
		dist[s][0] = 0;
		for(int i=1; i<=k-1; ++i)
			for(int v=0; v<n; ++v)
			{
				dist[v][i] = dist[v][i-1];
				for(int j=0; j<(int)g[v].size(); ++j)
					dist[v][i] = min(dist[v][i], dist[g[v][j].first][i-1] + g[v][j].second);
			}
		
		int sol = dist[t][k-1];
		if(sol == INF) puts("-1");
		else printf("%d\n", dist[t][k-1]);
	}	

	return 0;
}
