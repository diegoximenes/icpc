#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;

#define MAXD 25
#define MAXM 1005

int exp10[MAXD];
ll dp[MAXD][MAXM];
int n, m;

ll opt(int i, int sum)
{
	int lower = 0; 
	ll sol = 0;
	if(i == 0) lower = 1;

	if(i == n/2)
	{
		if(n%2 == 1)
		{
			for(int j=lower; j<=9; ++j)
				if((sum + exp10[i] * j)%m == 0) 
					sol++;
			return sol;
		}
		else
		{
			if(sum == 0) return 1;
			return 0;
		}
	}

	ll &state = dp[i][sum];
	if(state != -1) return state;

	for(int j=lower; j<=9; ++j)
		sol += opt(i+1, (sum + exp10[i]*j + exp10[n-i-1]*j)%m);
	

	return state = sol;
}

int main()
{
	int t;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &m, &n);
		
		exp10[0] = 1;
		for(int i=1; i<MAXD; ++i) exp10[i] = (exp10[i-1]*10)%m;

		memset(dp, -1, sizeof(dp));
		printf("%lld\n", opt(0, 0));
	}

	return 0;
}
