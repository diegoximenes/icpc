#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
using namespace std;

#define pb push_back
#define mp make_pair

#define INF 1e9
#define NMAX 20010
#define LOGNMAX 15

vector< pair<int, int> > g[NMAX];
bool mark[NMAX];
int cost[NMAX], dad[NMAX], ancestor[NMAX][LOGNMAX], bottleneck[NMAX][LOGNMAX], level[NMAX];

void build(int n)
{
	memset(ancestor, -1, sizeof(ancestor));

	for(int i=0; i<n; ++i) ancestor[i][0] = dad[i];

	for(int j=1; (1 << j) < n; ++j)
		for(int i=0; i<n; ++i)
			if(ancestor[i][j-1] != -1)
			{
				bottleneck[i][j] = min(bottleneck[i][j-1], bottleneck[ancestor[i][j-1]][j-1]);
				ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
			}
}

int lca(int p, int q)
{
	int log, bot = INF;
	
	if(level[p] < level[q]) swap(p, q);

	for(log=1; (1 << log) <= level[p]; ++log);
	--log;
	
	for(int i=log; i>=0; --i)
		if(level[p] - (1 << i) >= level[q])
		{
			bot = min(bot, bottleneck[p][i]);
			p = ancestor[p][i];
		}

	if(p == q) return bot;

	for(int i=log; i>=0; --i)
		if(ancestor[p][i] != -1 && ancestor[p][i] != ancestor[q][i])
		{
			bot = min(bot, bottleneck[p][i]);
			bot = min(bot, bottleneck[q][i]);
			p = ancestor[p][i], q = ancestor[q][i];
		}
	
	return min(bot, min(bottleneck[p][0], bottleneck[q][0]));
}

int main()
{
	int n, m, s, u, v, w;

	while(scanf("%d %d %d", &n, &m, &s) == 3)
	{
		for(int i=0; i<n; ++i) g[i].clear();
		while(m--)
		{
			scanf("%d %d %d", &u, &v, &w);
			--u; --v;
			g[u].pb(mp(v, w)); g[v].pb(mp(u, w));
		}

		for(int i=0; i<n; ++i) cost[i] = -INF, mark[i] = 0;
		cost[0] = 0; dad[0] = -1; level[0] = 0;
		set< pair<int, int> > heap;
		heap.insert(mp(-cost[0], 0));
		while(!heap.empty())
		{
			int v = heap.begin()->second;
			heap.erase(heap.begin());
			mark[v] = 1;

			for(int i=0; i<(int)g[v].size(); ++i)
			{
				int u = g[v][i].first, w = g[v][i].second;
				if(!mark[u] && cost[u] < w)
				{
					heap.erase(mp(-cost[u], u));
					cost[u] = w;
					dad[u] = v; level[u] = level[v] + 1;
					bottleneck[u][0] = w;
					heap.insert(mp(-cost[u], u));
				}
			}
		}
		
		build(n);
		while(s--)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			printf("%d\n", lca(u, v));
		}
	}

	return 0;
}

