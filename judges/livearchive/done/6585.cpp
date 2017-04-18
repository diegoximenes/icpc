#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 15

char g[MAX][MAX];
const int neigh[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

inline bool can(int i, int j)
{
	if(i>=0 && i<10 && j>=0 && j<10) return 1;
	return 0;
}

int move(int i, int j)
{
	int sol = 0;
	for(int k=0; k<4; ++k)
	{
		int ni = i + neigh[k][0], nj = j + neigh[k][1];
		if(can(ni, nj) && g[ni][nj] == 'B')
		{
			int nni = ni + neigh[k][0], nnj = nj + neigh[k][1];
			if(can(nni, nnj) && g[nni][nnj] == '#')
			{
				g[ni][nj] = '#';
				sol = max(sol, 1 + move(nni, nnj));
				g[ni][nj] = 'B';
			}
		}
	}
	return sol;
}

int main()
{
	int t;

	scanf("%d", &t);
	gets(g[0]);
	while(t--)
	{
		gets(g[0]);
		for(int i=0; i<10; ++i) gets(g[i]);
		
		int best = 0;
		for(int i=0; i<10; ++i)
			for(int j=0; j<10; ++j)
				if(g[i][j] == 'W')
				{
					g[i][j] = '#';
					best = max(best, move(i, j));
					g[i][j] = 'W';
				}
		printf("%d\n", best);
	}

	return 0;
}
