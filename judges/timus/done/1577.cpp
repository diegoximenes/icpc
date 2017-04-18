#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX 2005
#define MOD 1000000007

int dpLen[MAX][MAX], dpCount[MAX][MAX], n, m;
char s1[MAX], s2[MAX];

int optLen(int i, int j)
{
	if(i == n && j == m) return 1;
	int &state = dpLen[i][j];
	if(state != -1) return state;
	
	int sol = INF;
	if(i < n && j < m && s1[i] == s2[j]) sol = min(sol, 1 + optLen(i+1, j+1));
	else
	{
		if(i < n) sol = min(sol, 1 + optLen(i+1, j)); 
		if(j < m) sol = min(sol, 1 + optLen(i, j+1)); 
	}

	return state = sol;
}

int optCount(int i, int j)
{
	if(i == n && j == m) return 1;
	int &state = dpCount[i][j];
	if(state != -1) return state;

	int sol = 0;
	if(i < n && j < m && s1[i] == s2[j] && optLen(i, j) == 1 + optLen(i+1, j+1)) sol = (sol + optCount(i+1, j+1)) % MOD;
	else
	{
		if(i < n && optLen(i, j) == 1 + optLen(i+1, j)) sol = (sol + optCount(i+1, j)) % MOD; 
		if(j < m && optLen(i, j) == 1 + optLen(i, j+1)) sol = (sol + optCount(i, j+1)) % MOD; 
	}

	return state = sol;
}

int main()
{
	scanf(" %s %s ", s1, s2);
	n = strlen(s1); m = strlen(s2);

	memset(dpLen, -1, sizeof(dpLen));
	memset(dpCount, -1, sizeof(dpCount));
	printf("%d\n", optCount(0, 0));

	return 0;
}
