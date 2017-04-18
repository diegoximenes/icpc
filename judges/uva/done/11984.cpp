#include<stdio.h>

int main()
{
    int t, c, d;
    
    scanf("%d", &t);
    
    for(int i=1; i<=t; i++)
    {
	scanf("%d %d", &c, &d);
	
	float r, f = 9.0/5.0*c + 32 + d;
	r = (f - 32)*5.0/9.0;
	
	printf("Case %d: %.2f\n", i, r);
    }
    
    return 0;
}