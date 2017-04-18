#include<cstdio>
#include<cstring>
using namespace std;

#define SUMMAX 85
#define DMAX 10

int dp[DMAX][SUMMAX];

int opt(int i, int s)
{
	if(i == 9)
	{
		if(s == 0) return 1;
		return 0;
	}
	int &state = dp[i][s];
	if(state != -1) return state;
	
	int sol = 0;
	for(int j=0; j<10; ++j)
		if(s - j >= 0)
			sol += opt(i+1, s - j);
	
	return state = sol;
}

int main()
{
	int s;

	scanf("%d", &s);

	memset(dp, -1, sizeof(dp));
	int sol = opt(0, s);
	if(s == 1) sol++;
	printf("%d\n", sol);

	return 0;
}
