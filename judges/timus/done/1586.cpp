#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;

#define PMAX 1005
#define MAX 10005
#define DMAX 10
#define MOD (int)(1e9 + 9)

bool isPrime[PMAX];
int dp[MAX][DMAX][DMAX], n;

int opt(int i, int last1, int last2)
{
	if(i == n) return 1;
	int &state = dp[i][last1][last2];
	if(state != -1) return state;

	int aux = 100*last1 + 10*last2, sol = 0;
	for(int j=0; j<10; ++j)
	{
		int num = aux + j;
		if(num >= 100 && isPrime[num]) sol = (sol + opt(i+1, last2, j))%MOD;
	}
	
	return state = sol;
}

int main()
{
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = 0;
	for(int i=100; i<=999; ++i)
		for(int j=2; ; ++j)
		{
			if(i%j == 0)
			{
				isPrime[i] = 0;
				break;
			}
			if(j*j > i) break;
		}
	
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));

	int sol = 0;
	for(int i=0; i<10; ++i)
		for(int j=0; j<10; ++j)
			sol = (sol + opt(2, i, j))%MOD;

	printf("%d\n", sol);	

	return 0;
}
