#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

#define INF (int) 1e9
#define MAX 100

vector< vector<int> > g;
int cap[MAX][MAX], flow[MAX][MAX], pred[MAX];
int n; //number of vertices

bool bfs(int s, int t)
{
	int u, v;
	bool mark[MAX];
	queue<int> f;
	
	memset(mark, 0, sizeof(mark));
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
	
	for(int i=0; i<MAX; ++i)
		for(int j=0; j<MAX; ++j)
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
	int s = 10, t = 11, count = 0;;
	char a, c, ch;
	vector<int> ve;
	
	n = MAX;
	ve.clear();
	g.assign(MAX, ve);
	for(int i=0; i<MAX; ++i)
		for(int j=0; j<MAX; ++j)
			cap[i][j] = 0;
	for(int i=0; i<10; ++i)
	{
		g[i].push_back(t);
		cap[i][t] = 1;
	}
	
	while(1)
	{
		bool flag = 0;
		if(scanf("%c", &a) == EOF)
			flag = 1;
		if((a == '\n') || flag)
		{
			if(fordfulkerson(s, t) != count)
				puts("!");
			else
			{
				for(int i=0; i<10; ++i)
				{
					for(ch='A'; ch<='Z'; ++ch)
						if(flow[i][(int)ch] == -1)
						{
							printf("%c", ch);
							break;
						}
					if(ch == 'Z' + 1)
						printf("_");
				}
				puts("");
			}
			
			if(flag)
				break;
			
			count = 0;
			g.clear();
			g.assign(MAX, ve);
			for(int i=0; i<MAX; ++i)
				for(int j=0; j<MAX; ++j)
					cap[i][j] = 0;
			for(int i=0; i<10; ++i)
			{
				g[i].push_back(t);
				cap[i][t] = 1;
			}
		}
		else
		{
			scanf("%d%*c", &n);
			cap[s][(int)a] = n;
			g[s].push_back(a);
			
			count += n;
			
			while(scanf("%c", &c) && (c != ';'))
			{
				cap[(int)a][c-'0'] = 1;
				g[a].push_back(c-'0');
				g[c-'0'].push_back(a);
			}
			getchar();
		}
	}
	
	return 0;
}