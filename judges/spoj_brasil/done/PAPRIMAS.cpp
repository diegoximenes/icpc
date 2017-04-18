#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

#define pb push_back

vector<int> primes;

inline int num(char c)
{
	if(c >= 'a' && c <= 'z') return c - 'a' + 1;
	return c - 'A' + 27;
}


inline void generatePrimes(int n)
{
	primes.pb(2);
	for(int i=3; i<n; ++i)
	{
		int upper = sqrt(1.0*i) + 1;
		bool isprime = 1;
		for(int j=2; j<upper; ++j)
			if(i%j == 0)
			{
				isprime = 0;
				break;
			}
		if(isprime) primes.pb(i);
	}
}

bool isPrime(int n)
{
	for(int i=0; i<(int)primes.size(); ++i)
	{
		if(primes[i] == n) return 1;
		if(primes[i] > n) return 0;
	}
	return 0;
}

int main()
{
	char l[25];

	generatePrimes(20*52);

	while(scanf(" %s", l) == 1)
	{
		int len = strlen(l), count = 0;
		for(int i=0; i<len; ++i)
			count += num(l[i]);
			
		if(count == 1 || isPrime(count)) puts("It is a prime word.");
		else puts("It is not a prime word.");
	}

	return 0;
}
