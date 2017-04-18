#include<stdio.h>

#define CMAX 21
#define VMAX 10010

int coin[21];
long long int pd[CMAX][VMAX];

long long int change(int t, int v)
{
	if((v < 0) || (t == CMAX))
		return 0;
	
	if(v == 0)
		return 1;
	
	if(pd[t][v] != -1)
		return pd[t][v];
	
	return pd[t][v] = change(t+1, v) + change(t, v - coin[t]);
	
}

int main()
{
	int n, i, j;
	
	for(i=1; i<=CMAX; ++i)
		coin[i-1] = i*i*i;
	
	for(i=0; i<CMAX; ++i)
		for(j=0; j<VMAX; ++j)
			pd[i][j] = -1;
	
	while(scanf("%d", &n) == 1)
		printf("%lld\n", change(0, n));
	
	return 0;
}