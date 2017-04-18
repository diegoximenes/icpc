#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 2005

bool cycle;
int n, m, dist[MAX][MAX], mark[MAX][MAX];
char g[MAX][MAX];
pair<int, int> last[MAX][MAX];

pair<int, int> move(int i, int j)
{
	if(g[i][j] == '>') return mp(i, j+1);
	if(g[i][j] == '<') return mp(i, j-1);
	if(g[i][j] == 'v') return mp(i+1, j);
	if(g[i][j] == '^') return mp(i-1, j);
	return mp(0, 0);
}

void dfs(int i, int j, int curSet)
{
	if(mark[i][j] == curSet) cycle = 1;
	else if(mark[i][j]) return;
	else
	{
		mark[i][j] = curSet;
		pair<int, int> p = move(i, j);
		if(p != mp(0, 0))
		{
			int ni = p.first, nj = p.second;
			
			dfs(ni, nj, curSet);
			dist[i][j] = 1 + dist[ni][nj];

			if(g[ni][nj] == '#') last[i][j] = mp(i, j);
			else last[i][j] = last[ni][nj];
		}
		else dist[i][j] = 0;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i) scanf(" %s", g[i]);
	
	cycle = 0; memset(mark, 0, sizeof(mark));
	int maxdist = 0, curSet = 1;
	for(int i=0; !cycle && i<n; ++i)
		for(int j=0; !cycle && j<m; ++j)
			if(!mark[i][j])
				dfs(i, j, curSet++), maxdist = max(maxdist, dist[i][j]);
	
	if(cycle) puts("-1");
	else if(maxdist == 0) puts("0");
	else
	{
		int sol = maxdist*2 - 1;

		vector< pair<int, int> > v;
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				if(dist[i][j] == maxdist)
					v.pb(mp(i, j));
		
		bool solved = 0;
		for(int i=0; !solved && i<(int)v.size(); ++i)
			for(int j=i+1; !solved && j<(int)v.size(); ++j)
				if(last[v[i].first][v[i].second] != last[v[j].first][v[j].second])
					solved = 1, sol = maxdist*2;

		printf("%d\n", sol);
	}

	return 0;
}
