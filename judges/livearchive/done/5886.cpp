#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 1005

char g[MAX][MAX], g2[MAX][MAX], m[MAX][MAX];

int main()
{
	int n;

	while(scanf("%d", &n) && n)
	{
		for(int i=0; i<n; ++i) scanf(" %s ", g[i]);
		for(int i=0; i<n; ++i) scanf(" %s ", m[i]);
		
		for(int k=0; k<4; ++k)
		{
			for(int i=0; i<n; ++i)
				for(int j=0; j<n; ++j)
					if(g[i][j] == 'O')
						putchar(m[i][j]);

			for(int i=0; i<n; ++i)
				for(int j=0; j<n; ++j)
					g2[j][n-i-1] = g[i][j];
			
			memcpy(g, g2, sizeof(g));
		}

		puts("");
	}

	return 0;
}
