#include<cstdio>
#include<vector>
using namespace std;

#define MAX 110
#define MAX2 32001

bool solved;
int v[MAX], dp[MAX][2*MAX2], n;
vector<char> ans;

bool can(int n)
{
	if(n < -32000 || n > 32000)
		return 0;
	return 1;
}

bool solve(int op, int res, int target)
{
	int nop = op+1, idres = res + MAX2 - 1;
	
	if(dp[op][idres] != -1)
		return dp[op][idres];

	if(op == n && res == target)
		return dp[op][idres] = 1;
	else if(op == n)
		return dp[op][idres] = 0;
	
	if(can(res + v[op]) && solve(nop, res + v[op], target))
	{
		ans.push_back('+');
		return dp[op][idres] = 1;
	}
	if(can(res - v[op]) && solve(nop, res - v[op], target))
	{
		ans.push_back('-');
		return dp[op][idres] = 1;
	}
	if(can(res*v[op]) && solve(nop, res*v[op], target))
	{
		ans.push_back('*');
		return dp[op][idres] = 1;
	}
	if(res%v[op]==0 && solve(nop, res/v[op], target))
	{
		ans.push_back('/');
		return dp[op][idres] = 1;
	}
	
	return dp[op][idres] = 0;
}

int main()
{
	int t, target;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
			scanf("%d", &v[i]);
		scanf("%d", &target);
		
		for(int i=0; i<=n; ++i)
			for(int j=0; j<2*MAX2; ++j)
				dp[i][j] = -1;
		
		ans.clear();
		if(!solve(1, v[0], target))
			puts("NO EXPRESSION");
		else
		{
			int j = 0;
			for(int i=ans.size()-1; i>=0; --i)
				printf("%d%c", v[j++], ans[i]);
			printf("%d=%d\n", v[j], target);
		}
				
	}
	
	return 0;
}
