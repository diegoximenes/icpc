#include<stdio.h>

int main()
{
	int h1, m1, h2, m2, m;
	
	while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2))
	{
		if(!h1 && !m1 && !h2 && !m2)
			break;
		
		if((h2 < h1) || ((h2 == h1) && (m2 < m1)))
			m = 24*60 - (h1*60 + m1) + (h2*60 + m2);
		else
			m = (h2*60 + m2) - (h1*60 + m1);
		
		printf("%d\n", m);
	}
	
	return 0;
}