#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF (int) 1e9
#define MAX 8
#define EMPTY -2
#define LAMP -3
#define ILUMINATED -4
#define BLOCK -1

int n, m, b, g[MAX][MAX];
const int neigh[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline int can(int i, int j)
{
	if(i>=0 && i<n && j>=0 && j<m) return 1;
	return 0;
}

inline bool fill(int i, int j)
{
	bool r = 1;
	for(int k=i-1; k>=0 && g[k][j] < -1; --k)
	{
		if(g[k][j] == LAMP){ r = 0; break; }
		g[k][j] = ILUMINATED;
	}
	for(int k=i+1; k<n && g[k][j] < -1; ++k)
	{
		if(g[k][j] == LAMP){ r = 0; break; }
		g[k][j] = ILUMINATED;
	}
	for(int k=j-1; k>=0 && g[i][k] < -1; --k)
	{
		if(g[i][k] == LAMP){ r = 0; break; }
		g[i][k] = ILUMINATED;
	}
	for(int k=j+1; k<m && g[i][k] < -1; ++k)
	{
		if(g[i][k] == LAMP){ r = 0; break; }
		g[i][k] = ILUMINATED;
	}
	return r;
}

int solve(int i, int j)
{
	int line[MAX], column[MAX];

	if(j == m) ++i, j = 0;
	if(i == n)
	{
		for(int k=0; k<n; ++k)
			for(int l=0; l<m; ++l)
			{
				if(g[k][l] == EMPTY) return INF;
				if(g[k][l] >= 0) 
				{
					int count = 0;
					for(int p=0; p<4; ++p)
					{
						int nk = k + neigh[p][0], nl = l + neigh[p][1];
						if(can(nk, nl) && g[nk][nl] == LAMP) ++count;
					}
					if(count != g[k][l]) return INF;
				}
			}
		return 0;
	}
	
	if(g[i][j] == ILUMINATED || g[i][j] == BLOCK || g[i][j] >= 0) return solve(i, j+1);
	
	int sol1 = solve(i, j+1);
	
	for(int k=0; k<n; ++k) column[k] = g[k][j];
	for(int k=0; k<m; ++k) line[k] = g[i][k];

	g[i][j] = LAMP;
	if(!fill(i, j)) 
	{
		for(int k=0; k<n; ++k) g[k][j] = column[k];
		for(int k=0; k<m; ++k) g[i][k] = line[k];
		return sol1;
	}
	int sol2 = 1 + solve(i, j+1);
	for(int k=0; k<n; ++k) g[k][j] = column[k];
	for(int k=0; k<m; ++k) g[i][k] = line[k];
	g[i][j] = EMPTY;
			
	return min(sol1, sol2);
}

int main()
{
	while(scanf("%d %d %d", &n, &m, &b) && n)
	{
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				g[i][j] = EMPTY;
		while(b--)
		{
			int x, y, nb;
			scanf("%d %d %d", &x, &y, &nb);
			--x; --y;
			g[x][y] = nb;
		}

		int sol = solve(0, 0);
		if(sol == INF) puts("No solution");
		else printf("%d\n", sol);
	}

	return 0;
}
