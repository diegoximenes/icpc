#include<cstdio>
#include<cstring>
#include<bitset>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;
#define MAX 10000010
#define pb push_back

vector<ll> primes;
bitset<MAX> isPrime;
int cntFactors[MAX];

void sieve(int n)
{
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for(ll i=2; i<=n; ++i)
		if(isPrime[i])
		{
			primes.pb(i);
			for(ll j=i*i; j<=n; j+=i) isPrime[j] = 0;
		}
}

void primeFactors(int r, ll x, set<int> &tree)
{
	ll i = 0, pf = primes[i];
	while(x != 1 && (pf * pf) <= x)
	{
		while(x%pf == 0) x /= pf, tree.insert(pf);
		pf = primes[++i];
	}
	if(x != 1) tree.insert(x);
}

int main()
{
	int n, x;

	scanf("%d", &n);
	
	memset(cntFactors, 0, sizeof(cntFactors));
	sieve(MAX-1);
	
	int cnt1 = 0;
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &x);
		if(x == 1) cnt1++;
		
		set<int> tree;
		set<int>::iterator it;
		primeFactors(i, x, tree);
		for(it=tree.begin(); it!=tree.end(); ++it) cntFactors[*it]++;
	}
	
	if(cnt1 == n)
	{
		puts("0");
		return 0;
	}

	int cnt = 1;
	for(int i=0; i<MAX; ++i) cnt = max(cnt, cntFactors[i]);
	
	if(cnt >= 3) puts("infinity");
	else printf("%d\n", cnt);

	return 0;
}
