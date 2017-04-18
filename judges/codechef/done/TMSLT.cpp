#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX 3000005
#define MOD 1000000

typedef long long ll;

int v[MAX], cnt[MAX];

int main()
{
	int t, n;
	ll a, b, c, d;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %lld %lld %lld %lld", &n, &a, &b, &c, &d);
		
		memset(cnt, 0, sizeof(cnt));
		v[0] = d;
		int maxv = v[0];
		cnt[v[0]]++;
		for(int i=1; i<n; ++i) v[i] = (a*(ll)v[i-1]*(ll)v[i-1] + b*(ll)v[i-1] + c)%MOD, cnt[v[i]]++, maxv = max(maxv, v[i]);
		

		ll s1 = 0, s2 = 0;
		while(n > 0)
		{
			if(cnt[maxv])
			{
				(n%2 == 0) ? s1 += maxv : s2 += maxv;
				--n;
				--cnt[maxv];
			}
			else --maxv;
		}

		printf("%lld\n", abs(s1 - s2));
	}

	return 0;
}
