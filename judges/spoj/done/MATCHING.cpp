//O(|E|*sqrt(|V|))

#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define mp make_pair
#define pb push_back

#define MAX 100010
#define INF (int)1e9
#define NIL 0

vector<int> g[MAX];
int match[MAX], dist[MAX], n, m;
//n == number of vertices in the left side, m == number of vertices in the right side
//indices for left side: 1...n, indices for right side: n+1...m
//only need edge from left to right

bool bfs()
{	
	int i, u, v, len;
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
			len = g[u].size();
			for(i=0; i<len; ++i)
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
	int i, v, len;
	if(u != NIL)
	{
		len = g[u].size();
		for(i=0; i<len; ++i)
		{
			v = g[u][i];
			if(dist[match[v]] == dist[u] + 1)
			{
				if(dfs(match[v]))
				{
					match[v] = u;
					match[u] = v;
					return 1;
				}
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

//return indice of vertices from right side. indice of vertices of the vertice side don't need adjusts
inline int indm(int u)
{
	return n + u + 1;
}

int main()
{
	int e, u, v;

	scanf("%d %d %d", &n, &m, &e);
	while(e--)
	{
		scanf("%d %d", &u, &v);
		g[u].pb(indm(v));
	}
	printf("%d\n", hopcroftKarp());

	return 0;
}

