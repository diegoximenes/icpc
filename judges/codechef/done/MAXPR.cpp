#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 250
#define MOD (int)(1e9 + 7)

int cnt[MAX][MAX], cntA[MAX], n, t, x;
const int offset = 101, maxa = 100;

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		memset(cntA, 0, sizeof(cntA));
		int sol = 1, all = 1;
		for(int i=0; i<n; ++i)
		{
			scanf("%d", &x);
			all = (all * 2)%MOD;
			
			for(int j=0; j<maxa; ++j) 
			{
				if(x - j >= 1)
				{
					cnt[x][j] = (cnt[x][j] + cnt[x - j][j])%MOD;
					cnt[x][j] = (cnt[x][j] + cntA[x - j])%MOD;
				}
				if(j != 0 && x + j <= maxa)
				{
					cnt[x][j + offset] = (cnt[x][j + offset] + cnt[x + j][j + offset])%MOD;
					cnt[x][j + offset] = (cnt[x][j + offset] + cntA[x + j])%MOD;
				}

			}
			
			cntA[x] = (cntA[x] + 1)%MOD;
		}
		
		for(int i=1; i<=maxa; ++i)
		{
			for(int j=0; j<=maxa+offset; ++j) sol = (sol + cnt[i][j])%MOD;
			sol = (sol + cntA[i])%MOD;
		}
		sol = all - sol;
		if(sol < 0) sol += MOD;
		
		printf("%d\n", sol);
	}

	return 0;
}
