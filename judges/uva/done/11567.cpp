#include<cstdio>
#include<algorithm>
using namespace std;

#define ll long long

int solve(ll n)
{
	if(n == 0) return 0;
	if(n == 1) return 1;

	if(n%2 != 0)
		return 1 + min(solve(n+1), solve(n-1));
	return 1 + solve(n/2);
}

int main()
{
	int count;
	ll s;

	while(scanf("%lld", &s) == 1)
		printf("%d\n", solve(s));
		
	return 0;
}
