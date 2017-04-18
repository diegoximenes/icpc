#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MAX 60010
#define INF (int) 1e9
#define pb push_back

int n, m, q, vec[MAX], vec2[MAX], age[MAX], manager[MAX];
bool mark[MAX];
vector<int> g[MAX];

int dfs(int u)
{
	if(mark[u]) return manager[u];
	manager[u] = INF;
	mark[u] = 1;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		manager[u] = min(manager[u], min(age[vec2[v]], dfs(v)));
	}
	return manager[u];
}

int main()
{
	int u, v;
	char op;

	while(scanf("%d %d %d", &n, &m, &q) == 3)
	{
		for(int i=0; i<n; ++i) g[i].clear(), vec[i] = i, vec2[i] = i;

		for(int i=0; i<n; ++i) scanf("%d", &age[i]);
		while(m--)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			g[v].pb(u);
		}

		while(q--)
		{
			scanf(" %c %d", &op, &u);
			--u;
			if(op == 'T')
			{
				scanf("%d", &v);
				--v;
				swap(vec[u], vec[v]);
				vec2[vec[u]] = u; vec2[vec[v]] = v;
				//int aux = vec[u];
				//vec[u] = vec[vec[v]];
				//vec[v] = aux;
			}
			else
			{
				memset(mark, 0, sizeof(mark));
				int man = dfs(vec[u]);
				if(man == INF) puts("*");
				else printf("%d\n", man);
				//if(manager[vec[u]] == INF) puts("*");
				//else printf("%d\n", manager[vec[u]]);
			}
		}
	}

	return 0;
}
