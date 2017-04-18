#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 10010

int main()
{
	int n, v[MAX], dp[MAX], maxdp;

	while(scanf("%d", &n) && n)
	{
		maxdp = -1;
		for(int i=0; i<n; ++i)
		{
			scanf("%d", &v[i]);
			if(!i) dp[i] = v[i];
			else dp[i] = max(v[i], v[i] + dp[i-1]);
			maxdp = max(maxdp, dp[i]);
		}

		if(maxdp <= 0) puts("Losing streak.");
		else printf("The maximum winning streak is %d.\n", maxdp);
	}

	return 0;
}
