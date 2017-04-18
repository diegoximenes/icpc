#include<cstdio>
#include<cmath>
#include<utility>
using namespace std;

#define mp make_pair
#define ll long long

pair< ll, pair<ll, ll> > extendedEuclid(ll a, ll b)
{
	ll x0 = 1, y0 = 0, x1 = 0, y1 = 1, x2, y2, q;
	while(b != 0)
	{
		q = a/b;
		x2 = x0 - q*x1;
		y2 = y0 - q*y1;
		
		x0 = x1; y0 = y1;
		x1 = x2; y1 = y2;

		ll aux = b;
		b = a - q*b; //b = a%b;
		a = aux;
	}

	if(a > 0) return mp(a, mp(x0, y0));
	return mp(-a, mp(-x0, -y0));
}

pair< pair<bool, ll>, pair<ll, ll> > linearDiophantine(ll a, ll b, ll c)
{
	pair< ll, pair<ll, ll> > p = extendedEuclid(a, b);

	if(c%p.first == 0) return mp(mp(1, p.first), mp(p.second.first*c/p.first, p.second.second*c/p.first));
	return mp(mp(0, 0), mp(0, 0));
}

int main()
{
	ll a, b;
	while(scanf("%d %d", &a, &b) == 2)
	{
		pair< ll, pair<ll, ll> > p = extendedEuclid(a, b);
		printf("%lld %lld %lld\n", p.second.first, p.second.second, p.first);
	}

	return 0;
}
