#include<stdio.h>

int main()
{
    int x1, x2, y1, y2, i, flag;
    
    while(1)
    {
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	
	if(x1 == 0)
	    break;
	
	if((x2 == x1) && (y2 == y1))
	    printf("0\n");
	else if((x2 == x1) || (y2 == y1))
	    printf("1\n");
	else 
	{
	    flag = 0;
	    
	    i = 1;
	    while(!flag && (x1 + i <= 8) && (y1 + i <= 8))
	    {
		if((x1 + i == x2) && (y1 + i == y2))
		    flag = 1;
		
		++i;
	    }
	    
	    i = 1;
	    while(!flag && (x1 - i >= 1) && (y1 - i >= 1))
	    {
		if((x1 - i == x2) && (y1 - i == y2))
		    flag = 1;
		    
		++i;
	    }
	    
	    i = 1;
	    while(!flag && (x1 - i >= 1) && (y1 + i <= 8))
	    {
		if((x1 - i == x2) && (y1 + i == y2))
		    flag = 1;
		    
		++i;
	    }
	    
	    i = 1;
	    while(!flag && (x1 + i <= 8) && (y1 - i >= 1))
	    {
		if((x1 + i == x2) && (y1 - i == y2))
		    flag = 1;
		    
		++i;
	    }
	    
	    if(flag)
		printf("1\n");
	    else
		printf("2\n");
	}
    }
    
    return 0;
}