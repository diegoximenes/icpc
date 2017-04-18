#include<cstdio>
#include<cctype>
#include<queue>
using namespace std;

#define MAX 12
#define INF 1e9
#define MOD 20437
#define mp make_pair

char g[MAX][MAX];
int dist[MAX][MAX], countLetter, n;
long long int path[MAX][MAX];
bool mark[MAX][MAX];
pair<int, int> letter[30];

bool can(int i, int j)
{
	if(i<0 || i>=n || j<0 || j>=n || g[i][j]=='#')
		return 0;
	return 1;
}

int countPath(pair<int, int> s, pair<int, int> t)
{
	int delta[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int si = s.first, sj = s.second, ti = t.first, tj = t.second;
	queue< pair<int, int> > q;
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
		{
			path[i][j] = 0;
			mark[i][j] = 0;
			dist[i][j] = INF;
		}
	mark[si][sj] = 1;
	path[si][sj] = 1;
	dist[si][sj] = 0;
	q.push(mp(si, sj));
	while(!q.empty())
	{
		int vi = q.front().first, vj = q.front().second;
		q.pop();
		if(vi == ti && vj == tj)
			continue;
		
		for(int i=0; i<4; ++i)
		{
			int ui = delta[i][0] + vi, uj = delta[i][1] + vj;
			if(can(ui, uj) && !mark[ui][uj])
			{
				if(isalpha(g[ui][uj]) && g[ui][uj] != g[ti][tj])
					continue;

				dist[ui][uj] = dist[vi][vj] + 1;
				mark[ui][uj] = 1;
				path[ui][uj] += path[vi][vj];
				
				q.push(mp(ui, uj));
			}
			else if(can(ui, uj) && mark[ui][uj] && dist[ui][uj] == dist[vi][vj]+1)
				path[ui][uj] += path[vi][vj];
		}
	}
	
	return path[ti][tj];
}

int main()
{
	char line[10];
	
	for(int t=1; scanf("%d", &n) && n; ++t)
	{	
		countLetter = 0;
		gets(line);
		for(int i=0; i<n; ++i, gets(line))
			for(int j=0; j<n; ++j)
			{
				g[i][j] = getchar();
				if(isalpha(g[i][j]))
				{
					letter[g[i][j] - 'A'] = mp(i, j);
					++countLetter;
				}
					
			}
		
		int d = 0;
		long long int count = 1;
		for(int i=1; i<countLetter; ++i)
		{
			count *= countPath(letter[i-1], letter[i]);
			count %= MOD;
			g[letter[i-1].first][letter[i-1].second] = g[letter[i].first][letter[i].second] = '.';
			//printf("count= %lld, i= %d, letter[i-1].first= %d, letter[i-1].second= %d, letter[i].first= %d, letter[i].second=%d, dist[letter[i].first][letter[i].second]= %d\n", count, i, letter[i-1].first, letter[i-1].second, letter[i].first, letter[i].second, dist[letter[i].first][letter[i].second]);
			d += dist[letter[i].first][letter[i].second];
		}
		
		printf("Case %d: ", t);
		if(!count)
			puts("Impossible");
		else
			printf("%d %lld\n", d, count);
	}
	
	return 0;
}