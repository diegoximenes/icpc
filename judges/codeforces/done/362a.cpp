#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 10

bool visited[MAX][MAX][MAX][MAX];
int dp[MAX][MAX][MAX][MAX];
char g[MAX][MAX];
const int move[4][2] = {{2, 2}, {2, -2}, {-2, 2}, {-2, -2}};

inline bool can(int i, int j)
{
	if(i>=0 && i<8 && j>=0 && j<8) return 1;
	return 0;
}

int solve(int x1, int y1, int x2, int y2)
{
	visited[x1][y1][x2][y2] = 1;
	if(dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
	if(x1 == x2 && y1 == y2 && g[x1][y1] != '#') return dp[x1][y1][x2][y2] = 1;
	
	int sol = 0;
	for(int i=0; i<4; ++i)
		for(int j=0; j<4; ++j)
		{
			int nx1 = x1 + move[i][0], ny1 = y1 + move[i][1];
			int nx2 = x2 + move[j][0], ny2 = y2 + move[j][1];
			if(can(nx1, ny1) && can(nx2, ny2) && !visited[nx1][ny1][nx2][ny2])
			{
				int sol = solve(nx1, ny1, nx2, ny2);
				if(sol) return dp[x1][y1][x2][y2] = sol;
			}
		}
	return dp[x1][y1][x2][y2] = sol;
}

int main()
{
	int t, x1, x2, y1, y2;

	scanf("%d", &t);
	while(t--)
	{
		bool first = 1;
		for(int i=0; i<8; ++i)
		{
			scanf(" %s", g[i]);
			for(int j=0; j<8; ++j)
				if(g[i][j] == 'K')
				{
					if(first)
					{
						x1 = i; y1 = j;
					}
					else
					{
						x2 = i; y2 = j;
					}
					first = 0;
				}
		}

		memset(dp, -1, sizeof(dp));
		memset(visited, 0, sizeof(visited));
		if(solve(x1, y1, x2, y2)) puts("YES");
		else puts("NO");
	}
	

	return 0;
}
