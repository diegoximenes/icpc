#include<cstdio>
#include<bitset>
using namespace std;

typedef long long ll;
#define MAX 3000

bitset<MAX> isPrime;

void sieve(int n)
{
	isPrime.set();
	isPrime[0] = 0; isPrime[1] = 0;
	for(ll i=2; i<n; ++i)
		if(isPrime[i])
			for(ll j=i*i; j<n; j += i)
				isPrime[j] = 0;
}

int main()
{
	int t, x, y;
	
	sieve(MAX);

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &x, &y);
		for(int i=x+y+1; ;++i)
			if(isPrime[i])
			{
				printf("%d\n", i-(x+y));
				break;
			}
	}

	return 0;
}
