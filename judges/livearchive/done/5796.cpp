#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

#define MAX 10010
#define WHITE -1
#define mp make_pair
#define pb push_back

vector< pair<int, int> > bridge;
int dfsCounter, num[MAX], low[MAX], parent[MAX], set[MAX];
vector<int> g[MAX];

void findBridges(int u)
{
	low[u] = num[u] = dfsCounter++;
	for(int j=0; j<(int)g[u].size(); ++j)
	{
		int v = g[u][j];
		if(num[v] == WHITE)
		{
			parent[v] = u;

			findBridges(v);

			if(low[v] > num[u]) bridge.pb(mp(u, v));
			low[u] = min(low[u], low[v]);
		}
		else if(v != parent[u])
			low[u] = min(low[u], num[v]);
	}
}

void initSet(int n)
{
	for(int i=0; i<n; ++i) set[i] = i;
}

int findSet(int i)
{
	return (set[i] == i) ? i : (set[i] = findSet(set[i]));
}

bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}

void unionSet(int i, int j)
{
	set[findSet(i)] = findSet(j);
}

int main()
{
	int n, m, q, u, v;

	while(scanf("%d %d %d", &n, &m, &q) && n)
	{
		for(int i=0; i<n; ++i) g[i].clear();
		while(m--)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			g[u].pb(v); g[v].pb(u);
		}
		
		dfsCounter = 0;
		bridge.clear();
		for(int i=0; i<n; ++i)
		{
			num[i] = WHITE;
			low[i] = parent[i] = 0;
		}
		for(int i=0; i<n; ++i)
			if(num[i] == WHITE)
				findBridges(i);
		
		initSet(n);
		for(int i=0; i<(int)bridge.size(); ++i)
			if(!isSameSet(bridge[i].first, bridge[i].second))
				unionSet(bridge[i].first, bridge[i].second);
		
		while(q--)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			if(isSameSet(u, v)) puts("Y");
			else puts("N");
		}
		puts("-");
	}

	return 0;
}

