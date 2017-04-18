#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define INF 1e9
#define MAX 2000000000
#define MAX2 10000
#define MAX3 300000
#define MAX4 10000010

int cnt[MAX4], cum[MAX4], n, m;
int v[MAX4], maxx;
bitset<MAX4> isPrime;

void sieve(int n)
{
	isPrime.set();
	for(ll i=2; i<=n; ++i)
		if(isPrime[i])
		{
			cnt[i] += v[i];	
			for(ll j = 2*i; j<=maxx; j+=i)
			{
				isPrime[j] = 0;
				cnt[i] += v[j];
			}
		}
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int x;
		scanf("%d", &x);
		v[x]++;
		maxx = max(maxx, x);
	}
	
	sieve(MAX4-1);

	for(int i=1; i<=min(maxx, MAX4-1); ++i) cum[i] = cnt[i] + cum[i-1];

	scanf("%d", &m);
	while(m--)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", cum[min(r, min(maxx, MAX4-1))] - cum[min(l-1, min(maxx, MAX4-1))]);
	}

	return 0;
}
