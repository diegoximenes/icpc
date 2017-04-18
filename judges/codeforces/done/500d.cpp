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
#define MAX 100005

int dp[MAX], dad[MAX];
vector<int> g[MAX];

struct Edge
{
	int u, v, w;
	Edge(int _u=0, int _v=0, int _w=0) : u(_u), v(_v), w(_w) {}
	bool operator<(Edge o) const
	{
		if(u != o.u) return (u < o.u);
		if(v != o.v) return (v < o.v);
		return (w < o.w);
	}
};

int dfs(int u)
{
	dp[u] = 1;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(v != dad[u]) dad[v] = u, dp[u] += dfs(v);
	}
	return dp[u];
}

int main()
{
	map< int, Edge > edge;
	map< int, Edge >::iterator it;
	int n;

	scanf("%d", &n);
	for(int i=0; i<n-1; ++i)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		edge[i+1] = Edge(u, v, w);
		g[u].pb(v); g[v].pb(u);
	}

	dad[0] = -1;
	dfs(0);
	ll totalDist = 0;
	for(it=edge.begin(); it!=edge.end(); ++it)
	{
		int u = it->se.u, v = it->se.v, w = it->se.w;
		if(v == dad[u]) swap(u, v);
		totalDist += (ll)dp[v] * (ll)(n - dp[v]) * (ll)w;
	}

	int q;
	scanf("%d", &q);
	for(int i=0; i<q; ++i)
	{
		int id, nw;
		scanf("%d %d", &id, &nw);
		Edge e = edge[id];

		int u = e.u, v = e.v, w = e.w;
		if(v == dad[u]) swap(u, v);
		totalDist -= (ll)dp[v] * (ll)(n - dp[v]) * (ll)(w-nw);

		edge[id].w = nw;
		
		double sol = (double)(totalDist * 6) / (double)((ll)n * (ll)(n-1));
		printf("%.7lf\n", sol);
	}

	return 0;
}
