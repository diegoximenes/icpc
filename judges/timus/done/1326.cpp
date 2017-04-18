#include<bits/stdc++.h>
using namespace std;

#define MMAX 105
#define NMAX 20
#define MASKMAX (1 << NMAX)
#define INF 0x3f3f3f3f

int dp[2][MASKMAX], finalMask, n, m, price[NMAX + MMAX], setMask[NMAX + MMAX];

inline bool check(int mask1, int mask2)
{
	for(int i=0; i<n; ++i)
		if((mask1 & (1 << i)) && !(mask2 & (1 << i)))
			return 0;
	return 1;
}

int main()
{
	int x, y;

	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &price[i]), setMask[i] = (1 << i);
	scanf("%d", &m);
	for(int i=0; i<m; ++i)
	{
		int mask = 0;
		scanf("%d %d", &price[n+i], &x);
		while(x--) scanf("%d", &y), mask |= (1 << (y-1));

		setMask[n+i] = mask;
	}
	finalMask = 0;
	scanf("%d", &x);
	while(x--) scanf("%d", &y), finalMask |= (1 << (y-1));
	
	int upperMask = (1 << n);
	n += m;

	for(int mask=0; mask<upperMask; ++mask)
	{
		if(check(finalMask, mask)) dp[n%2][mask] = 0;
		else dp[n%2][mask] = INF;
	}
	for(int i=n-1; i>=0; --i)
		for(int mask=0; mask<upperMask; ++mask)
			dp[i%2][mask] = min(price[i] + dp[(i+1)%2][mask | setMask[i]], dp[(i+1)%2][mask]);

	printf("%d\n", dp[0%2][0]);

	return 0;
}
