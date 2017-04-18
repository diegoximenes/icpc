#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define MAX 65

ll dp[MAX][MAX][2][2], k, m;
ull lowerBound, upperBound;

ll opt(int i, int cntOneBits, int greaterLowerBound, int lowerUpperBound)
{
	if(cntOneBits > k) return 0;
	if(i == -1) return (cntOneBits == k);
	ll &state = dp[i][cntOneBits][greaterLowerBound][lowerUpperBound];
	if(state != -1) return state;
	
	if(greaterLowerBound && lowerUpperBound) state = opt(i-1, cntOneBits, 1, 1) + opt(i-1, cntOneBits+1, 1, 1);
	else if(!greaterLowerBound && lowerUpperBound)
	{ 
		if(lowerBound & (1LL << i)) state = opt(i-1, cntOneBits+1, 0, 1);
		else state = opt(i-1, cntOneBits, 0, 1) + opt(i-1, cntOneBits+1, 1, 1);
	}
	else if(greaterLowerBound && !lowerUpperBound)
	{
		if(upperBound & (1LL << i)) state = opt(i-1, cntOneBits, 1, 1) + opt(i-1, cntOneBits+1, 1, 0);
		else state = opt(i-1, cntOneBits, 1, 0);
	}
	else if(!greaterLowerBound && !lowerUpperBound)
	{
		bool mask1 = (lowerBound & (1LL << i)), mask2 = (upperBound & (1LL << i));
		if(mask1 && mask2) state = opt(i-1, cntOneBits+1, 0, 0);
		else if(!mask1 && !mask2) state = opt(i-1, cntOneBits, 0, 0);
		else if(!mask1 && mask2) state = opt(i-1, cntOneBits, 0, 1) + opt(i-1, cntOneBits+1, 1, 0);
		else if(mask1 && !mask2) state = 0;
	}

	return state;
}

int main()
{
	cin >> m >> k;
	
	ll l = 1, r = 1000000000000000000LL;
	while(l <= r)
	{
		ll mid = (l+r)/2;
		
		memset(dp, -1, sizeof(dp));
		lowerBound = mid+1; upperBound = mid*2LL;
		ll sol = opt(63, 0, 0, 0);
		if(sol == m)
		{
			cout << mid << endl;
			return 0;
		}
		else if(sol > m) r = mid-1;
		else l = mid+1;
	}

	return 0;
}
