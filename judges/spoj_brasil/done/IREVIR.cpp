#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MAX 2010
#define WHITE -1

vector< vector<int> > g;
vector<int> s;
int num[MAX], low[MAX], visited[MAX], dfscount, numscc;

void tarjan(int u)
{
	low[u] = num[u] = dfscount++;
	s.push_back(u);
	visited[u] = 1;
	for(int j=0; j<(int)g[u].size(); ++j)
	{
		int v = g[u][j];
		if(num[v] == WHITE)
			tarjan(v);
		if(visited[v])
			low[u] = min(low[u], low[v]);
	}
	
	if(low[u] == num[u])
	{
		++numscc;
		while(1)
		{
			int v = s.back(); s.pop_back(); visited[v] = 0;
			if(v == u)
				break;
		}
	}
}

int main()
{
	int n, m, u, v, op;
	vector<int> ve;
	
	ve.clear();
	
	while(scanf("%d %d", &n, &m) && n)
	{
		g.assign(n, ve);
		
		while(m--)
		{
			scanf("%d %d %d", &u, &v, &op);
			--u; --v;
			g[u].push_back(v);
			if(op == 2)
				g[v].push_back(u);
		}
		
		for(int i=0; i<n; ++i)
		{
			num[i] = WHITE;
			low[i] = visited[i] = 0;
		}
		dfscount = numscc = 0;
		for(int i=0; i<n; ++i)
		{
			//if(numscc > 1)
			//	break;
			if(num[i] == WHITE)
				tarjan(i);
		}
		
		//printf("numscc= %d\n", numscc);
		if(numscc != 1)
			puts("0");
		else
			puts("1");
	}
	
	return 0;
}