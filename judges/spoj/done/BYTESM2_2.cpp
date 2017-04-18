#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 105

int dp[MAX*MAX], g[MAX*MAX], h, w;

inline int ind(int i, int j)
{
	return i*w + j;
}

inline bool in(int i, int j)
{
	if(i>=0 && i<h && j>=0 && j<w)
		return 1;
	return 0;
}

int main()
{
	int t, mem;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &h, &w);
		mem = h*w;
		for(int i=0; i<mem; ++i)
		{
			scanf("%d", g+i);
			dp[i] = -1;
		}
		
		int i2, j2, indij, gij;
		for(int i=h-1; i>=0; --i)
			for(int j=0; j<w; ++j)
			{
				indij = ind(i, j);
				gij = dp[indij] = g[indij];
				for(int k=-1; k<=1; ++k)
				{
					i2 = i+1; j2 = j+k;
					if(in(i2, j2))
						dp[indij] = max(dp[indij], dp[ind(i2, j2)] + gij);
				}
			}
		
		
		int res = -1;
		for(int i=0; i<w; ++i)
			res = max(res, dp[ind(0, i)]);
		printf("%d\n", res);
	}
	
	return 0;
}