#include<cstdio>
#include<iostream>
#include<cstring>
#include<bitset>
#include<vector>
using namespace std;

typedef long long ll;

#define pb push_back
#define MAX 1250*1250

ll dp[MAX];
bitset<MAX> isPrime;
vector<ll> primes;

void sieve(ll n)
{
	isPrime.set();
	isPrime[0] = 0; isPrime[1] = 0;
	for(ll i=2; i<=n; ++i)
		if(isPrime[i])
		{
			for(ll j=i*i; j<=n; j+=i) isPrime[j] = 0;
			primes.pb(i);
		}
}

ll cntDivisors(ll n)
{
	ll i = 0, pf = primes[0], sol = 1;
	while(n != 1 && (pf*pf <= n))
	{
		int cnt = 0;
		while(n%pf == 0) n /= pf, cnt++;
		sol *= (cnt + 1);
		pf = primes[++i];
	}

	if(n != 1) return sol*2;
	return sol;
}

int main()
{
	int t, n;
	
	sieve(MAX-1);
	
	dp[0] = 0; dp[1] = 1;
	for(int i=2; i<MAX; ++i) dp[i] = dp[i-1] + cntDivisors(i);

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		
		ll cnt = 0;
		for(int a00=1; a00<n; ++a00)
		{
			int a11 = n - a00;
			
			cnt += dp[a00*a11 - 1];

			//printf("a00= %d, a11= %d, dp= %lld\n", a00, a11, dp[a00*a11 - 1]);
		}

		//printf("%lld\n", cnt);
		cout << cnt << endl;
	}

	return 0;
}
