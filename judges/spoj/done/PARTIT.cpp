#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MAX 221
#define MAX2 11

int n, m, k, dp[MAX2][MAX][MAX];

int solve(int pos, int start, int res)
{	
	if(dp[pos][start][res] != -1)
		return dp[pos][start][res];
	
	if(pos == n-1 && res == m)
		return dp[pos][start][res] = 1;
	else if(pos == n-1)
		return dp[pos][start][res] = 0;
	
	dp[pos][start][res] = 0;
	for(int i=start; i<MAX; ++i)
	{
		if(res + i <= m)
			dp[pos][start][res] += solve(pos+1, i, res+i);
		else
			break;
	}
	
	return dp[pos][start][res];
}

int main()
{
	int t;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &m, &n, &k);
		memset(dp, -1, sizeof(dp));
		
		int j = 1, res = 0, count, i=0;
		bool first = 1;
		while(i < n)
		{
			count = solve(i, j, res+j);
			if(count >= k)
			{
				if(first)
				{
					printf("%d", j);
					first = 0;
				}
				else
					printf(" %d", j);
				res += j;
				++i;
			}
			else
			{
				k -= count;
				++j;
			}
		}
		puts("");
	}
	
	return 0;
}