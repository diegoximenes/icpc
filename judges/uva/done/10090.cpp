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
	ll n, c1, n1, c2, n2;
	while(scanf("%lld", &n) && n)
	{
		scanf("%lld %lld %lld %lld", &c1, &n1, &c2, &n2);
		
		pair< pair<bool, ll>, pair<ll, ll> > p = linearDiophantine(n1, n2, n);
		if(!p.first.first) puts("failed");
		else
		{
			ll x = p.second.first, y = p.second.second, gcd = p.first.second;
			ll k1 = ceil(-(double)x/n2*gcd);
			ll k2 = floor((double)y/n1*gcd);
			
			//verify if there is a positive solution	
			if(k2 < k1)
			{
				puts("failed");
				continue;
			}
			
			//verify the min cost solution consiring the boundaries calculated before
			ll aux1 = x + k1*n2/gcd, aux2 = y - k1*n1/gcd, aux3 = x + k2*n2/gcd, aux4 = y - k2*n1/gcd;
			if(c1*aux1 + c2*aux2 < c1*aux3 + c2*aux4) printf("%lld %lld\n", aux1, aux2);
			else printf("%lld %lld\n", aux3, aux4);
		}
	}

	return 0;
}
