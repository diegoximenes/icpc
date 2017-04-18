#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 105
#define INF 0x3f3f3f3f

int cumRow[MAX][MAX], sum[MAX], g[MAX][MAX];

int main()
{
	int n;
	
	scanf("%d", &n);
	memset(cumRow, 0, sizeof(cumRow));
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
		{
			scanf("%d", &g[i][j]);
			cumRow[i][j] = cumRow[i][j-1] + g[i][j];
		}
	
	int sol = -INF;
	for(int j=1; j<=n; ++j)
		for(int j2=j; j2<=n; ++j2)
		{
			sum[0] = 0;
			for(int i=1; i<=n; ++i)
			{
				int aux = cumRow[i][j2] - cumRow[i][j-1];
				sum[i] = max(sum[i-1] + aux, aux);
				sol = max(sol, sum[i]);
			}

		}
			
	printf("%d\n", sol);
	
	return 0;
}
