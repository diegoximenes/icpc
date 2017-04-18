#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define mp make_pair
#define pb push_back

#define MAX 10010
#define INF (int)1e9
#define NIL 0

vector<int> g[MAX];
int match[MAX], dist[MAX], n, m, color[MAX];

bool bfs()
{	
	int i, u, v;
	queue<int> q;
	
	for(i=1; i<=n; ++i)
	{
		if(match[i] == NIL)
		{
			dist[i] = 0;
			q.push(i);
		}
		else dist[i] = INF;
	}

	dist[NIL] = INF;
	while(!q.empty())
	{
		u = q.front(); q.pop();
		if(u != NIL)
		{
			for(i=0; i<(int)g[u].size(); ++i)
			{
				v = g[u][i];
				if(dist[match[v]] == INF)
				{
					dist[match[v]] = dist[u] + 1;
					q.push(match[v]);
				}
			}
		}
	}
	
	return (dist[NIL] != INF);
}

bool dfs(int u)
{
	int i, v;
	
	if(u != NIL)
	{
		for(i=0; i<(int)g[u].size(); ++i)
		{
			v = g[u][i];
			if(dist[match[v]] == dist[u] + 1 && dfs(match[v]))
			{
				match[v] = u; match[u] = v;
				return 1;
			}
		}
		
		dist[u] = INF;
		return 0;
	}
	
	return 1;
}

int hopcroftKarp()
{
	int matching = 0, i;
	for(int i=0; i<=n+m; ++i) match[i] = NIL;
	while(bfs())
		for(i=1; i<=n; ++i)
			if(match[i] == NIL && dfs(i))
				++matching;
	return matching;
}

inline int indm(int u)
{
	return n + u + 1;
}

int main()
{
	scanf("%d %*d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", &color[i]);

	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			if(color[i] != color[j])
				g[i].pb(indm(j));

	printf("%d\n", hopcroftKarp());
	for(int i=1; i<=n; ++i) printf("%d %d\n", color[i], (match[i] != NIL) ? color[match[i] - n - 1] : color[i]);

	return 0;
}

