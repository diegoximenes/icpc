#include<cstdio>
#include<cstring>
#include<bitset>
#include<vector>
using namespace std;

#define MAX 1000010
#define ll long long
#define pb push_back

vector<int> digitPrimes;
bitset<MAX> isPrime, isDigitPrime;
int smaller[MAX];

inline void sieve(int n)
{
	isPrime.set(); isDigitPrime.reset();
	isPrime[1] = isPrime[0] = 0;

	for(ll i=2; i<=n; ++i)
		if(isPrime[i])
		{
			int d = 0, num = i;
			while(num)
			{
				d += num%10;
				num /= 10;
			}
			if(isPrime[d])
			{
				digitPrimes.pb(i);
				isDigitPrime[i] = 1;
			}

			for(ll j=i*i; j<=n; j+=i)
				isPrime[j] = 0;
		}
}

int main()
{
	sieve(MAX - 1);
	
	memset(smaller, 0, sizeof(smaller));
	int j = digitPrimes.size() - 1, i = MAX - 1;
	while(i >= 0 && j >= 0)
	{
		if(digitPrimes[j] <= i)
		{
			smaller[i] = j + 1;
			--i;
		}
		else --j;
	}

	int l, r, tc;
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d %d", &l, &r);
		int aux = 0;
		if(isDigitPrime[l]) aux = 1;
		printf("%d\n", smaller[r] - smaller[l] + aux);
	}

	return 0;
}
