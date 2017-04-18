#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
using namespace std;

#define mp make_pair

#define MAX 105
#define INF 1e9

int main()
{
	int test, n, m, q, u, v, w, dist[MAX][MAX]; 
	char s[25], s2[25];
	map<string, int> dic;
	vector< pair<int, int> > g[MAX];
	
	scanf("%d", &test);
	for(int t=1; t<=test; ++t)
	{
		dic.clear();

		scanf("%d", &n);
		for(int i=0; i<n; ++i)
		{
			g[i].clear();
			scanf("%s", s);
			dic[s] = i;
		}
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s %s %d", s, s2, &w);
			u = dic[s]; v = dic[s2];
			g[v].push_back(mp(u, w));
		}
		
		for(int i=0; i<n; ++i)
			dist[i][0] = INF;
		dist[0][0] = 0;
		for(int i=1; i<n; ++i)
			for(int v=0; v<n; ++v)
			{
				dist[v][i] = dist[v][i-1];
				for(int j=0; j<(int)g[v].size(); ++j)
					dist[v][i] = min(dist[v][i], dist[g[v][j].first][i-1] + g[v][j].second);
			}
		
		printf("Scenario #%d\n", t);
		scanf("%d", &q);
		while(q--)
		{
			int ne;
			scanf("%d", &ne);
			if(ne >= n-1)
				ne = n-2;
			else if(ne < 0)
				ne = 0;
			if(dist[n-1][ne+1] == INF)
				puts("No satisfactory flights");
			else
				printf("Total cost of flight(s) is $%d\n", dist[n-1][ne+1]);
		}
		if(t!=test)
			puts("");
	}
	
	
	return 0;
}