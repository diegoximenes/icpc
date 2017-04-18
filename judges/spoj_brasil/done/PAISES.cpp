#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

#define WHITE -1
#define MAX 510
#define INF (int) 1e9

int num[MAX], low[MAX], visited[MAX], dfscount, numscc, scc[MAX]; 
vector< vector< pair<int, int> > > g;
vector<int> s;

void tarjan(int u)
{
	low[u] = num[u] = dfscount++;
	s.push_back(u);
	visited[u] = 1;
	for(int j=0; j<(int)g[u].size(); ++j)
	{
		int v = g[u][j].first;
		if(num[v] == WHITE)
			tarjan(v);
		if(visited[v])
			low[u] = min(low[u], low[v]);
	}
	
	if(low[u] == num[u])
	{
		while(1)
		{
			int v = s.back(); s.pop_back(); visited[v] = 0;
			scc[v] = numscc;
			if(u == v) break;
		}
		++numscc;
	}
}

int main()
{
	vector< pair<int, int> > ve;
	int n, m, w, u, v, s , t, k, dist[MAX];
	bool mark[MAX];
	set< pair<int, int> > heap;
	
	ve.clear();
	
	while(scanf("%d %d", &n, &m) && n)
	{
		g.assign(n, ve);
		
		while(m--)
		{
			scanf("%d %d %d", &u, &v, &w);
			--u; --v;
			g[u].push_back(make_pair(v, w));
		}
		
		//tarjan
		for(int i=0; i<n; ++i)
		{
			num[i] = WHITE;
			low[i] = 0;
			visited[i] = 0;
		}
		dfscount = numscc = 0;
		for(int i=0; i<n; ++i)
			if(num[i] == WHITE)
				tarjan(i);
			
		scanf("%d", &k);
		while(k--)
		{
			scanf("%d %d", &s, &t);
			--s; --t;
			
			//dijkstra
			heap.clear();
			for(int i=0; i<n; ++i)
				dist[i] = INF;
			dist[s] = 0;
			heap.insert(make_pair(dist[s], s));
			memset(mark, 0, n*sizeof(bool));
			while(!heap.empty())
			{
				v = (heap.begin())->second;
				mark[v] = 1;
				if(v == t)
					break;
				heap.erase(heap.begin());
				for(int i=0; i<(int)g[v].size(); ++i)
				{
					u = g[v][i].first;
					if(scc[u] == scc[v])
						w = 0;
					else
						w = g[v][i].second;
					
					if(!mark[u] && dist[u] > dist[v] + w)
					{
						heap.erase(make_pair(dist[u], u));
						dist[u] = dist[v] + w;
						heap.insert(make_pair(dist[u], u));
					}
				}
			}
			
			if(!mark[t])
				puts("Nao e possivel entregar a carta");
			else
				printf("%d\n", dist[t]);
		}
		puts("");
	}
	
	return 0;
}