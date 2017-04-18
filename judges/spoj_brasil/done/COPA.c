#include<stdio.h>

int main()
{
	int j, p, t, v;
	
	while(scanf("%d %d", &t, &j) && t)
	{
		p = 0;
		while(t--)
		{
			scanf("%*s %d", &v);
			p += v;
		}
		printf("%d\n", 3*j-p);
	}
	
	return 0;
}