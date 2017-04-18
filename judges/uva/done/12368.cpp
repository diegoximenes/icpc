#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define NMAX 10
#define MASKMAX (1 << NMAX)
#define VMAX 105
#define INF 0x3f3f3f3f

int n, age[NMAX], dp[MASKMAX][VMAX], dp2[MASKMAX][VMAX];
bool canMask[MASKMAX];

bool cmp(int mask1, int mask2)
{
	if(__builtin_popcount(mask1) != __builtin_popcount(mask2))
		return (__builtin_popcount(mask1) < __builtin_popcount(mask2));

	for(int i=9; i>=0; --i)
	{
		if((mask1 & (1 << i)) && !(mask2 & (1 << i))) return 0;
		if(!(mask1 & (1 << i)) && (mask2 & (1 << i))) return 1;
	}
	return 1;
}

int main()
{
	for(int mask=0, upper=(1 << 10); mask<upper; ++mask) dp[mask][0] = 1;
	for(int v=1; v<=100; ++v) dp[0][v] = 0;
	for(int mask=1, upper=(1 << 10); mask<upper; ++mask)
		for(int v=1; v<=100; ++v)
		{
			dp[mask][v] = 0;
			if(mask & (1 << (v%10))) 
			{
				int newMask = (mask & ~(1 << (v%10)));
				dp[mask][v] = dp[newMask][v/10];
			}		
		}
	
	for(int mask=0, upper=(1<<10); mask<upper; ++mask)
		for(int v=1; v<=100; ++v)
		{
			int state = dp[mask][v];
			for(int mask1=((mask-1) & mask); !state && mask1; mask1=((mask1-1) & mask))
			{
				int mask2 = mask & ~(mask1);
				for(int v2=1; !state && v2<v; ++v2) state = dp[mask1][v2] && dp[mask2][v-v2];
			}
			dp2[mask][v] = state;
		}


	for(int tc=1; scanf("%d", &n) && n; ++tc)
	{
		memset(canMask, 1, sizeof(canMask));
		
		for(int i=0; i<n; ++i) 
		{
			scanf("%d", &age[i]);
		
			for(int mask=0, upper=(1<<10); mask<upper; ++mask)
				if(!dp2[mask][age[i]])
					canMask[mask] = 0;
		}
		
		vector<int> possibleMasks;
		for(int mask=0, upper=(1<<10); mask<upper; ++mask)
			if(canMask[mask])
				possibleMasks.pb(mask);
		sort(possibleMasks.begin(), possibleMasks.end(), cmp);

		printf("Case %d: ", tc);
		for(int i=9; i>=0; --i)
			if(possibleMasks[0] & (1 << i)) 
				printf("%d", i);
		puts("");
	}
 
	return 0;
}
