#include<cstdio>
using namespace std;

#define MAX 110

int n, m;

bool in(int i, int j)
{
	if(i<n && j<m && i>=0 && j>=0)
		return 1;
	return 0;
}

int main()
{
	int s, iini, jini, i, j, count;
	char g[MAX][MAX], d;
	
	while(scanf("%d %d %d", &n, &m, &s) && n)
	{
		count = 0;
		
		getchar();
		for(i=0; i<n; ++i)
		{
			for(j=0; j<m; ++j)
			{
				scanf("%c", &g[i][j]);
				if((g[i][j] == 'N') || (g[i][j] == 'S') || (g[i][j] == 'L') || (g[i][j] == 'O'))
				{
					iini = i; jini = j;
				}
			}
			getchar();
		}
		i = iini, j = jini; d = g[i][j];
		for(int k=0; k<s; ++k)
		{
			char inst;
			scanf("%c", &inst);
			if(inst == 'D')
			{
				if(d == 'N')
					d = 'L';
				else if(d == 'O')
					d = 'N';
				else if(d == 'S')
					d = 'O';
				else if(d == 'L')
					d = 'S';
			}
			else if(inst == 'E')
			{
				if(d == 'N')
					d = 'O';
				else if(d == 'O')
					d = 'S';
				else if(d == 'S')
					d = 'L';
				else if(d == 'L')
					d = 'N';
			}
			else 
			{
				if((d == 'N') && in(i-1, j) && g[i-1][j] != '#')
					--i;
				else if((d == 'S') && in(i+1, j) && g[i+1][j] != '#')
					++i;
				else if((d == 'L') && in(i, j+1) && g[i][j+1] != '#')
					++j;
				else if((d == 'O') && in(i, j-1) && g[i][j-1] != '#')
					--j;
			}
			
			if(g[i][j] == '*')
				++count;
			g[i][j] = '.';
		}
		
		printf("%d\n", count);
	}
	
	return 0;
}