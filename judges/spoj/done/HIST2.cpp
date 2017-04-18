#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

#define MAXN 16
#define MAXMASK (1 << 15)

int n, dp1[MAXMASK][MAXN], v[MAXN];
ll dp2[MAXMASK][MAXN];

int opt1(int mask, int last)
{
	if(__builtin_popcount(mask) == n) return v[last];
	int &state = dp1[mask][last];
	if(state != -1) return state;
	
	int sol = 0;
	for(int i=0; i<n; ++i)
		if(!((1 << i) & mask))
			sol = max(sol, opt1(mask | (1 << i), i) + 2 + abs(v[last] - v[i]));
	
	return state = sol;
}

ll opt2(int mask, int last)
{
	if(__builtin_popcount(mask) == n) return 1;
	ll &state = dp2[mask][last];
	if(state != -1) return state;
	
	ll sol = 0;
	for(int i=0; i<n; ++i)
		if(!((1 << i) & mask))
			if(opt1(mask | (1 << i), i) + 2 + abs(v[last] - v[i]) == opt1(mask, last))
				sol += opt2(mask | (1 << i), i);

	return state = sol;
}

int main()
{
	
	while(scanf("%d", &n) && n)
	{
		for(int i=0; i<n; ++i) scanf("%d", &v[i]);
		memset(dp1, -1, sizeof(dp1));
		memset(dp2, -1, sizeof(dp2));

		int sol1 = 0;
		ll sol2 = 0;
		for(int i=0; i<n; ++i) sol1 = max(sol1, opt1((1 << i), i) + 2 + v[i]); 
		for(int i=0; i<n; ++i)
			if(opt1((1 << i), i) + 2 + v[i] == sol1)
				sol2 += opt2((1 << i), i);

		printf("%d %lld\n", sol1, sol2);
	}


	return 0;
}
