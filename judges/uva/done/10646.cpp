#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char v;
    char s;
}Card;

int main()
{
    int n;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
    {
	Card c[52];
	
	for(int j=0; j<52; j++)
	    scanf("%c%c ", &(c[j].v), &(c[j].s));
	
	int y = 0, k = 0, x;
	for(int j=0; j<3; j++)
	{
	    if((c[k].v == 'A') || (c[k].v == 'K') || (c[k].v == 'Q') || (c[k].v == 'J'))
		x = 10;
	    else
		x = atoi(&(c[k].v));
	    
	    y += x;
	    
	    k += 1 + 10 - x;
	}
	
	printf("Case %d: %c%c\n", i+1, c[k + y].v, c[k + y].s);
	
    }
    
    return 0;
}