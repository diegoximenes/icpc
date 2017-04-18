#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int val(char c)
{
    if(c == '0') return 0;
    else if(c == '1') return 1;
    else if(c == '2') return 2;
    else if(c == '3') return 3;
    else if(c == '4') return 4;
    else if(c == '5') return 5;
    else if(c == '6') return 6;
    else if(c == '7') return 7;
    else if(c == '8') return 8;
    else if(c == '9') return 9;
    else if(c == 'X') return 10;
    else return -1;
}

int main()
{
    char c = 0;
    while(1)
    {
	int i = 0, fram = 0, p = 0;
	char s[23];
	memset(s, 0, 23);
	
	while(1)
	{
	    scanf("%c", &c);
	    
	    if(c == ' ') continue;
	    if(c == '\n') break;
	    if(c == 'G') break;
	    
	    s[i] = c;
	    
	    i++;
	}
	
	if(c == 'G') break;
	
	//printf("%s, i = %d\n", s, i);
	
	bool infram = 0;
	for(int k=0; k<i; k++)
	{
	    c = s[k];
	    
	    //printf("fram = %d, infram = %d, ", fram, infram);
	    
	    if((val(c) < 10) && (val(c) >= 0))//numero
	    {
		p += val(c);
		
		if(infram == 0)
		    infram = 1;
		else
		{
		    infram = 0;
		    fram++;
		}
	    }
	    else if(c == 'X')
	    {
		if(fram >= 9)
		{
		    p+= 10;
		    fram++;
		    infram = 0;
		}
		else
		{
		    if(s[k+2] == '/') 
			p += 10 + 10;
		    else
			p += 10 + val(s[k+1]) + val(s[k + 2]);
		    
		    fram++;
		    infram = 0;
		}
	    }
	    else if(c == '/')
	    {
		if(fram >= 9)
		{
		    p+= 10;
		    p -= val(s[k-1]);
		    fram++;
		    infram = 0;
		}
		else
		{
		    p -= val(s[k-1]);
		    p += 10 + val(s[k+1]);
		    
		    fram++;
		    infram = 0;
		}
	    }
	    
	    //printf("k = %d, c = %c, p = %d\n", k, c, p);
	}
	
	if(p > 300) p = 300;
	printf("%d\n", p);
	
	//printf("p=%d\n", p);
    }
    
    return 0;
}