#include<cstdio>
#include<bitset>
using namespace std;

#define MAX (int) 1e6
#define MAX2 (long long int) 1e12

long long int primes[MAX];
int countPrimes;

void sieve()
{
	bitset<MAX> prime;
	prime.set();
	countPrimes = 0;
	
	for(long long int i=2; i<=MAX; ++i)
		if(prime[i])
		{
			for(long long int j=i*i; j<=MAX; j+=i)
				prime[j] = 0;
			primes[countPrimes++] = i;
		}
}

int main()
{
	int t, countAlmost = 0;
	long long almost[MAX], l, u;
	
	countPrimes = 0;
	sieve();
	for(int i=0; i<countPrimes; ++i)
		for(long long int j= primes[i]*primes[i]; j<=MAX2; j*=primes[i])
			almost[countAlmost++] = j;
		
	scanf("%d", &t);
	while(t--)
	{
		int count = 0;
		scanf("%lld %lld", &l, &u);
		for(int i=0; i<countAlmost; ++i)
			if(almost[i]>=l && almost[i]<=u)
				++count;
		printf("%d\n", count);
	}
		

	return 0;
}