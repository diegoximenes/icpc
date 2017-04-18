#include<cstdio>
#include<vector>
#include<bitset>
#include<set>
#include<map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define pb push_back
#define MAX 100000
#define MAX2 400
#define MOD (ll)(1e9 + 7)

vector<int> g[MAX];
bool mark[MAX];

vector<int> primes;
bitset<MAX> isPrime;

void sieve(int n)
{
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for(ll i=2; i<=(ll)n; ++i)
		if(isPrime[i])
		{
			primes.pb(i);
			for(ll j=i*i; j<=n; j+=i) isPrime[j] = 0;
		}
}

vector<int> primeFactors(int n)
{
	vector<int> factors;
	int i = 0, pf = primes[i];
	while(n != 1 && (pf * pf <= n))
	{
		while(n % pf == 0) n /= pf, factors.pb(pf);
		pf = primes[++i];
	}
	if(n != 1) factors.pb(n);
	return factors;
}

int dfs(int u)
{
	mark[u] = 1;
	int size = 1;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(!mark[v]) size += dfs(v);
	}
	return size;
}

int main()
{
	int t, n;
	
	sieve(MAX2);

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=0; i<n; ++i) g[i].clear();
		for(int i=0; i<n; ++i)
		{
			int x;
			scanf("%d", &x); --x;
			g[i].pb(x); g[x].pb(i);
			mark[i] = 0;
		}
		
		map<int, int> maxExp;
		map<int, int>::iterator it;
		for(int i=0; i<n; ++i)
			if(!mark[i])
			{
				vector<int> factors = primeFactors(dfs(i));

				map<int, int> cntExp;
				for(int j=0; j<(int)factors.size(); ++j)
				{
					if(cntExp.find(factors[j]) == cntExp.end()) cntExp[factors[j]] = 1;
					else cntExp[factors[j]]++;

					if(maxExp.find(factors[j]) == maxExp.end()) maxExp[factors[j]] = cntExp[factors[j]];
					else maxExp[factors[j]] = max(maxExp[factors[j]], cntExp[factors[j]]);
				}
			}
		
		ll sol = 1;
		for(it = maxExp.begin(); it != maxExp.end(); ++it)
			for(int i=0; i<it->second; ++i)
				sol = (sol * it->first)%MOD;
		
		printf("%lld\n", sol);
	}

	return 0;
}
