#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;

#define pb push_back
#define MAX 1000

vector<int> primes;

void sieve(int n)
{
	bitset<MAX> mark;
	mark.set();

	for(int i=2; i<=n; ++i)
		if(mark[i])
		{
			primes.pb(i);
			for(int j=i*i; j<=n; j+=i)
				mark[i] = 0;
		}
}

int countFactors(int n)
{
	int i = 0, lastFactor = -1, count = 0;
	while(n >= primes[i] && i < (int)primes.size())
	{
		if(n%primes[i] != 0) ++i;
		else
		{
			n /= primes[i];
			if(i != lastFactor) ++count;
			lastFactor = i;
		}
	}
	if(n > 1) ++count;

	return count;
}

int main()
{
	int n;

	sieve(MAX);

	while(scanf("%d", &n) && n)
		printf("%d : %d\n", n, countFactors(n));
}
