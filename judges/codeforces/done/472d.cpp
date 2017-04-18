#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 2005

vector< pair<int, int> > g[MAX];
int dist[MAX][MAX], n, dset[MAX], dist2[MAX][MAX];

void init()  { for(int i=0; i<n; ++i) dset[i] = i;  }
int findSet(int i) { return (dset[i] == i) ? i : (dset[i] = findSet(dset[i])); }
bool sameSet(int i, int j) { return (findSet(i) == findSet(j)); } 
void unionSet(int i, int j)
{
	if(sameSet(i, j)) return;
	dset[findSet(j)] = findSet(i);
}

void dfs(int u, int dadu, int root)
{
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i].first, w = g[u][i].second;
		if(v != dadu)
		{
			if(dadu == -1) dist2[root][v] = w;
			else dist2[root][v] = dist2[root][u] + w;
	
			dfs(v, u, root);
		}
	}
}

int main()
{
	vector< pair<int, pair<int, int> > > edges;

	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			scanf("%d", &dist[i][j]);
			if(j > i) edges.pb(mp(dist[i][j], mp(i, j)));
		}
	
	sort(edges.begin(), edges.end());	
	init();
	for(int i=0; i<(int)edges.size(); ++i)
	{
		int u = edges[i].second.first, v = edges[i].second.second, w = edges[i].first;
		
		if(sameSet(u, v)) continue;
		unionSet(u, v);
		g[u].pb(mp(v, w)); g[v].pb(mp(u, w));
	}
	
	memset(dist2, 0, sizeof(dist2));
	for(int i=0; i<n; ++i) dfs(i, -1, i);
	
	
	bool can = 1;
	for(int i=0; can && i<n; ++i)
		for(int j=0; can && j<n; ++j)
			if(dist[i][j] != dist2[i][j] || (dist2[i][j] == 0 && i!=j))
				can = 0;
	
	puts(can ? "YES" : "NO");

	return 0;
}
