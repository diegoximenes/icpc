#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 1e9
#define MOD 100
#define MAX 105

int sum[MAX][MAX], dp[MAX][MAX], v[MAX], n;

inline int cum(int i, int j)
{
	if(i >= n || j < 0) return 0;
	return sum[i][j];
}

int opt(int i, int j)
{
	if(j <= i) return 0;
	int &state = dp[i][j];
	if(state != -1) return state;

	int sol = INF;
	for(int k=i+1; k<=j; ++k)
	{
		sol = min(sol, cum(i, k-1)*cum(k, j) + opt(i, k-1) + opt(k, j));
		
		//printf("i= %d, j= %d, k= %d, sol1= %d, sol2= %d, auxsol= %d\n", i, j, k, sol1, sol2, auxsol);
		//printf("cum(i, k-1)= %d, cum(k, k+1)= %d, cum(i, k+1)= %d, cum(k+2, j)= %d, cum(k, j)= %d\n", cum(i, k-1), cum(k, k+1), cum(i, k+1), cum(k+2, j), cum(k, j));

	}
	return state = sol;
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		for(int i=0; i<n; ++i) scanf("%d", &v[i]);
				
		memset(sum, 0, sizeof(sum));
		for(int i=0; i<n; ++i)
			for(int j=i; j<n; ++j)
			{
				if(i == j) sum[i][j] = v[i];
				else sum[i][j] = (sum[i][j-1] + v[j])%MOD;

				//printf("i= %d, j= %d, sum= %d\n", i, j, sum[i][j]);
			}
		
		memset(dp, -1, sizeof(dp));
		printf("%d\n", opt(0, n-1));
	}

	return 0;
}
