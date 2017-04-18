#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

#define pb push_back
#define MAX 100010

int n, m, color[MAX];
bool can[MAX][4], mark[MAX];
vector<int> g[MAX];

void bfs(int s)
{
	queue<int> q; q.push(s); mark[s] = 1;
	while(!q.empty())
	{
		int v = q.front(); q.pop();
		
		int c;
		for(int i=1; i<=3; ++i)
			if(can[v][i])
			{
				color[v] = c = i;
				break;
			}

		for(int i=0; i<(int)g[v].size(); ++i)
		{
			int u = g[v][i];
			if(mark[u] == 0) 
			{
				mark[u] = 1;
				q.push(u);
			}
			can[u][c] = 0;
		}
	}
}

int main()
{
	for(int i=0; i<MAX; ++i) can[i][1] = can[i][2] = can[i][3] = 1;
	memset(color, 0, sizeof(color));
	memset(mark, 0, sizeof(mark));

	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		--a; --b; --c;
		g[a].pb(b); g[a].pb(c);
		g[b].pb(a); g[b].pb(c);
		g[c].pb(a); g[c].pb(b);
	}
	
	for(int i=0; i<n; ++i)
		if(!mark[i])
			bfs(i);
		
	printf("%d", color[0]);
	for(int i=1; i<n; ++i)	printf(" %d", (color[i] == 0) ? 1 : color[i]);
	puts("");

	return 0;
}
