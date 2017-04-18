#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 32
#define MAX2 1002

int a[MAX], dp[MAX2][MAX];

int opt(int v, int i)
{
	if(v == 0) return 1;
	if(i == -1 || v < 0) return 0;
	if(dp[v][i] != -1) return dp[v][i];
	
	return dp[v][i] = max(opt(v - a[i], i - 1), opt(v, i - 1));
}

int main()
{
	int n;

	for(int tc=1; scanf("%d", &n) == 1; ++tc)
	{
		bool isSequence = 1;
		for(int i=0; i<n; ++i)
		{
			scanf("%d", &a[i]);
			if(i > 0 && a[i] <= a[i-1]) isSequence = 0;
		}

		if(isSequence)
		{
			memset(dp, -1, sizeof(dp));
			for(int i=2; i<n && isSequence; ++i)
				if(opt(a[i], i-1))
					isSequence = 0;
		}

		printf("Case #%d:", tc);
		for(int i=0; i<n; ++i) printf(" %d", a[i]);
		if(isSequence) puts("\nThis is an A-sequence.");
		else puts("\nThis is not an A-sequence.");
	}
	
	return 0;
}
