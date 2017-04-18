#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<list>
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
#define INF 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9

int main()
{
	ll n, a, b, sol = INF, la, lb, b2;
	
	cin >> n >> a >> b;
	
	if(a*b >= n*6LL) la = a, lb = b, sol = a*b;
	else
	{
		bool swaped = 0;
		if(b < a) swaped = 1, swap(a, b);
		
		ll upper = 1000000LL;
		for(ll a2=a; a2<=upper; ++a2)
		{
			b2 = (n*6LL)/a2;
			if((n*6LL) % a2 != 0) b2++;
			
			if(a2 < a) a2 = a;
			if(b2 < b) b2 = b;
			if(a2*b2 < sol && a2*b2 >= (n*6LL))
			{
				//cout << "a2= " << a2 << ", b2= " << b2 << endl;
				sol = a2*b2;
				la = a2; lb = b2;
			}
		}

		if(swaped) swap(la, lb);
	}

	cout << sol << endl << la << " " << lb << endl;

	return 0;
}
