#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
#define MAX 110
#define MOD 1000000007

char num[MAX];
ll dp[10][12][MAX], comb[MAX][MAX];
int len, cnt[10], finalCntPos, finalCntNeg;

ll combination(int n, int k)
{
	if(k == n) return 1;
	if(k > n || n < 0 || k < 0) return 0;
	if(comb[n][k] != -1) return comb[n][k];
	return comb[n][k] = (combination(n-1, k-1) + combination(n-1, k))%MOD;
}


ll opt(int pos, int sum, int cntNeg)
{
	int sumCnt = 0;
	for(int i=0; i<pos; ++i) sumCnt += cnt[i];
	int cntPos = sumCnt - cntNeg;

	if(cntNeg > finalCntNeg || cntPos > finalCntPos) return 0;

	if(pos == 10) return (sum%11 == 0);
	
	ll &state = dp[pos][sum][cntNeg];
	if(state != -1) return state;
	
	if(!cnt[pos]) return state = opt(pos + 1, sum, cntNeg);
			
	ll combPos, combNeg;
	int sumPos, sumNeg;
	state = 0;
	int posLeft = finalCntPos - cntPos, negLeft = finalCntNeg - cntNeg;
	if(pos == 0)
	{
		if(len%2 == 0) negLeft--;
		else posLeft--;
	}
	if(posLeft < 0 || negLeft < 0) return state = 0;
	for(int i=0; i<=cnt[pos]; ++i)
	{		
		if(i > posLeft || cnt[pos] - i > negLeft) continue;
		combPos = combination(posLeft, i);
		combNeg = combination(negLeft, cnt[pos] - i);
	
		sumPos = (i*pos)%11;
		sumNeg = ((cnt[pos] - i)*pos)%11;
		int nsum = (sum + (sumPos - sumNeg)%11)%11;
		if(nsum < 0) nsum += 11;
		
		state = (state + (((combPos*combNeg)%MOD)*opt(pos + 1, nsum, cntNeg + cnt[pos] - i))%MOD)%MOD;	
	}

	return state;
}

int main()
{
	memset(comb, -1, sizeof(comb));
	for(int i=0; i<MAX; ++i)
		for(int j=0; j<MAX; ++j)
			combination(i, j);
	
	while(scanf(" %s", num) == 1)
	{
		len = strlen(num);
		finalCntPos = ceil((double)len/2.0);
		finalCntNeg = len/2;
		
		memset(cnt, 0, sizeof(cnt));
		for(int i=0; i<len; ++i) cnt[num[i] - '0']++;
		
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", opt(0, 0, 0));
	}

	return 0;
}
