#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MAX 1010
#define WHITE -1
#define pb push_back

bool solved;
int dfsRoot, dfsCounter, rootChildren, num[MAX], low[MAX], parent[MAX], articulation[MAX];
vector<int> g[MAX];

void articulationBridge(int u)
{
	low[u] = num[u] = dfsCounter++;
	for(int j=0; j<(int)g[u].size(); ++j)
	{
		int v = g[u][j];
		if(num[v] == WHITE)
		{
			parent[v] = u;
			if(u == dfsRoot) ++rootChildren;

			articulationBridge(v);
			if(solved) return;

			if(low[v] >= num[u]) articulation[u] = 1;
			if(low[v] > num[u]) 
			{
				solved = 1;
				puts("N");
			}
			low[u] = min(low[u], low[v]);
		}
		else if(v != parent[u])
			low[u] = min(low[u], num[v]);
	}
}

int main()
{
	int u, v, n, m;

	while(scanf("%d %d", &n, &m) && n)
	{
		for(int i=0; i<n; ++i)
			g[i].clear();

		for(int i=0; i<m; ++i)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			g[u].pb(v); g[v].pb(u);
		}
		
		solved = 0;
		dfsCounter = 0;
		for(int i=0; i<n; ++i)
		{
			num[i] = WHITE;
			low[i] = parent[i] = articulation[i] = 0;
		}
		for(int i=0; i<n && !solved; ++i)
			if(num[i] == WHITE)
			{
				dfsRoot = i; rootChildren = 0;
				articulationBridge(i);
				articulation[dfsRoot] = (rootChildren > 1);
			}
		if(!solved)	puts("S");
	}

	return 0;
}
