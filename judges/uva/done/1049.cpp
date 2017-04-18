/*
O(n*m + f*m*log(n)), f = maximum flow
Work with multigraph and initial negative edges.
*/

#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define INF 0x3f3f3f3f
#define MAXN (55+55)
#define MAXM 2*(55*55 + 110) //must also counts reverse edges

typedef double cost_type;

struct Edge 
{
	int u, v, cap, flow; 
	cost_type cost;
	int next;
	Edge() {}
	Edge(int u, int v, int cap, int flow, cost_type cost, int next) : u(u), v(v), cap(cap), flow(flow), cost(cost), next(next) {}
};

int n, m, head[MAXN], src, snk;
Edge e[MAXM];
int path[MAXN], mincap[MAXN], vis[MAXN];
cost_type pi[MAXN], dist[MAXN];

void init(int _n, int _src, int _snk) 
{
	n = _n;
	m = 0;
	src = _src;
	snk = _snk;
	memset(head, -1, sizeof(head));
}

//directional edge
void addEdge(int u, int v, int cap, cost_type cost) 
{
	e[m] = Edge(u, v, cap, 0, cost, head[u]);
	head[u] = m++;
	e[m] = Edge(v, u, 0, 0, -cost, head[v]);
	head[v] = m++;
}

int bellman_ford() 
{
	for(int i=0; i<=n; ++i) pi[i] = INF;
	pi[src] = 0;
	int flag = 1;
	for(int i = 0; flag && i < n; i++) 
	{
		flag = 0;
		for(int j = 0; j < m; j++) 
		{
			if(e[j].cap == e[j].flow) continue;
			if(pi[e[j].u] + e[j].cost < pi[e[j].v]) 
			{
				pi[e[j].v] = pi[e[j].u] + e[j].cost;
				flag = 1;
			}
		}
	}
	return flag;
}

int dijkstra() 
{
	priority_queue< pair<cost_type, int>, vector< pair<cost_type, int> >, greater< pair<cost_type, int> > > heap;
	for(int i=0; i<=n; ++i) dist[i] = INF;
	memset(vis, 0, sizeof(vis));
	dist[src] = 0;
	mincap[src] = INF;
	heap.push(mp(0, src));
	while(!heap.empty()) 
	{
		int u = heap.top().second;
		heap.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u]; i != -1; i = e[i].next) 
		{
			int v = e[i].v;
			if(vis[v] || e[i].flow == e[i].cap) continue;
			cost_type w = dist[u] + e[i].cost + pi[u] - pi[v];
			if(w < dist[v]) 
			{
				dist[v] = w;
				path[v] = i;
				mincap[v] = min(mincap[u], e[i].cap - e[i].flow);
				heap.push(mp(dist[v], v));
			}
		}
	}

	// update potencials
	for(int i = 0; i < n; i++) pi[i] += dist[i];

	return dist[snk] < INF;
}

pair<cost_type, int> mcmf() 
{
	// set potencials
	if(bellman_ford()) return mp(-1, -1);

	cost_type cost = 0;
	int flow = 0;
	while(dijkstra()) 
	{
		// augment path and update cost
		int f = mincap[snk];
		for (int v = snk; v != src; ) 
		{
			int idx = path[v];
			e[idx].flow += f;
			e[idx^1].flow -= f;
			cost += e[idx].cost * f;
			v = e[idx].u;
		}
		flow += f;
	}

	return mp(cost, flow);
}

#define MAXLEFT 55
double cost[MAXLEFT][MAXLEFT];
int capLeft[MAXLEFT], capRight[MAXLEFT];

int main()
{
	int nLeft, nRight;
	int source = 0, sink = 1;

	for(int tc=1; scanf("%d %d", &nLeft, &nRight) && nLeft; ++tc)
	{
		for(int i=0; i<nLeft; ++i) scanf("%d", &capLeft[i]);
		for(int i=0; i<nRight; ++i) scanf("%d", &capRight[i]);
		for(int i=0; i<nLeft; ++i)
			for(int j=0; j<nRight; ++j)
				scanf("%lf", &cost[i][j]);
		
		//minimum cost
		init(2 + nLeft + nRight, source, sink);
		for(int i=0; i<nLeft; ++i) addEdge(source, 2 + i, capLeft[i], 0);
		for(int i=0; i<nRight; ++i) addEdge(2 + nLeft + i, sink, capRight[i], 0);

		for(int i=0; i<nLeft; ++i)
			for(int j=0; j<nRight; ++j)
				if(cost[i][j] > -1) 
					addEdge(2 + i, 2 + nLeft + j, INF, cost[i][j]);

		double minCost = mcmf().first;
		
		//maximum cost
		init(2 + nLeft + nRight, source, sink);
		for(int i=0; i<nLeft; ++i) addEdge(source, 2 + i, capLeft[i], 0);
		for(int i=0; i<nRight; ++i) addEdge(2 + nLeft + i, sink, capRight[i], 0);

		for(int i=0; i<nLeft; ++i)
			for(int j=0; j<nRight; ++j)
				if(cost[i][j] > -1) 
					addEdge(2 + i, 2 + nLeft + j, INF, -cost[i][j]);
		
		double maxCost = -mcmf().first;

		printf("Problem %d: %.2lf to %.2lf\n", tc, minCost, maxCost);
	}

	return 0;
}
