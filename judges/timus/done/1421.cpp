#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>

#define INF (int) 1e9
#define MAX 110*2

using namespace std;

typedef long long LL;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel {
  int N;
  vector<vector<Edge> > G;
  vector<LL> excess;
  vector<int> dist, active, count;
  queue<int> Q;

  PushRelabel(int N) : N(N), G(N), excess(N), dist(N), active(N), count(2*N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  void Enqueue(int v) { 
    if (!active[v] && excess[v] > 0) { active[v] = true; Q.push(v); } 
  }

  void Push(Edge &e) {
    int amt = int(min(excess[e.from], LL(e.cap - e.flow)));
    if (dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    G[e.to][e.index].flow -= amt;
    excess[e.to] += amt;    
    excess[e.from] -= amt;
    Enqueue(e.to);
  }
  
  void Gap(int k) {
    for (int v = 0; v < N; v++) {
      if (dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      Enqueue(v);
    }
  }

  void Relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for (int i = 0; i < G[v].size(); i++) 
      if (G[v][i].cap - G[v][i].flow > 0)
	dist[v] = min(dist[v], dist[G[v][i].to] + 1);
    count[dist[v]]++;
    Enqueue(v);
  }

  void Discharge(int v) {
    for (int i = 0; excess[v] > 0 && i < G[v].size(); i++) Push(G[v][i]);
    if (excess[v] > 0) {
      if (count[dist[v]] == 1) 
	Gap(dist[v]); 
      else
	Relabel(v);
    }
  }

  LL GetMaxFlow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for (int i = 0; i < G[s].size(); i++) {
      excess[s] += G[s][i].cap;
      Push(G[s][i]);
    }
    
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      active[v] = false;
      Discharge(v);
    }
    
    LL totflow = 0;
    for (int i = 0; i < G[s].size(); i++) totflow += G[s][i].flow;
    return totflow;
  }
};

int main()
{
	int sc, sr, sumSR = 0, N, t, s = 0, n;
	
	scanf("%d", &N);
	t = 2*N+1;
	n = 2*N+2;
	
	PushRelabel g(n);
	
	int flow[MAX][MAX];
	for(int i=0; i<=t; ++i)
		for(int j=0; j<=t; ++j)
			flow[i][j] = 0;
	
	for(int i=N+1; i<=2*N; ++i)
		scanf("%d", &sr);
		sumSR += sr;
		g.AddEdge(i, t, sr);
		
	for(int i=1; i<=N; ++i)
		scanf("%d", &sc);
		g.AddEdge(s, i, sc);
		
	for(int i=1; i<=N; ++i)
		for(int j=N+1; j<=2*N; ++j)
			g.AddEdge(i, j, 100);
	
	int maxflow =  g.GetMaxFlow(s, t);
	for(int i=0; i<(int)g.G.size(); ++i)
		for(int j=0; j<(int)g.G[i].size(); ++j)
			flow[g.G[i][j].from][g.G[i][j].to] = g.G[i][j].flow;

	if(maxflow != sumSR)
		puts("NO");
	else
	{
		puts("YES");
		for(int i=N+1; i<=2*N; ++i)
		{
			for(int j=1; j<N; ++j)
				printf("%d ", flow[j][i]);
			printf("%d\n", flow[N][i]);
		}
	}
	
	return 0;
}