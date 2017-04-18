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
#define INF 0x3f3f3f3f
#define EPS 1e-7
#define MAX 50

ll v[MAX];

int main()
{
	int t, n, k;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &k);
		for(int i=0; i<n; ++i) scanf("%lld", &v[i]);

		if(k > n)
		{
			puts("0");
			continue;
		}
		
		ll sol = 0;
		for(int bit=32; bit>=0; --bit)
		{
			vector<int> can;
			for(int i=0; i<n; ++i)
				if((1LL << bit) & v[i])
					can.pb(v[i]);

			if((int)can.size() < k) continue;
			sort(can.begin(), can.end());
			
			for(int i=0; i<(int)can.size(); ++i)
			{
				ll lsol = can[i];
				if(i + k - 1 >= (int)can.size()) break;
				for(int j=0; j<k; ++j)
				{
					lsol &= can[i+j];
				}
				
				sol = max(sol, lsol);
			}
		}

		printf("%lld\n", sol);
	}

	return 0;
}
