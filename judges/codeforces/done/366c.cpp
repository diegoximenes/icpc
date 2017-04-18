#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXN 110
#define MAXC 200010
#define INF (int) 1e9

const int minc = -10000, maxc = 10000;
const int offset = maxc;

int dp[MAXN][MAXC], a[MAXN], b[MAXN], n, k;

int opt(int i, int w)
{
	int woffset = w + offset;
	if(i == n)
	{
		if(w == 0) return 0; 
		return -INF;
	}
	if(woffset < 0  || woffset > MAXC) return -INF;
	if(dp[i][woffset] != -1) return dp[i][woffset];

	return dp[i][woffset] = max(opt(i+1, w), a[i] + opt(i+1, w - (a[i] - k*b[i])));
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i) scanf("%d", &a[i]);
	for(int i=0; i<n; ++i) scanf("%d", &b[i]);
	
	for(int i=minc; i<maxc; ++i) opt(0, i);
	int sol = opt(0, 0);
	printf("%d\n", sol ? sol : -1);

	return 0;
}
