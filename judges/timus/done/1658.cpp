#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int dp[905][8105], t, n;

int opt(int sum, int squaredSum)
{
	if(sum > 900 || squaredSum > 8100) return INF;
	if(sum < 0 || squaredSum < 0) return INF;
	if(!sum && !squaredSum) return 0;
	if(!sum || !squaredSum) return INF;
	int &state = dp[sum][squaredSum];
	if(state != -1) return state;

	int sol = INF;
	for(int i=1; i<=9; ++i) sol = min(sol, 1 + opt(sum - i, squaredSum - i*i));

	return state = sol;
}

void print(int sum, int squaredSum)
{
	if(sum > 900 || squaredSum > 8100) return;

	for(int i=1; i<=9; ++i)
		if(opt(sum, squaredSum) == 1 + opt(sum - i, squaredSum - i*i))
		{
			printf("%d", i);
			print(sum - i, squaredSum - i*i);
			return;
		}
}

int main()
{
	memset(dp, -1, sizeof(dp));

	scanf("%d", &t);
	while(t--)
	{
		int sum, squaredSum;
		scanf("%d %d", &sum, &squaredSum);
		int sol = opt(sum, squaredSum);
		if(sol > 100) puts("No solution");
		else print(sum, squaredSum), puts("");
	}

	return 0;
}
