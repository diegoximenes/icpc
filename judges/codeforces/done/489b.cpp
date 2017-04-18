#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define mp make_pair
#define pb push_back

#define MAX 210
#define INF 0x3f3f3f3f
#define NIL 0

vector<int> g[MAX];
int match[MAX], dist[MAX], nLeft, nRight;

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

int a[MAX], b[MAX];

int main()
{
	scanf("%d", &nLeft);
	for(int i=1; i<=nLeft; ++i) scanf("%d", &a[i]);
	scanf("%d", &nRight);
	for(int i=1; i<=nRight; ++i) scanf("%d", &b[i]);
	
	for(int i=1; i<=nLeft; ++i)
		for(int j=1; j<=nRight; ++j)
			if(abs(a[i] - b[j]) <= 1)
				g[i].pb(idRight(j));
	printf("%d\n", hopcroftKarp());

	return 0;
}

