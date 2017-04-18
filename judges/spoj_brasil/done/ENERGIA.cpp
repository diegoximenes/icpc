#include<cstdio>
#include<vector>
using namespace std;

#define MAX 105

bool mark[MAX];
int n, m;
vector<int> g[MAX];

void dfs(int v)
{
	mark[v] = 1;
	for(int i=0; i<(int)g[v].size(); ++i)
	{
		int u = g[v][i];
		if(!mark[u]) dfs(u);
	}
}

int main()
{
	for(int tc=1; scanf("%d %d", &n, &m) && n; ++tc)
	{
		for(int i=0; i<n; ++i)
		{
			mark[i] = 0;
			g[i].clear();
		}

		while(m--)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		dfs(0);
		
		bool fail = 0;
		for(int i=0; i<n; ++i)
			if(mark[i] == 0)
			{
				fail = 1;
				break;
			}
		printf("Teste %d\n", tc);
		if(fail) puts("falha\n");
		else puts("normal\n");
	}

	return 0;
}

