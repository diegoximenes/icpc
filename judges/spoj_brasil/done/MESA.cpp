#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

#define MAX 105
#define mp make_pair
#define pb push_back

int n, m, u, v, mark[MAX];
vector<int> g[MAX];

bool bfs(int s)
{
	queue<int> q;
	q.push(s); mark[s] = 1;
	while(!q.empty())
	{
		v = q.front(); q.pop();
		for(int i=0; i<(int)g[v].size(); ++i)
		{
			u = g[v][i];
			if(mark[u] != 0 && mark[u] == mark[v]) 
				return 0;
			if(!mark[u])
			{
				if(mark[v] == 1) mark[u] = 2;
				else mark[u] = 1;
				q.push(u);
			}
		}
	}
	return 1;
}

int main()
{
	for(int tc=1; scanf("%d %d", &n, &m) == 2; ++tc)
	{
		for(int i=0; i<n; ++i) g[i].clear();
		for(int i=0; i<m; ++i)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			g[u].pb(v); g[v].pb(u);
		}
		
		bool can = 1;
		memset(mark, 0, sizeof(mark));
		for(int i=0; i<n && can; ++i)
			if(!mark[i])
				can = bfs(i);
			
		printf("Instancia %d\n", tc);
		if(can) puts("sim\n");
		else puts("nao\n");
	}


	return 0;
}
