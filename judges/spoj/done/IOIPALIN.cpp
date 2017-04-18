#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 5005

int n, dp[MAX][MAX];
char s[MAX];

int main()
{
	scanf("%d %s ", &n, s);
	
	for(int j=0; j<n; ++j) dp[n-1][j] = 0, dp[j][j] = 0;	
	for(int i=n-1; i>=0; --i)
		for(int j=i+1; j<n; ++j)
		{
			if(s[i] == s[j])
			{
				if(i+1 < j-1) dp[i][j] = dp[i+1][j-1];
				else dp[i][j] = 0;
			}
			else dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
		}

	printf("%d\n", dp[0][n-1]);

	return 0;
}
