#include<bits/stdc++.h>
using namespace std;

#define HMAX 1300
#define RMAX 200005
#define MOD 1000000007

int a, b, h;
int dp[2][RMAX];

inline int sumPA(int first, int last, int n){ return (first+last)*n/2; }

inline bool can(int height)
{
	int la = a, lb = b;
	for(int i=height; i>=1; --i)
	{
		if(la > lb) la -= i;
		else lb -= i;
		if(la < 0 || lb < 0) return 0;
	}
	return 1;
}

int main()
{
	scanf("%d %d", &a, &b);	
	
	h = -1;
	int l = 1, r = a+b;
	while(l <= r)
	{
		int mid = (l+r)/2;
		if(can(mid)) h = mid, l = mid+1;
		else r = mid-1;
	}
	
	for(int remainingA=0; remainingA<=a; ++remainingA) dp[0][remainingA] = 1;
	for(int height=1; height<=h; ++height)
		for(int remainingA=0; remainingA<=a; ++remainingA)
		{	
			int usedA = a - remainingA;
			int usedB = (sumPA(h, height+1, h-height) - usedA);
			int remainingB = b - usedB;

			dp[height&1][remainingA] = 0;
			if(remainingA >= height) dp[height&1][remainingA] = (dp[height&1][remainingA] + dp[(height-1)&1][remainingA-height]) % MOD;
			if(remainingB >= height) dp[height&1][remainingA] = (dp[height&1][remainingA] + dp[(height-1)&1][remainingA]) % MOD;
		}

	printf("%d\n", dp[h&1][a]);

	return 0;
}
