#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 105
#define INF 1e9

char s[MAX];
int dp[MAX][MAX];

int solve(int i, int j)
{
	if(j < i)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	if(i == j)
		return dp[i][j] = 1;
	
	int count = INF;
	if(s[i]==')' && s[i]==']')
		return dp[i][j] = 1 + solve(i+1, j);
	if(s[j]=='(' && s[j]=='[')
		return dp[i][j] = 1 + solve(i, j-1);
	if((s[i]=='(' && s[j]==')') || (s[i]=='[' && s[j]==']'))
		count = solve(i+1, j-1);
	
	for(int k=i; k<j; ++k)
		count = min(count, solve(i, k) + solve(k+1, j));
	
	return dp[i][j] = count;
}

void print(int i, int j)
{
	if(j < i)
		return;
	if(i == j)
	{
		if(s[i]==')' || s[i]=='(')
			printf("()");
		else
			printf("[]");
	}
	else if(s[i]==')')
	{
		printf("()");
		print(i+1, j);
	}
	else if(s[i]==']')
	{
		printf("[]");
		print(i+1, j);
	}
	else if(s[j]=='[')
	{
		print(i, j-1);
		printf("[]");
	}
	else if(s[j]=='(')
	{
		print(i, j-1);
		printf("()");
	}
	else if(((s[i]=='(' && s[j]==')') || (s[i]=='[' && s[j]==']')) && (j==i+1 || dp[i][j] == dp[i+1][j-1]))
	{
		putchar(s[i]);
		print(i+1, j-1);
		putchar(s[j]);
	}
	else
		for(int k=i; k<j; ++k)
			if(dp[i][j] == dp[i][k] + dp[k+1][j])
			{
				print(i, k);
				print(k+1, j);
				break;
			}
}

int main()
{
	memset(dp, -1, sizeof(dp));
	
	gets(s);
	int len = strlen(s)-1;
	solve(0, len);
	print(0, len); puts("");
	
	return 0;
}