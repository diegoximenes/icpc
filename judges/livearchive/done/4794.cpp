#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define isOn(S, j) (S & (1 << j))

#define MAX 101
#define MAX2 (int) (1 << 15)

int w, h, n, v[16], dp[MAX][MAX2], sum[MAX2], size[MAX2], ind[MAX2];

int solve(int x, int y, int set)
{
	if(dp[x][set] != -1)
		return dp[x][set];
	
	if(size[set] == 1)
	{
		if(v[ind[set]] == x*y)
			return dp[x][set] = 1;
		return dp[x][set] = 0;
	}
	
	int maxx = x/2, maxy = y/2;
	//split vertical
	for(int i=1; i<=maxx; ++i)
		for(int set2 =((set-1)&set); set2; set2 = ((set2-1)&set))
		{
			int set3 = set-set2;
			if(sum[set2]==i*y && sum[set3]==(x-i)*y && solve(min(i, y), max(i, y), set2) && solve(min(x-i, y), max(x-i, y), set3))
				return dp[x][set] = 1;
		}
	//split horizontal
	for(int i=1; i<=maxy; ++i)
		for(int set2 =((set-1)&set); set2; set2 = ((set2-1)&set))
		{
			int set3 = set-set2;
			if(sum[set2]==i*x && sum[set3]==(y-i)*x && solve(min(x, i), max(x, i), set2) && solve(min(y-i, x), max(y-i, x), set3))
				return dp[x][set] = 1;
		}
		
	return dp[x][set] = 0;
}

int main()
{	
	for(int tc=1; scanf("%d", &n) && n; ++tc)
	{
		scanf("%d %d", &w, &h);
		for(int i=0; i<n; ++i)
			scanf("%d", v+i);
		
		int minhw = min(h, w);
		for(int i=0; i<=minhw; ++i)
			memset(dp[i], -1, sizeof(dp[i]));
		memset(sum, 0, sizeof(sum));
		memset(size, 0, sizeof(size));
		
		int set = (1 << n) - 1;
		for(int i=0; i<=set; ++i)
			for(int j=0; j<n; ++j)
				if(isOn(i, j))
				{
					sum[i] += v[j];
					++size[i];
					ind[i] = j;
				}
				
		printf("Case %d: ", tc);
		if(solve(min(w, h), max(w, h), set))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}