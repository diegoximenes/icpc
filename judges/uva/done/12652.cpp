#include<cstdio>
#include<utility>
using namespace std;

#define MAX 305
#define mp make_pair

pair<int, int> rightPos[MAX*MAX], pos[MAX*MAX];
int g[MAX][MAX];
bool canChangeRow[MAX], canChangeCol[MAX];

int main()
{
	int n, m;
			
	while(scanf("%d %d", &n, &m) == 2)
	{
		int k = 1;
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				rightPos[k++] = mp(i, j);

		for(int i=0; i<n; ++i) canChangeRow[i] = 1;
		for(int i=0; i<m; ++i) canChangeCol[i] = 1;
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
			{
				scanf("%d", &g[i][j]);
				pos[g[i][j]] = mp(i, j);
			}
		
		bool can = 1;
		int upper = n*m, moves = 0;
		for(int i=1; can && i<=upper; ++i)
		{
			//printf("i= %d, pos[i]= (%d, %d)\n", i, pos[i].first, pos[i].second);
			int xactual = pos[i].first, xright = rightPos[i].first, yactual = pos[i].second, yright = rightPos[i].second;
			if(xactual != xright)
			{
				if(!canChangeRow[xright])
				{
					can = 0;
					break;
				}
				for(int j=0; j<m; ++j)
				{
					//printf("%d\n", g[xactual][j]);
					pos[g[xactual][j]].first = xright;
					pos[g[xright][j]].first = xactual;
					swap(g[xactual][j], g[xright][j]);
				}
				++moves;
				canChangeRow[xright] = 0;
			}
			if(yactual != yright)
			{
				if(!canChangeCol[yright])
				{
					can = 0;
					break;
				}
				for(int j=0; j<n; ++j)
				{
					pos[g[j][yactual]].second = yright;
					pos[g[j][yright]].second = yactual;
					swap(g[j][yactual], g[j][yright]);
				}
				++moves;
				canChangeCol[yright] = 0;
			}
		}

		if(!can) puts("*");
		else printf("%d\n", moves);
	}

	return 0;
}
