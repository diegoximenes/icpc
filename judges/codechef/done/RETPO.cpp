#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

typedef long long ll;

int main()
{
	int t;
	ll x, y;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld %lld", &x, &y);
		x = abs(x); y = abs(y);

		ll d1 = min(x, y), sol = 0;
		sol += 2*d1; x -= d1; y -= d1;
		
		if(y)
		{
			sol += y/2 * 3;
			sol += (y - y/2);
		}
		else if(x)
		{
			sol += x/2;
			sol += (x - x/2) * 3;
		}

		printf("%lld\n", sol);
	}

	return 0;
}
