#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define MAX 60
#define INF 0x3f3f3f3f3f3f3f3fLL
#define KMAX 1000000010LL

int n;
ll dp[MAX][2][2], k;

ll opt(int i, int lower, int lastOne, ull mask)
{
	if(i == -1) return 1;
	ll &state = dp[i][lower][lastOne];
	if(state != -1) return state;
	
	state = -INF;
	if(lastOne) 
	{
		if(mask & (1LL << i)) state = opt(i-1, 1, 0, mask);
		else state = opt(i-1, lower, 0, mask);
	}
	else if(lower) state = opt(i-1, 1, 1, mask) + opt(i-1, 1, 0, mask);
	else if(!lower)
	{
		if(mask & (1LL << i)) state = opt(i-1, 0, 1, mask) + opt(i-1, 1, 0, mask);
		else state = opt(i-1, 0, 0, mask);
	}
	
	if(state > KMAX) state = KMAX;
	return state;
}

ll findLastLowerOrEqual(ull mask)
{
	for(int i=n-1; i>=1; --i)
		if((mask & (1LL << i)) && (mask & (1LL << (i-1))))
		{
			mask &= ~(1LL << (i-1));
			for(int j=i-2, k=0; j>=0; --j, k++)
			{
				if(k&1) mask &= ~(1LL << j);
				else mask |= (1LL << j);
			}
			break;
		}
	return mask;
}

int main()
{
	cin >> n >> k;
	
	bool solved = 0;
	ull sol;
	ull l = 0, r = (1LL << n);
	while(l <= r)
	{
		ull mid = (l+r)/2;

		memset(dp, -1, sizeof(dp));
		ll ret = opt(n-1, 0, 0, mid);
		if(ret == k)
		{
			//cout << "mid= " << mid << ", ret= " << ret << endl;
			sol = findLastLowerOrEqual(mid);
			solved = 1;
			break;
		}
		if(ret > k) r = mid-1;
		else l = mid+1;
	}
	
	if(!solved) puts("-1");
	else
	{
		for(int i=n-1; i>=0; --i)
		{
			if(sol & (1LL << i)) putchar('1');
			else putchar('0');
		}
		puts("");
	}

	return 0;
}
