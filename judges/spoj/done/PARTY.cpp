#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define INF 1e9
#define MAXN 105
#define MAXB 505

int dpFun[MAXB][MAXN], dpFee[MAXB][MAXN], fun[MAXN], fee[MAXN], n;

int optFun(int b, int i)
{
	if(i == n || b == 0) return 0;
	int &state = dpFun[b][i];
	if(state != -1) return state;

	int sol1 = optFun(b, i+1);
	int sol2 = 0;
	if(b - fee[i] >= 0) sol2 = fun[i] + optFun(b - fee[i], i+1);

	return state = max(sol1, sol2);
}

int optFee(int b, int i)
{
	if(i == n || b == 0) return 0;
	int &state = dpFee[b][i];
	if(state != -1) return state;

	int sol1 = optFun(b, i+1);
	int sol2 = 0;
	if(b - fee[i] >= 0) sol2 = fun[i] + optFun(b - fee[i], i+1);
	
	if(sol1 > sol2 || (sol2 == 0 && sol1 == 0)) return state = optFee(b, i+1);
	if(sol2 > sol1) return state = fee[i] + optFee(b - fee[i], i+1);
	return state = min(optFee(b, i+1), fee[i] + optFee(b - fee[i], i+1));
}

int main()
{
	int b;

	while(scanf("%d %d", &b, &n) && n)
	{
		for(int i=0; i<n; ++i) scanf("%d %d", &fee[i], &fun[i]);

		memset(dpFun, -1, sizeof(dpFun));
		memset(dpFee, -1, sizeof(dpFee));
		printf("%d %d\n", optFee(b, 0), optFun(b, 0));
	}

	return 0;
}
