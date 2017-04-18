#include<stdio.h>

int main()
{
	int n, count, q;
	
	while(scanf("%d", &n) && n)
	{
		count = 0;
		while(n--)
		{
			scanf("%*d %d", &q);
			if(q>1)
			{
				if(q%2==0)
					count += q;
				else
					count += q-1;
			}
		}
		printf("%d\n", count/4);
	}
	
	return 0;
}