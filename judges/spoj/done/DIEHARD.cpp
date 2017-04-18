#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int dp[3][2000][2000];
const int delta[3][2] = {{3, 2}, {-5, -10}, {-20, 5}};

int opt(int type, int h, int a)
{
	if(h <= 0 || a <= 0) return -1;
	if(dp[type][h][a] != -1) return dp[type][h][a];

	int sol = 0;
	for(int i=0; i<3; ++i)
		if(i != type)
			sol = max(sol, 1 + opt(i, h + delta[i][0], a + delta[i][1]));
	return dp[type][h][a] = sol;
}

int main()
{
	int tc, a, h;

	memset(dp, -1, sizeof(dp));
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d %d", &h, &a);
		printf("%d\n", max(opt(0, h, a), max(opt(1, h, a), opt(2, h, a))));
	}

	return 0;
}
