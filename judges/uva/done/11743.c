#include<stdio.h>

int main()
{
    int n, i, v[17], sum;
    char c;
    
    scanf("%d", &n);
    
    while(n--)
    {
	getchar();
	for(i=1; i<=16; ++i)
	{
	    scanf("%c", &c);
	    if(c == ' ')
		scanf("%c", &c);
	    v[i] = c - '0';
	}
	
	sum = 0;
	for(i=1; i<=16; i+=2)
	    sum += (2*v[i])%10 + (2*v[i]/10)%10;
	
	for(i=2; i<=16; i+=2)
	    sum += v[i];
		
	if(sum%10 != 0)
	    printf("Invalid\n");
	else
	    printf("Valid\n");
    }
    
    return 0;
}