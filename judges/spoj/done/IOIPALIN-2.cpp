#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 5005

int n, dp[2][MAX];
char s[MAX];

int main()
{
	scanf("%d %s ", &n, s);
	
	for(int j=0; j<n; ++j) dp[(n-1)%2][j] = 0, dp[j%2][j] = 0;	
	for(int i=n-1; i>=0; --i)
		for(int j=i+1; j<n; ++j)
		{
			if(s[i] == s[j])
			{
				if(i+1 < j-1) dp[i%2][j] = dp[(i+1)%2][j-1];
				else dp[i%2][j] = 0;
			}
			else dp[i%2][j] = 1 + min(dp[(i+1)%2][j], dp[i%2][j-1]);
		}

	printf("%d\n", dp[0%2][n-1]);

	return 0;
}
