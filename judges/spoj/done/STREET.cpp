#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 1e9
#define MAX 505

int dp[MAX][MAX], cumMin[MAX][MAX], h[MAX], n, t, k;

int opt(int i, int actualK)
{
	if(actualK > k) return -INF;
	if(i == n)
	{
		if(actualK == k) return 0;
		return -INF;
	}
	int &state = dp[i][actualK];
	if(state != -1) return state;
	
	int sol = opt(i+1, actualK);
	for(int j=0; j<t && i+j<n; ++j) sol = max(sol, cumMin[i][i+j]*(j + 1) + opt(i+j+1, actualK + 1));
	
	return state = sol;
}

int main()
{
	scanf("%d %d %d", &n, &k, &t);
	for(int i=0; i<n; ++i) scanf("%d", &h[i]);
	
	for(int i=0; i<n; ++i)
		for(int j=i; j<n; ++j)
		{
			if(i == j) cumMin[i][i] = h[i];
			else cumMin[i][j] = min(cumMin[i][j-1], h[j]);
		}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", opt(0, 0));

	return 0;
}
