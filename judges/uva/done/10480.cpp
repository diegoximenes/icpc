#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

#define INF (int) 1e9
#define MAX 60

vector< vector<int> > g;
int cap[MAX][MAX], flow[MAX][MAX], pred[MAX];
int n; //number of vertices

bool bfs(int s, int t)
{
	int u, v;
	bool mark[MAX], flag = 1;
	queue<int> f, f2;
	
	memset(mark, 0, n*sizeof(bool));
	f.push(s);
	pred[s] = -1;
	mark[s] = 1;
	
	while(!f.empty())
	{
		v = f.front();
		f.pop();
		
		f2.push(v);
		
		if(v == t)
			break;

		for(int i=0; i<(int)g[v].size(); ++i)
		{	
			u = g[v][i];
			if(!mark[u] && (cap[v][u] - flow[v][u] > 0))
			{
				f.push(u);
				mark[u] = 1;
				pred[u] = v;
			}
		}
	}
	
	if(!mark[t])
	{
		flag = 0;
		
		while(!f2.empty())
		{
			v = f2.front();
			f2.pop();
			
			for(int i=0; i<(int)g[v].size(); ++i)
			{
				u = g[v][i];
				
				if(!mark[u])
					printf("%d %d\n", v+1, u+1);
			}
		}
	}
	
	return flag;
}

int fordfulkerson(int s, int t)
{
	int maxflow = 0, inc, v;
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			flow[i][j] = 0;
	
	while(bfs(s, t))
	{
		inc = INF;
		
		for(v=t; pred[v]!=-1; v=pred[v])
			inc = min(inc, cap[pred[v]][v] - flow[pred[v]][v]);
		
		for(v=t; pred[v]!=-1; v=pred[v])
		{
			flow[pred[v]][v] += inc;
			flow[v][pred[v]] -= inc;
		}
		
		maxflow += inc;
	}
	
	return maxflow;
}

int main()
{
	int m, s = 0, t = 1, u, v, w;
	vector<int> ve;
	
	ve.clear();
	g.resize(MAX);
	
	while(scanf("%d %d", &n, &m) && n && m)
	{
		g.assign(n, ve);
		
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				cap[i][j] = 0;
		
		while(m--)
		{
			scanf("%d %d %d", &v, &u, &w);
			--u; --v;
			
			if(u!=t && v!=s)
			{
				g[u].push_back(v);
				cap[u][v] = w;
			}
			if(v!=t && u!=s)
			{
				g[v].push_back(u);
				cap[v][u] = w;
			}
		}
		
		fordfulkerson(s, t);
		
		puts("");
	}
	
	return 0;
}