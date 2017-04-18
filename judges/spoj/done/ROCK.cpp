#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 205

int t, n, dp[MAX], sum[MAX];
char s[MAX];

inline int cum(int i, int j)
{
	if(i - 1 >= 0) return (sum[j] - sum[i - 1]);
	return sum[j];
}

int opt(int i)
{
	if(i == n) return 0;
	int &state = dp[i];
	if(state != -1) return state;

	int sol = 0;
	for(int j=i; j<n; ++j)
	{
		int auxsol = 0;
		if(cum(i, j) > (j-i+1) - cum(i, j)) auxsol = (j-i+1);
		sol = max(sol, auxsol + opt(j+1));
	}
	
	return state = sol;
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %s ", &n, s);
		
		for(int i=0; i<n; ++i)
		{
			if(s[i] == '0') sum[i] = 0;
			else sum[i] = 1;
			
			if(i > 0) sum[i] += sum[i-1];
		}
		
		memset(dp, -1, sizeof(dp));
		printf("%d\n", opt(0));
	}

	return 0;
}
