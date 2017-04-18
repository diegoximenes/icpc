#include<bits/stdc++.h>
using namespace std;

#define MAX 5005

int dp[MAX][MAX], height[MAX], n;

int opt(int i, int j)
{
	if(i == n) return 0;
	int &state = dp[i][j];
	if(state != -1) return state;
	
	if(height[i] > j) state = 1 + opt(i+1, min(j, height[i]));
	else state = opt(i+1, min(j, height[i]));

	if(height[i] > j && j < MAX-1) state = min(state, 1 + opt(i, min(j+1, height[i])));

	return state;
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &height[i]);
	
	memset(dp, -1, sizeof(dp));
	printf("%d\n", opt(0, 0));

	return 0;
}
