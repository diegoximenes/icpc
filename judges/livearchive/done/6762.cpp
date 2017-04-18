#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
#define INF 10000000000
#define MAX 1005

ll g[MAX][MAX], cum[MAX][MAX];

int main()
{
	int t, n, m;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=m; ++j) 
				scanf("%lld", &g[i][j]);
		
		memset(cum, 0, sizeof(cum));
		ll sol = -INF;
		for(int i=n; i>=1; --i)
			for(int j=m; j>=1; --j)
			{
				cum[i][j] = cum[i][j+1] + cum[i+1][j] - cum[i+1][j+1] + g[i][j];
				sol = max(sol, cum[i][j]);
			}
		printf("%lld\n", sol);
	}

	return 0;
}
