#include<cstdio>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a%b)); }

ll cntEven(ll n) { return n/2; }
ll cntOdd(ll n) { return (n+1)/2; }

int main()
{
	int t;
	ll n, m;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld %lld", &n, &m);

		ll neven = cntEven(n), nodd = cntOdd(n);
		ll meven = cntEven(m), modd = cntOdd(m);

		ll num = neven*modd + nodd*meven, den = n*m;
		ll g = gcd(num, den);

		printf("%lld/%lld\n", num/g, den/g);
	}

	return 0;
}
