#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

#define MAX 510
#define pb push_back

int main()
{
	int tc, pos[MAX], n, m, u, v, deg[MAX];
	bool g[MAX][MAX];

	scanf("%d", &tc);
	while(tc--)
	{
		memset(g, 0, sizeof(g));
		
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
		{
			scanf("%d", &pos[i]);
			--pos[i];
		}
		for(int i=0; i<n; ++i)
			for(int j=i+1; j<n; ++j)
				g[pos[i]][pos[j]] = 1;

		scanf("%d", &m);
		while(m--)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			if(g[u][v]) 
			{
				g[u][v] = 0;
				g[v][u] = 1;
			}
			else
			{
				g[v][u] = 0;
				g[u][v] = 1;
			}
		}
		
		memset(deg, 0, sizeof(deg));
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				if(g[i][j])
					++deg[j];
		queue<int> q;
		for(int i=0; i<n; ++i)
			if(!deg[i])
				q.push(i);
		vector<int> sol;
		while(!q.empty())
		{
			v = q.front(); q.pop();
			sol.pb(v);
			for(int u=0; u<n; ++u)
				if(g[v][u])
				{
					--deg[u];
					if(!deg[u]) q.push(u);
				}
		}

		if((int)sol.size() != n) puts("IMPOSSIBLE");
		else
		{
			printf("%d", sol[0] + 1);
			for(int i=1; i<(int)sol.size(); ++i) printf(" %d", sol[i] + 1);
			puts("");
		}
	}

	return 0;
}
