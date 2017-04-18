#include<stdio.h>
#include<string.h>

#define N 32768

/*sieve of eratosthenes*/
void sieve(int *primes, char *isPrime, int *countPrimes, const int n)
{
	int i, j; 

	*countPrimes = 0;
	memset(isPrime, 1, n*sizeof(char));

	for(i=2; i<=n; ++i)
		if(isPrime[i])
		{			
			primes[(*countPrimes)++] = i;
			for(j=i*i; j<=n; j+=i)
				isPrime[j] = 0;
		}
}

int main()
{
	int primes[N+10], countPrimes, i, j, count, n;
	char isPrime[N+10];

	/*generate primes*/
	sieve(primes, isPrime, &countPrimes, N);
	
	while(scanf("%d", &n) && n)
	{
		count = 0;
		i = n/2;
		for(j=0; j<countPrimes && primes[j]<=i; ++j)
			if(isPrime[n-primes[j]])
				++count;
		printf("%d\n", count);
	}

	return 0;
}
