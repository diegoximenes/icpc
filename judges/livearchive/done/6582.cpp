#include<cstdio>
#include<map>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a%b)); }

int main()
{
	int t, n;
	ll x;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);

		map<ll, ll> g;
		map<ll, ll>::iterator it;
		ll sol = 0;
		for(int i=0; i<n; ++i)
		{
			scanf("%lld", &x);
			
			map<ll, ll> newg;
			for(it = g.begin(); it != g.end(); ++it)
			{
				ll auxgcd = gcd(it->first, x);
				if(newg.find(auxgcd) == newg.end()) newg[auxgcd] = it->second + 1;
				else newg[auxgcd] = max(newg[auxgcd], it->second + 1);
				
				sol = max(sol, auxgcd * newg[auxgcd]);
			}
			
			if(newg.find(x) == newg.end()) newg[x] = 1;
			sol = max(sol, x * newg[x]);

			g = newg;
		}

		printf("%lld\n", sol);
	}

	return 0;
}
