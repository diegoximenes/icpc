#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAX 1010
#define MAXE 10010
#define INF (int) 1e9
#define pb push_back
#define mp make_pair

int n, m, bases, sx, sy, tx, ty, tc, l, r, mid, dist[MAX][MAX];
pair<int, int> enemy[MAXE], s, t;
bool mark[MAX][MAX], g[MAX][MAX];

inline int distance(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

inline bool can(int i, int j)
{
	if(i>=0 && i<n && j>=0 && j<m) return 1;
	return 0;
}

inline int bfs(int d)
{
	queue< pair<int, int> > q;
	memset(mark, 0, sizeof(mark));
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			dist[i][j] = INF;
	q.push(s); dist[s.first][s.second] = 0; mark[s.first][s.second] = 1;

	while(!q.empty())
	{
		pair<int, int> v = q.front(); q.pop();
		if(v == t) break;

		for(int i=-1; i<=1; ++i)
			for(int j=-1; j<=1; ++j)
				if(abs(i) + abs(j) == 1)
				{
					int ni = v.first + i, nj = v.second + j;
					if(can(ni, nj) && !g[ni][nj] && !mark[ni][nj])
					{
						mark[ni][nj] = 1;
						dist[ni][nj] = dist[v.first][v.second] + 1;
						q.push(mp(ni, nj));
					}
				}
	}
		
	return dist[t.first][t.second];
}

inline void updateGraph(int d)
{
	int ni, nj;
	memset(g, 0, sizeof(g));
	
	for(int i=0; i<bases; ++i)
	{
		g[enemy[i].first][enemy[i].second] = 1;
		for(int j=0; j<d; ++j)
			{
				ni = enemy[i].first + j; nj = enemy[i].second + d - j - 1;
				if(can(ni, nj)) g[ni][nj] = 1;

				ni = enemy[i].first - j; nj = enemy[i].second + d - j - 1;
				if(can(ni, nj)) g[ni][nj] = 1;
				
				ni = enemy[i].first + j; nj = enemy[i].second - (d - j - 1);
				if(can(ni, nj)) g[ni][nj] = 1;
				
				ni = enemy[i].first - j; nj = enemy[i].second - (d - j - 1);
				if(can(ni, nj)) g[ni][nj] = 1;
			}
	}
}

int main()
{
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d %d %d %d %d %d %d", &bases, &n, &m, &sx, &sy, &tx, &ty);
		s = mp(sx, sy); t = mp(tx, ty); r = INF;
		for(int i=0; i<bases; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			enemy[i] = mp(x, y);
			r = min(min(r, distance(enemy[i].first, enemy[i].second, s.first, s.second)), distance(enemy[i].first, enemy[i].second, t.first, t.second));
		}
		
		int dist, solDist, solD, solved = 0 ;
		l = 1;
		while(l <= r)
		{
			mid = (l + r)/2;
			updateGraph(mid);
			dist = bfs(mid);
			if(dist < INF)
			{
				l = mid + 1;
				solDist = dist; solD = mid;
				solved = 1;
			}
			else r = mid - 1;
		}

		if(solved) printf("%d %d\n", solD, solDist);
		else printf("%d %d\n", 0, distance(s.first, s.second, t.first, t.second));
	}

	return 0;
}
