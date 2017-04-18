#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

#define pb push_back
#define MAX 505
#define INF (int) 1e9

int t, n, m, u, v, dist[MAX], dad[MAX];
vector<int> g[MAX];
bool mark[MAX];

inline int bfs(int s)
{
	for(int i=0; i<n; ++i) mark[i] = 0;
	mark[s] = 1; dist[s] = 0; dad[s] = -1;
	queue<int> q; q.push(s);

	int ret = INF;
	while(!q.empty())
	{
		v = q.front(); q.pop();
		for(int i=0; i<(int)g[v].size(); ++i)
		{
			u = g[v][i];
			if(!mark[u]) mark[u] = 1, q.push(u), dist[u] = dist[v] + 1, dad[u] = v;
			else if(dad[v] != u) 
			{
				ret = min(ret, dist[u] + dist[v] + 1);
				if(ret == 3) return ret;
			}
		}
	}
	return ret;
}

int girth()
{
	int sol = INF;
	for(int i=0; i<n && sol != 3; ++i) sol = min(bfs(i), sol);
	return sol;
}

int main()
{
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i) g[i].clear();
		
		while(m--)
		{
			scanf("%d %d", &u, &v);
			g[u].pb(v); g[v].pb(u);
		}
		
		int sol = girth();

		printf("Case %d: ", tc);
		if(sol == INF) puts("impossible");
		else printf("%d\n", sol);
	}

	return 0;
}
