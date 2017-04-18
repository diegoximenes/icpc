#include<cstdio>
using namespace std;

#define MAX 1001
#define MAX2 6*MAX
#define DICE 6

double p[MAX][MAX2], prob = 1.0/6.0;

double solve(int n, int k)
{
	if(p[n][k] != -1.0)
		return p[n][k];
	if(n == 0)
	{
		if(k != 0)
			return p[n][k] = 0.0;
		else
			return p[n][k] = 1.0;
	}
	
	p[n][k] = 0.0;
	for(int i=1; i<=DICE; ++i)
	{
		if(k-i >= 0)
			p[n][k] += prob*solve(n-1, k-i);
		else
			break;
	}
	
	return p[n][k];
}

int main()
{
	int t, n, k;
	
	for(int i=0; i<MAX; ++i)
		for(int j=0; j<MAX2; ++j)
			p[i][j] = -1.0;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &k);
		if(n > MAX || k > MAX2)
			puts("0");
		else
			printf("%d\n", (int)(100*solve(n, k)));
	}
	
	return 0;
}