#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

#define mp make_pair
#define MAX 110
#define INF 1e17
#define ll long long

vector< pair<int, ll> > g[MAX];
int n, dad[MAX];
ll flow[MAX][MAX], cap[MAX][MAX], dist[MAX], pot[MAX];

void dijkstra(int s, int t)
{
	for(int i=0; i<n; ++i) dist[i] = INF;
	dist[s] = 0;
	priority_queue< pair<ll, int> > pq;
	pq.push(mp(0, s));
	dad[s] = -1;

	while(!pq.empty())
	{
		int v = pq.top().second;
		ll d = -pq.top().first;
		pq.pop();
		
		if(d == dist[v])
			for(int j=0; j<(int)g[v].size(); ++j)
			{
				int u = g[v][j].first;
				ll w = g[v][j].second;
				ll newdist = dist[v] + w + pot[v] - pot[u];
				if(dist[u] > newdist && cap[v][u] - flow[v][u] > 0)
				{
					dist[u] = newdist;
					dad[u] = v;
					pq.push(mp(-dist[u], u));
				}
				newdist = dist[v] + pot[v] - w - pot[u];
				if(flow[u][v] > 0 && dist[u] > newdist)
				{
					dist[u] = newdist;
					dad[u] = v;
					pq.push(mp(-dist[u], u));
				}
			}
	}
}

pair<ll, ll> edmondsKarp(int s, int t)
{
	ll bottleneck, f = 0, time = 0;
	
	memset(flow, 0, sizeof(flow));
	memset(pot, 0, sizeof(pot));
	while(1)
	{
		dijkstra(s, t);
		if(dist[t] == INF) break;
		
		bottleneck = INF;
		for(int v = t; dad[v] != -1; v = dad[v])
			bottleneck = min(bottleneck, cap[dad[v]][v] - flow[dad[v]][v]);
		
		time += bottleneck*(dist[t] - pot[s] + pot[t]);

		for(int i=0; i<n; ++i) if(dist[i] != INF) pot[i] += dist[i];

		for(int v = t; dad[v] != -1; v = dad[v])
		{
			flow[dad[v]][v] += bottleneck;
			flow[v][dad[v]] -= bottleneck;
		}
		f += bottleneck;
	}
	
	return mp(f, time);
}

inline void addEdge(int u, int v, ll w, bool bidirectional, int s, int t)
{
	if((v != s) && (u != t)) g[u].push_back(mp(v, w));
	if((u != s) && (v != t)) g[v].push_back(mp(u, w));
}

int main()
{
	int s, t, m, u, v; 
	ll w, d, k;

	while(scanf("%d %d", &n, &m) == 2)
	{
		for(int i=0; i<n+1; ++i) g[i].clear();
		memset(cap, 0, sizeof(cap));

		s = n; t = n-1; n++;
		while(m--)
		{
			scanf("%d %d %lld", &u, &v, &w);
			--u; --v;
			addEdge(u, v, w, 1, s, t);
		}
		scanf("%lld %lld", &d, &k);
		
		for(int i=0; i<n; ++i)
			for(int j=0; j<(int)g[i].size(); ++j)
				cap[i][g[i][j].first] = cap[g[i][j].first][i] =  k;
		cap[s][0] = d; g[s].push_back(mp(0, 0));
		
		pair<ll, ll> p = edmondsKarp(s, t);
		if(d == p.first) printf("%lld\n", p.second);
		else puts("Impossible.");
	}
	
	return 0;
}
