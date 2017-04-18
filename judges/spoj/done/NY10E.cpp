#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;

#define MAX 1005

ll dp[MAX][10], sol[MAX];

ll opt(int n, int d)
{
	if(n == 0) return 1;
	ll &state = dp[n][d];
	if(state != -1) return state;
	
	ll sol = 0;
	for(int i=0; i<=d; ++i) sol += opt(n-1, i);

	return state = sol;
}

int main()
{
	int t;
	
	memset(dp, -1, sizeof(dp));
	opt(999, 9);
	for(int i=1; i<=1000; ++i)
	{
		sol[i] = 0;
		for(int j=0; j<10; ++j) sol[i] += opt(i-1, j);
	}
		
	scanf("%d", &t);
	while(t--)
	{
		int tc, n;
		scanf("%d %d", &tc, &n);
		
		printf("%d %lld\n", tc, sol[n]);
	}

	return 0;
}
