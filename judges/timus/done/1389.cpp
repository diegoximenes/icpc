//bipartite matching of a tree

#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define mp make_pair
#define pb push_back

#define MAX 2*100005
#define INF 0x3f3f3f3f
#define NIL 0

vector<int> g[MAX], gaux[MAX];
int match[MAX], dist[MAX], nLeft, nRight;
bool mark[MAX];
int color[MAX];

bool bfs()
{	
	int i, u, v;
	queue<int> q;
	
	for(i=1; i<=nLeft; ++i)
	{
		if(match[i] == NIL) dist[i] = 0, q.push(i);
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
	for(int i=0; i<=nLeft+nRight; ++i) match[i] = NIL;
	while(bfs())
		for(i=1; i<=nLeft; ++i)
			if(match[i] == NIL && dfs(i))
				++matching;
	return matching;
}

inline int idRight(int u)
{
	return nLeft + u;
}

void dfs(int u, int c)
{
	mark[u] = 1;
	color[u] = c;
	for(int i=0; i<(int)gaux[u].size(); ++i)
	{
		int v = gaux[u][i];
		if(!mark[v]) dfs(v, 1-c);
	}
}

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);
	while(m--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		gaux[u].pb(v); gaux[v].pb(u);
	}
	
	//"generate" bipartite graph
	memset(mark, 0, sizeof(mark));
	dfs(1, 0);
	for(int u=1; u<=n; ++u)
		if(color[u] == 0)
			for(int i=0; i<(int)gaux[u].size(); ++i)
				g[u].pb(idRight(gaux[u][i]));
	nLeft = nRight = n;

	printf("%d\n", hopcroftKarp());
	
	//print match
	memset(mark, 0, sizeof(mark));
	for(int i=1; i<=n; ++i)
		if(match[i] != NIL && !mark[i])
		{
			printf("%d %d\n", i, match[i]);
			mark[i] = mark[match[i]] = 1;
		}

	return 0;
}

