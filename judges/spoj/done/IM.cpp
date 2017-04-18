#include<cstdio>
#include<cstring>
#include<cassert>
#include<queue>
using namespace std;

#define MAXN 2*30050
#define MAXM 8*50050
#define INF 0x3f3f3f3f
typedef long long ll;
typedef int flow_type;

struct Edge 
{
	int v;
	flow_type c, f;
	int next;
	Edge() {}
	Edge(int v, flow_type c, flow_type f, int next) : v(v), c(c), f(f), next(next) {}
};

int n, m, head[MAXN], lvl[MAXN], src, snk, work[MAXN];
Edge e[MAXM];

void init(int _n, int _src, int _snk) 
{
	n = _n;
	m = 0;
	src = _src;
	snk = _snk;
	memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, flow_type c, bool bidirectional) 
{
	e[m] = Edge(v, c, 0, head[u]);
	head[u] = m++;
	e[m] = Edge(u, bidirectional ? c : 0, 0, head[v]);
	head[v] = m++;
}

bool bfs() 
{
	queue<int> q;
	memset(lvl, -1, n * sizeof(int));
	lvl[src] = 0;
	q.push(src);
	while (!q.empty()) 
	{
		int u = q.front(); q.pop();
		for(int i = head[u]; i != -1; i = e[i].next) 
		{
			if(e[i].f < e[i].c && lvl[e[i].v] == -1) 
			{
				lvl[e[i].v] = lvl[u] + 1;
				q.push(e[i].v);
				if(e[i].v == snk) return 1;
			}
		}
	}
	return 0;
}

flow_type dfs(int u, flow_type f) 
{
	if(u == snk) return f;
	for(int &i = work[u]; i != -1; i = e[i].next) 
	{
		if(e[i].f < e[i].c && lvl[u] + 1 == lvl[e[i].v]) 
		{
			flow_type minf = dfs(e[i].v, min(f, e[i].c - e[i].f));
			if(minf > 0) 
			{
				e[i].f += minf;
				e[i^1].f -= minf;
				return minf;
			}
		}
	}
	return 0;
}

flow_type dinic() 
{
	flow_type f, ret = 0;
	while (bfs()) 
	{
		memcpy(work, head, n * sizeof(int));
		while((f = dfs(src, INF))) ret += f;
	}
	return ret;
}

int main()
{
	int _n, _m, t;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &_n, &_m);
	
		int source = 0, sink = 2*_n+1;
		
		init(2*_n + 2, source, sink);
		for(int i=1; i<=_n; ++i) addEdge(i, i + _n, 1, 0);

		addEdge(_n+1, sink, 1, 0);
		addEdge(_n+3, sink, 1, 0);
		addEdge(source, _n+2, 2, 0);
		while(_m--)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			if(u > _n || v > _n) continue;
			addEdge(u + _n, v, 1, 0);
			addEdge(v + _n, u, 1, 0);
		}
	
		if(_n >= 3 && dinic() == 2) puts("YES");
		else puts("NO");
	}
	

	return 0;
}
