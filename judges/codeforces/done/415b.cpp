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
#define EPS 1e-9

int main()
{
	int n;
	ll a, b, x;
	
	cin >> n >> a >> b;
	for(int i=0; i<n; ++i)
	{
		cin >> x;

		ll maxw = (x*a)/b, last=x;
		int l=0, r=x;
		while(l <= r)
		{
			int mid = (l + r)/2;

			ll midw = (mid*a)/b;
			if(midw == maxw) r = mid - 1, last = mid;
			else l = mid + 1;
		}
	
		if(i > 0) putchar(' ');
		cout << x-last;
	}
	puts("");

	return 0;
}
