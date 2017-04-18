/*
Description: Find two disjoint paths in a nonnegatively-weighted directed graph, so that connect the same pair of verticves and have minimum total length.

Version: EDGE disjoint, so can use same vertice multiple times

Complexity: complexity of dijkstra

Algorithm:
1. Find the shortest path tree T rooted at node s by running Dijkstra's algorithm. This tree contains for every vertex u, a shortest path from s to u. Let P1 be the shortest cost path from s to t. The edges in T are called tree edges and the remaining edges are called non tree edges.
2. Modify the cost of each edge in the graph by replacing the cost w(u,v) of every edge (u,v) by w'(u,v) = w(u,v) − d(s,v) + d(s,u). According to the resulting modified cost function, all tree edges have a cost of 0, and non tree edges have a non negative cost.
3. Create a residual graph Gt formed from G by removing the edges of G that are directed into s and by reversing the direction of the zero length edges along path P1.
4. Find the shortest path P2 in the residual graph Gt by running Dijkstra's algorithm.
5. Discard the reversed edges of P2 from both paths. The remaining edges of P1 and P2 form a subgraph with two outgoing edges at s, two incoming edges at t, and one incoming and one outgoing edge at each remaining vertex. Therefore, this subgraph consists of two edge-disjoint paths from s to t and possibly some additional (zero-length) cycles. Return the two disjoint paths from the subgraph.

Variation: vertex disjoint paths
The version of Suurballe's algorithm as described above finds paths that have disjoint edges, but that may share vertices. It is possible to use the same algorithm to find vertex-disjoint paths, by replacing each vertex by a pair of adjacent vertices, one with all of the incoming adjacencies of the original vertex, and one with all of the outgoing adjacencies. Two edge-disjoint paths in this modified graph necessarily correspond to two vertex-disjoint paths in the original graph, and vice versa, so applying Suurballe's algorithm to the modified graph results in the construction of two vertex-disjoint paths in the original graph. 
*/

#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<cstring>
using namespace std;

#define MAX 110
#define INF (int) 1e9
#define mp make_pair
#define pb push_back

struct edge
{
	int v, w;
	bool rev;
	edge(int v = 0, int w = 0, bool rev = 0) : v(v), w(w), rev(rev) {}
};

list<edge> g[MAX];
list<edge>::iterator it;
bool mark[MAX];
int dist1[MAX], dist2[MAX], n;
edge dad1[MAX], dad2[MAX];

void dijkstra(int s, int t, int *dist, edge *dad)
{
	set< pair<int, int> > heap;
	for(int i=0; i<n; ++i) dist[i] = INF;
	memset(mark, 0, sizeof(mark));
	dad[s].v = -1; dist[s] = 0;
	heap.insert(mp(dist[s], s));

	while(!heap.empty())
	{
		int v = heap.begin()->second; heap.erase(heap.begin());
		mark[v] = 1;

		for(it = g[v].begin(); it != g[v].end(); ++it)
		{
			int u = it->v, w = it->w;
			bool rev = it->rev;
			if(!mark[u] && dist[u] > dist[v] + w)
			{
				heap.erase(mp(dist[u], u));
				dist[u] = dist[v] + w;
				dad[u] = edge(v, w, rev);
				heap.insert(mp(dist[u], u));
			}
		}
	}
}

void modifyCost(int s, int *dist)
{
	for(int v=0; v<n; ++v)
		for(it = g[v].begin(); it != g[v].end(); ++it)
			it->w = it->w - dist[it->v] + dist[v];
}

//update graph g
void generateResidualGraph(int s, int t, edge *dad)
{
	vector< pair<int, list<edge>::iterator> > erase;
	vector< pair<int, edge> > insert;
	set< pair<int, int> > tree;
	
	for(int v = t; dad[v].v != -1; v = dad[v].v) tree.insert(mp(v, dad[v].v));

	for(int v=0; v<n; ++v)
		for(it = g[v].begin(); it != g[v].end(); ++it)
		{
			int u = it->v;
			if(u == s)
			{
				erase.pb(mp(v, it));
				continue;
			}
			if(tree.find(mp(u, v)) != tree.end())
			{
				erase.pb(mp(v, it));
				insert.pb(mp(u, edge(v, 0, 1)));
			}
		}
	
	for(int i=0; i<(int)erase.size(); ++i) g[erase[i].first].erase(erase[i].second);
	for(int i=0; i<(int)insert.size(); ++i) g[insert[i].first].pb(insert[i].second);
}

int removeCommonEdges(int t, edge *p1, edge *p2, int *dist)
{
	set< pair<int, int> > e; //keep edges of the graph which contains only the edges of the two paths
	set< pair<int, int> >::iterator ite;
	map< pair<int, int>, int > w; 
	
	//insert edges from path 1
	for(int v = t; p1[v].v != -1; v = p1[v].v)
	{
		e.insert(mp(p1[v].v, v));
		w[mp(p1[v].v, v)] = p1[v].w;
	}
	//insert edges from path 2 - before adding an edge verify if this edge or this edge reversed was already inserted. If yes the previous edge is removed e the new edge is discarted.
	for(int v = t; p2[v].v != -1; v = p2[v].v)
	{
		if(e.find(mp(v, p2[v].v)) != e.end()) e.erase(mp(v, p2[v].v));
		else if(e.find(mp(p2[v].v, v)) != e.end()) e.erase(mp(p2[v].v, v));
		else
		{ 
			e.insert(mp(p2[v].v, v));
			//adjust weights
			if(!p2[v].rev) w[mp(p2[v].v, v)] = p2[v].w + dist[v] - dist[p2[v].v];
			else w[mp(p2[v].v, v)] = p2[v].w - dist[v] + dist[p2[v].v];
		}
	}
	
	//calculate weight from both paths	
	int d = 0;
	for(ite = e.begin(); ite != e.end(); ++ite) d += w[*ite];

	return d;
}

int suurballe(int s, int t)
{
	dijkstra(s, t, dist1, dad1);
	modifyCost(s, dist1);
	generateResidualGraph(s, t, dad1);
	dijkstra(s, t, dist2, dad2);
	
	if(dist1[t] == INF || dist2[t] == INF) return -1; //there aren't two paths
	int dist = removeCommonEdges(t, dad1, dad2, dist1);
	return dist;
}

int main()
{
	int u, v, w, m;

	while(scanf("%d", &n) && n)
	{
		for(int i=0; i<n; ++i) g[i].clear();

		scanf("%d", &m);
		while(m--)
		{
			scanf("%d %d %d", &u, &v, &w);
			--u; --v;
			g[u].pb(edge(v, w, 0));
			g[v].pb(edge(u, w, 0));
		}

		int d = suurballe(0, n-1);
		if(d < 0) puts("Back to jail");
		else printf("%d\n", d);
	}

	return 0;
}
