#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
const ll INF = 1000000000;
#define MAX 2005

ll finalDist[MAX][MAX], dist[MAX], distDfs[MAX][MAX], finalGraph[MAX][MAX];
int dad[MAX]; 
bool mark[MAX];
vector< pair<int, ll> > g[MAX];

void dfs(int initial, int u, int dadu, ll w)
{
	distDfs[initial][u] = w;
	if(dadu != -1) distDfs[initial][u] += distDfs[initial][dadu];
	
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i].first;
		ll w = g[u][i].second;
		if(v != dadu) dfs(initial, v, u, w);
	}
}

int main()
{
	int n;
	
	bool firstCase = 1;
	while(scanf("%d", &n) == 1)
	{
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				scanf("%lld", &finalDist[i][j]);
				finalGraph[i][j] = 0;
				distDfs[i][j] = INF;
			}
			mark[i] = 0; dist[i] = INF;
			g[i].clear();
		}

		dist[0] = 0; dad[0] = -1;
		set< pair<ll, int> > heap;
		heap.insert(mp(dist[0], 0));
		while(!heap.empty())
		{
			int u = heap.begin()->second;
			heap.erase(heap.begin());
			mark[u] = 1;
			
			if(dad[u] != -1)
			{
				g[u].pb(mp(dad[u], finalDist[dad[u]][u]));
				g[dad[u]].pb(mp(u, finalDist[dad[u]][u]));
				finalGraph[u][dad[u]] = finalGraph[dad[u]][u] = finalDist[dad[u]][u];
			}

			for(int v=0; v<n; ++v)
				if(!mark[v] && dist[v] > finalDist[u][v])
				{
					dad[v] = u;
					heap.erase(mp(dist[v], v));
					dist[v] = finalDist[u][v];
					heap.insert(mp(dist[v], v));
				}
		}
		
		for(int i=0; i<n; ++i) distDfs[i][i] = 0, dfs(i, i, -1, 0);
		
		bool lessEdges = 1;
		ll minNextEdge = INF;
		pair<int, int> nextEdge;
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				if(finalDist[i][j] != distDfs[i][j] && minNextEdge > finalDist[i][j])
				{
					minNextEdge = finalDist[i][j];
					nextEdge = mp(i, j);
				}
		
		if(minNextEdge != INF) finalGraph[nextEdge.first][nextEdge.second] = finalGraph[nextEdge.second][nextEdge.first] = minNextEdge, lessEdges = 0;
			
		if(!firstCase) puts("");
		for(int i=0; i<n; ++i)
			for(int j=i+1; j<n; ++j)
				if(finalGraph[i][j])
				{
					printf("%d %d %lld\n", i+1, j+1, finalGraph[i][j]);
					if(lessEdges) printf("%d %d %lld\n", i+1, j+1, finalGraph[i][j]);
					lessEdges = 0;
				}

		firstCase = 0;
	}

	return 0;
}
