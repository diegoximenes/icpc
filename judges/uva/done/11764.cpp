#include<stdio.h>

int main()
{
    int t, n;
    
    scanf("%d", &t);
    
    for(int i=0; i<t; i++)
    {
	scanf("%d", &n);
	
	int h1, h2, lj = 0, hj = 0;
	
	scanf("%d", &h1);
	
	for(int j=1; j<n; j++)
	{
	    scanf("%d", &h2);
	    
	    if(h2 > h1) hj++;
	    else if(h2 < h1) lj++;
	    
	    h1 = h2;
	}
	
	printf("Case %d: %d %d\n", i+1, hj, lj);
    }
    
    return 0;
}