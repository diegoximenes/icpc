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
int n, m, match[MAX2], dist[MAX2], x, y, q, t;
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
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &x, &y, &q);
		
		for(int i=0; i<x; ++i)
			for(int j=0; j<y; ++j)
				grid[i][j] = '.';

		while(q--) scanf("%d %d", &n, &m), --n, --m, grid[n][m] = '*';
		scanf("%d", &q);
		while(q--) scanf("%d %d", &n, &m), --n, --m, grid[n][m] = '#';
		
		
		bool change = 1;
		n = 1;
		for(int i=0; i<x; ++i)
		{
			for(int j=0; j<y; ++j)
			{
				if(grid[i][j] == '*')
				{
					if(change) change = 0, id[i][j].first = n++;
					else id[i][j].first = id[i][j-1].first;
				}
				else if(grid[i][j] == '.') id[i][j].first = id[i][j-1].first;
				else if(grid[i][j] == '#') change = 1;
			}
			change = 1;
		}
		m = n;
		for(int j=0; j<y; ++j)
		{
			for(int i=0; i<x; ++i)
			{
				if(grid[i][j] == '*')
				{
					if(change) change = 0, id[i][j].second = m++;
					else id[i][j].second = id[i-1][j].second;
				}
				else if(grid[i][j] == '.') id[i][j].second = id[i-1][j].second;
				else if(grid[i][j] == '#') change = 1;
			}
			change = 1;
		}
	
		/*for(int i=0; i<x; ++i, puts(""))
			for(int j=0; j<y; ++j)
				printf("%c ", grid[i][j]);

		
		for(int i=0; i<x; ++i, puts(""))
			for(int j=0; j<y; ++j)
				printf("(%d, %d)  ", id[i][j].first, id[i][j].second);*/

		for(int i=0; i<=n; ++i) g[i].clear();
		for(int i=0; i<x; ++i)
			for(int j=0; j<y; ++j)
				if(grid[i][j] == '*')
					g[id[i][j].first].pb(id[i][j].second);

		printf("%d\n", hopcroftKarp());
	}

	return 0;
}
