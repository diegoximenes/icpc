#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 1e9
#define MAX 105

int dpMax[MAX][MAX], dpMin[MAX][MAX];
char s[MAX];

int optMax(int i, int j)
{
	if(i == j) return (s[i] -'0');
	int &state = dpMax[i][j];
	if(state != - 1) return state;
	
	int sol = -INF;
	for(int k=i+1; k<j; ++k)
	{
		if(s[k] == '+') sol = max(sol, optMax(i, k-1) + optMax(k+1, j));
		else if(s[k] == '*') sol = max(sol, optMax(i, k-1) * optMax(k+1, j));
	}

	return state = sol;
}

int optMin(int i, int j)
{
	if(i == j) return (s[i] -'0');
	int &state = dpMin[i][j];
	if(state != - 1) return state;
	
	int sol = INF;
	for(int k=i+1; k<j; ++k)
	{
		if(s[k] == '+') sol = min(sol, optMin(i, k-1) + optMin(k+1, j));
		else if(s[k] == '*') sol = min(sol, optMin(i, k-1) * optMin(k+1, j));
	}

	return state = sol;
}


int main()
{
	int t;

	scanf("%d", &t);
	while(t--)
	{
		scanf(" %s ", s);
		memset(dpMax, -1, sizeof(dpMax));
		memset(dpMin, -1, sizeof(dpMin));
		printf("%d %d\n", optMax(0, strlen(s)-1), optMin(0, strlen(s)-1));
	}

	return 0;
}
