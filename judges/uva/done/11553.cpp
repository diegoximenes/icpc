#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 10
#define MAX2 300
#define INF (int) 1e9

int n, g[MAX][MAX], dp[MAX2][MAX2];

int opt(int maski, int maskj)
{	
	if(maski == (1 << n) - 1) return 0;
	if(dp[maski][maskj] != -1) return dp[maski][maskj];
	
	int soli = -INF;
	for(int i=0; i<n; ++i)
		if(!(maski & (1 << i)))
		{
			int solj = INF;
			for(int j=0; j<n; ++j)
				if(!(maskj & (1 << j)))
					solj = min(solj, g[i][j] + opt(maski | (1 << i), maskj | (1 << j)));
			soli = max(soli, solj);
		}
	
	return dp[maski][maskj] = soli;
}

int main()
{
	int t;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				scanf("%d", &g[i][j]);

		memset(dp, -1, sizeof(dp));
		printf("%d\n", opt(0, 0));

	}

	return 0;
}
