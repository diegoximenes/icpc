#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 300000+10
#define ll long long

int n, k;
ll v, dp[MAX][2], tree[MAX];
bool firstPrint = 1;

void update(int idx , ll val)
{
	while (idx <= n)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

ll read(int idx)
{
	ll sum = 0;
	while (idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

ll opt(int i, int count)
{
	if(count > 1)
		return 0;
	if(i > n || i+k-1 > n)
		return 0;
	if(dp[i][count] != -1)
		return dp[i][count];
	
	return dp[i][count] = max(read(i + k - 1) - read(i - 1) + opt(i + k, count + 1), opt(i + 1, count));
}

void printSol(int i, int count)
{
	if(i > n || count > 1)
		return;

	if(dp[i][count] == read(i + k - 1) - read(i - 1) + opt(i + k, count + 1))
	{
		if(firstPrint)
		{
			printf("%d", i);
			firstPrint = 0;
		}
		else
			printf(" %d", i);
		printSol(i + k, count+1);
	}
	else
		printSol(i + 1, count);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	memset(tree, 0, sizeof(tree));
	dp[0][0] = dp[0][1] = 0;
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; ++i)
	{
		cin >> v;
		update(i, v);
	}

	opt(1, 0);
	printSol(1, 0);
	puts("");
	/*for(int i=1; i<=n; ++i)
		printf("i= %d, dp= %d, tree= %d\n", i, dp[i], tree[i]);*/
	
	return 0;
}
