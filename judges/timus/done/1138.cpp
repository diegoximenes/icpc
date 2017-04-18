#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 1e9
#define MAX 10005

int dp[MAX], s, n;

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a%b)); }

int opt(int i)
{
	if(i == n) return 0;
	int &state = dp[i];
	if(state != -1) return state;

	int sol = 0;
	for(int j=1; i+j <= n; ++j)
	{
		if(100*(i+j)/i > 200) break;
		if(gcd(100*(i+j), i) == i) sol = max(sol, 1 + opt(i+j));
	}

	return state = sol;
}

int main()
{
	scanf("%d %d", &n, &s);
	
	if(n == s) puts("1");
	else
	{
		memset(dp, -1, sizeof(dp));
		printf("%d\n", 1 + opt(s));
	}

	return 0;
}
