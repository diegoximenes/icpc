#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define WHITE -1

int dfscount, root, rootchildren;
vector< vector<int> > g;
vector< pair<int, int> > bridge;
vector<int> low, num, par, art;

void articulation(int u)
{
	int v;
	
	low[u] = num[u] = dfscount++;
	
	for(int j=0; j<(int)g[u].size(); ++j)
	{
		v = g[u][j];
		
		if(num[v] == WHITE)
		{
			par[v] = u;
			
			if(u == root)
				rootchildren++;
			
			articulation(v);
			
			if(low[v] >= num[u])
				art[u] = 1;
			if(low[v] > num[u])
				bridge.push_back(make_pair(min(u, v), max(u, v)));
			low[u] = min(low[u], low[v]);
		}
		else if(v != par[u])
			low[u] = min(low[u], num[v]);
	}
}

int main()
{
	int n, u, v, m;
	vector<int> ve;
	
	ve.clear();
	
	while(scanf("%d", &n) != EOF)
	{
		g.assign(n, ve);
		bridge.clear();
		
		for(int i=0; i<n; ++i)
		{
			scanf("%d (%d)", &v, &m);

			while(m--)
			{
				scanf("%d", &u);
				
				g[v].push_back(u);
				g[u].push_back(v);
			}
		}
		
		dfscount = 0;
		num.assign(n, WHITE);
		low.assign(n, 0);
		par.assign(n, 0);
		art.assign(n, 0);
		
		for(int i=0; i<n; ++i)
		{
			if(num[i] == WHITE)
			{
				root = i;
				rootchildren = 0;
				articulation(i);
				art[root] = (rootchildren > 1);
			}
		}
		
		sort(bridge.begin(), bridge.end());
		
		printf("%d critical links\n", (int)bridge.size());
		for(int i=0; i<(int)bridge.size(); ++i)
			printf("%d - %d\n", bridge[i].first, bridge[i].second);
		puts("");
	}
	
	return 0;
}