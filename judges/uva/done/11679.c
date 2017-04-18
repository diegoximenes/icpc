#include<stdio.h>

int main()
{
	int n, b, i, r[25], d, c, v, divida;
	
	while(scanf("%d %d", &b, &n))
	{
		if(!b && !n)
			break;
		
		for(i=1; i<=b; ++i)
			scanf("%d", &r[i]);
		
		for(i=0; i<n; ++i)
		{
			scanf("%d %d %d", &d, &c, &v);
			r[d] -= v; 
			r[c] += v;
		}
		
		divida = 0;
		for(i=1; i<=b; ++i)
			if(r[i] < 0)
			{
				divida = 1;
				break;
			}
		
		if(divida)
			puts("N");
		else
			puts("S");
	}
	
	return 0;
}