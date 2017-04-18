#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 105
#define INF (int) 1e9

char s1[MAX], s2[MAX], t[MAX], p[MAX];
int b[MAX], m, n1, n2, dp[MAX][MAX][MAX];

void kmpPreProcess()
{
	int i=0, j= -1;
	b[0] = -1;
	while(i < m)
	{
		while(j >= 0 && p[i] != p[j]) j = b[j];
		++i; ++j;
		b[i] = j;
	}
}

int kmpSearch(int n)
{
	int i=0, j=0;
	while(i < n)
	{
		while(j >= 0 && t[i] != p[j]) j = b[j];
		++i; ++j;
		if(j == m) break;
	}
	return j;
}

int opt(int i1, int i2, int lenp, int lens)
{
	if(lenp == m) return dp[i1][i2][lenp] = -INF;
	if(i1 == n1 || i2 == n2) return 0;
	if(dp[i1][i2][lenp] != -1) return dp[i1][i2][lenp];

	int sol1 = -INF, sol2, sol3;
	if(s1[i1] == s2[i2]) 
	{
		char aux = t[lens];
		t[lens] = s1[i1];
		sol1 = 1 + opt(i1 + 1, i2 + 1, kmpSearch(lens+1), lens + 1);
		t[lens] = aux;
	}
	sol2 = opt(i1 + 1, i2, lenp, lens);
	sol3 = opt(i1, i2 + 1, lenp, lens);
	return dp[i1][i2][lenp] = max(sol1, max(sol2, sol3));
}

void print(int i1, int i2, int lenp, int lens)
{
	if(lenp == m) return;
	if(i1 == n1 || i2 == n2) return;
	
	if(s1[i1] == s2[i2]) 
	{
		char aux = t[lens];
		t[lens] = s1[i1];
		if(opt(i1, i2, lenp, lens) == 1 + opt(i1 + 1, i2 + 1, kmpSearch(lens+1), lens + 1))
		{
			putchar(s1[i1]);
			print(i1 + 1, i2 + 1, kmpSearch(lens+1), lens + 1);
			return;
		}
		t[lens] = aux;
	}
	if(opt(i1, i2, lenp, lens) == opt(i1 + 1, i2, lenp, lens)) print(i1 + 1, i2, lenp, lens);
	else print(i1, i2 + 1, lenp, lens);
}

int main()
{
	scanf("%s %s %s", s1, s2, p);
	n1 = strlen(s1); n2 = strlen(s2); m = strlen(p);
	memset(dp, -1, sizeof(dp));
	
	kmpPreProcess();
	opt(0, 0, 0, 0);
	if(opt(0, 0, 0, 0) > 0) print(0, 0, 0, 0);
	else putchar('0');
	puts("");

	return 0;
}
