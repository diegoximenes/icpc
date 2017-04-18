#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

#define pb push_back
#define MAX 110
#define MAX2 MAX*MAX
#define INF (int) 1e9
#define NIL 0

pair<int, int> id[MAX][MAX];
int n, m, match[MAX2], dist[MAX2], l;
char grid[MAX][MAX];
vector<int> g[MAX2];

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

int main()
{
	while(scanf("%d", &l) == 1)
	{
		for(int i=0; i<l; ++i) scanf(" %s", grid[i]);
		
		bool change = 1;
		n = 1;
		for(int i=0; i<l; ++i)
		{
			for(int j=0; j<l; ++j)
			{
				if(grid[i][j] == '.')
				{
					if(change) change = 0, id[i][j].first = n++;
					else id[i][j].first = id[i][j-1].first;
				}
				else change = 1;
			}
			change = 1;
		}
		m = n;
		for(int j=0; j<l; ++j)
		{
			for(int i=0; i<l; ++i)
			{
				if(grid[i][j] == '.')
				{
					if(change) change = 0, id[i][j].second = m++;
					else id[i][j].second = id[i-1][j].second;
				}
				else change = 1;
			}
			change = 1;
		}
		for(int i=0; i<=n; ++i) g[i].clear();
		for(int i=0; i<l; ++i)
			for(int j=0; j<l; ++j)
				if(grid[i][j] == '.')
					g[id[i][j].first].pb(id[i][j].second);

		printf("%d\n", hopcroftKarp());
	}

	return 0;
}
