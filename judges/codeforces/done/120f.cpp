#include<cstdio>
#include<bitset>
#include<queue>
using namespace std;

#define mp make_pair

#define MAX 101
#define INF 1e9

bitset<MAX> mark;
int dist[MAX];
vector<int> g[MAX];

pair<int, int> bfs(int s)
{
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	mark.reset();
	mark[s] = 1;
	
	int maxdist = -INF, vmax;
	while(!q.empty())
	{
		int v = q.front(); q.pop();
		if(dist[v] > maxdist)
		{
			maxdist = dist[v];
			vmax = v;
		}
		for(int i=0; i<(int)g[v].size(); ++i)
		{
			int u = g[v][i];
			if(!mark[u])
			{
				dist[u] = dist[v] + 1;
				q.push(u);
				mark[u] = 1;
			}
		}
	}
	
	return mp(dist[vmax], vmax);
}

int main()
{
	int n, m, u, v, distance = 0, nlast = 0;
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	while(n--)
	{
		for(int i=0; i<nlast; ++i)
			g[i].clear();
		
		scanf("%d", &m);
		nlast = m;
		while(--m)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			g[u].push_back(v); g[v].push_back(u);
		}
		pair<int, int> p = bfs(0);
		p = bfs(p.second);
		distance += p.first;
	}
	printf("%d\n", distance);
	
	return 0;
}