#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 1e9
#define MAXQ 1005
#define MAXN 205

int v[MAXQ], cnt[MAXN], cost[MAXN][MAXN], dp[2][MAXN][MAXN], n, q;

/*int opt(int i, int l1, int l2)
{
	if(l1 == l2 || (i != 0 && (l1 == v[i-1] || l2 == v[i-1]))) return INF;
	if(i == q) return 0;
	int &state = dp[i][l1][l2];
	if(state != -1) return state;
	
	int sol1;
	if(i == 0) sol1 = cost[0][v[i]] + opt(i+1, l1, l2);
	else sol1 = cost[v[i-1]][v[i]] + opt(i+1, l1, l2);
	int sol2 = cost[l1][v[i]] + opt(i+1, v[i-1], l2);
	int sol3 = cost[l2][v[i]] + opt(i+1, l1, v[i-1]);
	
	return state = min(sol1, min(sol2, sol3));
}*/

int main()
{
	int t;

	scanf("%d", &t);
	while(t--)
	{
		memset(cnt, 0, sizeof(cnt));

		scanf("%d %d", &n, &q);
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				scanf("%d", &cost[i][j]);
		for(int i=0; i<q; ++i) scanf("%d", &v[i]), --v[i];

		/*memset(dp, -1, sizeof(dp));
		printf("%d\n", opt(0, 1, 2));*/
		
		for(int j=0; j<n; ++j)
			for(int k=0; k<n; ++k)
				dp[q%2][j][k] = 0;
		for(int i=q-1; i>=0; --i)
			for(int l1=0; l1<n; ++l1)
				for(int l2=0; l2<n; ++l2)
				{
					if((i == 0) && (l1 == 0 || l2 == 0 || l1 == l2))
					{
						dp[i%2][l1][l2] = INF;
						continue;
					}
					if((i != 0) && (l1 == v[i-1] || l2 == v[i-1] || l1 == l2)) 
					{ 
						dp[i%2][l1][l2] = INF; 
						continue;
					}
					
					int sol1;
					if(i == 0) sol1 = cost[0][v[i]] + dp[(i+1)%2][l1][l2];
					else sol1 = cost[v[i-1]][v[i]] + dp[(i+1)%2][l1][l2];
					int sol2 = cost[l1][v[i]] + dp[(i+1)%2][v[i-1]][l2];
					int sol3 = cost[l2][v[i]] + dp[(i+1)%2][l1][v[i-1]];
						
					dp[i%2][l1][l2] = min(sol1, min(sol2, sol3));
				}
		
		printf("%d\n", dp[0][1][2]);
	}

	return 0;
}
