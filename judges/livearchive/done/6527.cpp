#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll dp[65][65][2], a, b;

ll opt(int pos, int sum, int less, ull x)
{
	if(pos == -1) return sum;
	ll & state = dp[pos][sum][less];
	if(state != -1) return state;

	if(less) state = opt(pos-1, sum+1, 1, x) + opt(pos-1, sum, 1, x);
	else
	{
		if((1LL << pos) & x) state = opt(pos-1, sum+1, 0, x) + opt(pos-1, sum, 1, x);
		else state = opt(pos-1, sum, 0, x);
	}
	return state;
}

ll f(ull x)
{
	memset(dp, -1, sizeof(dp));
	for(int i=63; i>=0; --i)
		if((1LL << i) & x)
			return opt(i, 0, 0, x);
	return 0;
}

int main()
{
	while(scanf("%lld %lld", &a, &b) == 2)
		printf("%lld\n", f(b) - f(a-1));

	return 0;
}
