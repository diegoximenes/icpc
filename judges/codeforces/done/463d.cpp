#include<bits/stdc++.h>
using namespace std;

#define KMAX 6
#define NMAX 1005

int perm[KMAX][NMAX], ind[KMAX][NMAX], dp[NMAX][NMAX], n, k;

int opt(int i, int lastv)
{
	if(i > n) return 0;
	int &state = dp[i][lastv];
	if(state != -1) return state;
	
	state = opt(i+1, lastv);
	for(int j=0; j<k; ++j)
	{
		bool can = 1;
		for(int l=0; l<k; ++l)
			if(ind[l][perm[j][i]] <= ind[l][lastv])
				can = 0;
		if(can) state = max(state, 1 + opt(i+1, perm[j][i]));
	}
	
	return state;
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<k; ++i)
	{
		ind[i][0] = 0;
		for(int j=1; j<=n; ++j)
		{
			scanf("%d", &perm[i][j]);	
			ind[i][perm[i][j]] = j;
		}
	}
	
	memset(dp, -1, sizeof(dp));
	printf("%d\n", opt(1, 0));

	return 0;
}
