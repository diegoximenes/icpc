#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char s[100000];
    int i, j, flag;
    
    while(gets(s))
    {
	if(!strcmp(s, "DONE"))
	    break;
	    
	j = strlen(s) - 1;
	i = 0;
	flag = 0;
	while(j > i)
	{
	    if(isalpha(s[i]) && isalpha(s[j]))
	    {
		if(tolower(s[i]) != tolower(s[j]))
		{
		    flag = 1;
		    break;
		}
		++i;
		--j;
	    }
	    else
	    {
		if(!isalpha(s[i]))
		    ++i;
		if(!isalpha(s[j]))
		    --j;
	    }
	}
	
	if(!flag)
	    printf("You won't be eaten!\n");
	else
	    printf("Uh oh..\n");
    }
    
    return 0;
}