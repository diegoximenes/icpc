#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

#define INF (int) 1e9
#define MAX 110

vector< vector<int> > g;
int cap[MAX][MAX], flow[MAX][MAX], pred[MAX];
int n; //number of vertices

bool bfs(int s, int t)
{
	int u, v;
	bool mark[MAX];
	queue<int> f;
	
	memset(mark, 0, n*sizeof(bool));
	f.push(s);
	pred[s] = -1;
	mark[s] = 1;
	
	while(!f.empty())
	{
		v = f.front();
		f.pop();
		
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

	return mark[t];
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
	int s, t, m, u, v, w;
	vector<int> ve;
	
	g.resize(MAX);
	ve.clear();
	
	for(int k=1; scanf("%d", &n) && n; ++k)
	{
		g.assign(n, ve);
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				cap[i][j] = 0;
		
		scanf("%d %d %d", &s, &t, &m);
		--s; --t;
	
		while(m--)
		{
			scanf("%d %d %d", &u, &v, &w);
			--u; --v;
			
			if((v != s) && (u != t))
			{
				g[u].push_back(v);
				cap[u][v] += w;
			}
			if((u != s) && (v != t))
			{
				g[v].push_back(u);
				cap[v][u] += w;
			}
		}
		
		printf("Network %d\nThe bandwidth is %d.\n\n", k, fordfulkerson(s, t));
	}
	
	return 0;
}