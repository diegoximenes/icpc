#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

#define pb push_back
#define mp make_pair
#define INF 1e9
#define MAX 55

char g[MAX][MAX];
int dist[MAX][MAX], n, m;
bool mark[MAX][MAX];
const int neigh[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline bool can(int i, int j)
{
	if(i >= 0 && i < n && j >= 0 && j < m) return 1;
	return 0;
}

int main()
{
	int t;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		
		int cntPizzas = 0;
		pair<int, int> s;
		for(int i=0; i<n; ++i) 
		{
			scanf(" %s ", g[i]);
			for(int j=0; j<m; ++j)
			{
				if(g[i][j] == 'X') s = mp(i, j);
				if(g[i][j] == '$') cntPizzas++;
				dist[i][j] = INF;
				mark[i][j] = 0;
			}
		}
		
		vector<int> distBuilding;
		set< pair<int, pair<int, int> > > heap;
		dist[s.first][s.second] = 0;
		heap.insert(mp(0, s));
		while(!heap.empty())
		{
			pair<int, int> u = heap.begin()->second;
			heap.erase(heap.begin());
			mark[u.first][u.second] = 1;
			
			if(g[u.first][u.second] == '$') distBuilding.pb(dist[u.first][u.second]);
			
			//printf("u= (%d, %d), dist= %d\n", u.first, u.second, dist[u.first][u.second]);

			for(int i=0; i<4; ++i)
			{
				int i2 = u.first + neigh[i][0], j2 = u.second + neigh[i][1];
				if(can(i2, j2) && !mark[i2][j2])
				{
					int auxDist = INF;
					if(g[u.first][u.second] == '$' || g[i2][j2] == '$' || g[u.first][u.second] == 'X' || g[i2][j2] == 'X') auxDist = 2;
					else if(abs(g[u.first][u.second] - g[i2][j2]) == 0) auxDist = 1;
					else if(abs(g[u.first][u.second] - g[i2][j2]) == 1) auxDist = 3;

					if(dist[i2][j2] > dist[u.first][u.second] + auxDist)
					{
						heap.erase(mp(dist[i2][j2], mp(i2, j2)));
						dist[i2][j2] = dist[u.first][u.second] + auxDist;
						heap.insert(mp(dist[i2][j2], mp(i2, j2)));
					}

					//printf("i2= %d, j2= %d, auxDist= %d\n", i2, j2, auxDist);
				}
			}
		}
		
		if(cntPizzas != (int)distBuilding.size()) puts("-1");
		else
		{
			sort(distBuilding.begin(), distBuilding.end());
			int upper = (1 << (int)distBuilding.size()), sol = INF;
			for(int i=0; i<upper; ++i)
			{
				int sum1 = 0, sum2 = 0, last1 = 0, last2 = 0;
				for(int j=0; j<(int)distBuilding.size(); ++j)
				{
					if(i & (1 << j)) sum1 += 2*distBuilding[j], last1 = distBuilding[j];
					else sum2 += 2*distBuilding[j], last2 = distBuilding[j];
				}
				sol = min(sol, max(sum1 - last1, sum2 - last2));
			}

			printf("%d\n", sol);
		}
	}

	return 0;
}
