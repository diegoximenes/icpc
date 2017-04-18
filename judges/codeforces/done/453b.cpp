#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define CNTPRIMES 17
#define MASKMAX (1 << CNTPRIMES)
#define NMAX 105
#define AMAX 30
#define INF 0x3f3f3f3f

int n, a[NMAX], dp[NMAX][MASKMAX], numMask[2*AMAX + 5];
const int primes[CNTPRIMES] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

int opt(int i, int mask)
{
	if(i == n) return 0;
	if(__builtin_popcount(mask) == CNTPRIMES) return INF;
	int &state = dp[i][mask];
	if(state != -1) return state;
	
	state = abs(a[i] - 1) + opt(i+1, mask);
	for(int j=2; j<=2*AMAX; ++j)
		if((mask & numMask[j]) == 0)
			state = min(state, abs(a[i] - j) + opt(i+1, mask | numMask[j]));

	return state;
}

void build(int i, int mask)
{
	if(i == n) return;
	
	if(opt(i, mask) == abs(a[i] - 1) + opt(i+1, mask))
	{
		if(i) putchar(' ');
		printf("%d", 1);
		build(i+1, mask);
		return;
	}

	for(int j=2; j<=2*AMAX; ++j)
		if((mask & numMask[j]) == 0 && opt(i, mask) == abs(a[i] - j) + opt(i+1, mask | numMask[j]))
		{
			if(i) putchar(' ');
			printf("%d", j);
			build(i+1, mask | numMask[j]);
			return;
		}
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &a[i]);
	
	for(int i=2; i<=2*AMAX; ++i)
	{
		int mask = 0;
		for(int j=0; j<CNTPRIMES; ++j)
			if(i%primes[j] == 0)
				mask |= (1 << j);
		numMask[i] = mask;
	}
		
	memset(dp, -1, sizeof(dp));
	build(0, 0); puts("");

	return 0;
}
