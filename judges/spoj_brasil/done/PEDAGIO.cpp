#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define MAX 55

bool mark[MAX];
int n, m, s, p, u, v, dist[MAX];
vector<int> g[MAX];

int main()
{	
	for(int tc=1; scanf("%d %d %d %d", &n, &m, &s, &p) && n; ++tc)
	{
		--s;
		for(int i=0; i<n; ++i)
		{
			mark[i] = 0;
			g[i].clear();
		}

		while(m--)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		//bfs
		queue<int> q;
		dist[s] = 0;
		mark[s] = 1;
		q.push(s);
		while(!q.empty())
		{
			v = q.front(); q.pop();
			for(int i=0; i<(int)g[v].size(); ++i)
			{
				u = g[v][i];
				if(!mark[u])
				{
					dist[u] = dist[v] + 1;
					mark[u] = 1;
					q.push(u);
				}
			}
		}
		
		printf("Teste %d\n", tc);
		for(int i=0; i<n; ++i)
			if(i != s && mark[i] && dist[i] <= p)
				printf("%d ", i+1);
		printf("\n\n");
	}

	return 0;
}
