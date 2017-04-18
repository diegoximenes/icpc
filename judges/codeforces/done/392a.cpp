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
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define INF 1e9

int main()
{
	ll n, sol = 0, last = 1;

	cin >> n;
	if(n == 0) puts("1");
	else
	{
		for(ll i=1; last <= n; ++i)
		{
			if(i*i + (n-last)*(n-last) > n*n) last++;
			else
			{
				sol += n-i;
				if(i > 1) sol -= n-i-1;
			}
		}

		sol = sol*4 + 4;
		cout << sol << endl;
	}

	return 0;
}
