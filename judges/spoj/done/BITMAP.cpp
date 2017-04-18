#include<cstdio>
#include<queue>
using namespace std;

#define MAX 200
#define INF 1e9

#define mp make_pair

int n, m;

inline int can(int i, int j)
{
	if(i>=0 && i<n && j>=0 && j<m)
		return 1;
	return 0;
}

int main()
{
	int t, dist[MAX][MAX];
	pair<int, int> delta[4] = {mp(-1, 0), mp(1, 0), mp(0, -1), mp(0, 1)};
	char line[MAX+20], g[MAX][MAX];
	bool mark[MAX][MAX];

	gets(line);
	sscanf(line, "%d", &t);
	while(t--)
	{
		gets(line);
		sscanf(line, "%d %d", &n, &m);

		queue< pair<int, int> > q;
		for(int i=0; i<n; ++i, gets(line))
			for(int j=0; j<m; ++j)
			{
				dist[i][j] = INF;
				mark[i][j] = 0;
				scanf("%c", &g[i][j]);
				if(g[i][j] == '1')
				{
					q.push(mp(i, j));
					dist[i][j] = 0;
					mark[i][j] = 1;
				}
			}
		while(!q.empty())
		{
			pair<int, int> p = q.front(); q.pop();

			for(int k=0; k<4; ++k)
			{
				int i = p.first + delta[k].first, j = p.second + delta[k].second;
				if(can(i, j) && !mark[i][j])
				{
					q.push(mp(i, j));
					dist[i][j] = dist[p.first][p.second] + 1;
					mark[i][j] = 1;
				}
			}
		}
		
		for(int i=0; i<n; ++i, puts(""))
		{
			printf("%d", dist[i][0]);
			for(int j=1; j<m; ++j)
				printf(" %d", dist[i][j]);
		}
		gets(line);
    }

	return 0;
}
