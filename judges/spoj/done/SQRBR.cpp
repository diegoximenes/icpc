#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 40

int n, q, t, x, dpCnt[MAX][MAX], dpCan[MAX][MAX];
char s[MAX];

int optCan(int i, int j)
{
	if(i > j) return 1;
	if(i == j || s[j] == '(') return 0;
	int &state = dpCan[i][j];
	if(state != - 1) return state;
	
	int sol = 0;
	for(int k=i+1; k<=j; ++k)
	{
		if(s[k] != '(') sol = optCan(i+1, k-1) && optCan(k+1, j);
		if(sol) break;
	}

	return state = sol;
}

int optCnt(int i, int j)
{
	if(i > j) return 1;
	if(i == j || s[j] == '(') return 0;
	int &state = dpCnt[i][j];
	if(state != -1) return state;
	
	int sol = 0;
	for(int k=i+1; k<=j; ++k)
		if(s[k] != '(' && optCan(i+1, k-1) && optCan(k+1, j))
			sol += optCnt(i+1, k-1) * optCnt(k+1, j);
	
	return state = sol;
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &q);
		memset(s, 0, sizeof(s));
		for(int i=0; i<q; ++i) scanf("%d", &x), s[x-1] = '(';
		
		memset(dpCnt, -1, sizeof(dpCnt));
		memset(dpCan, -1, sizeof(dpCan));
		printf("%d\n", optCnt(0, 2*n-1));
	}

	return 0;
}
