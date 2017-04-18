#include<stdio.h>
#include<string.h>

bool cmp(char a, char b)
{
    if(((a == 'A') && (b == 'A')) || ((a == 'E') && (b == '3')) || ((a == '3') && (b == 'E')) || ((a == 'H') && (b == 'H')) || ((a == 'I') && (b == 'I'))
	|| ((a == 'J') && (b == 'L')) || ((a == 'L') && (b == 'J')) || ((a == 'M') && (b == 'M')) || ((a == 'O') && (b == 'O')) || ((a == 'S') && (b == '2'))
	|| ((a == '2') && (b == 'S')) || ((a == 'T') && (b == 'T')) || ((a == 'U') && (b == 'U')) || ((a == 'V') && (b == 'V')) || ((a == 'W') && (b == 'W'))
	|| ((a == 'W') && (b == 'W')) || ((a == 'X') && (b == 'X')) || ((a == 'Y') && (b == 'Y')) || ((a == 'Z') && (b == '5')) || ((a == '5') && (b == 'Z'))
	|| ((a == '1') && (b == '1')) || ((a == '8') && (b == '8')))
    {
	return true;
    }
    else
	return false;
}

int main()
{
    char s[20];
    
    while(scanf("%s\n", s) != EOF)
    {
	bool pal = 1, mir = 1;
	
	//pal
	int k = strlen(s) - 1;
	for(int i=0; (i < strlen(s)) || (k > i); i++)
	{
	    if(s[i] != s[k])
	    {
		pal = 0;
		break;
	    }
	    else
		k--;
	}
	
	//mir
	k = strlen(s) - 1;
	for(int i=0; (i < strlen(s)) || (k > i); i++)
	{
	    if(!cmp(s[i], s[k]))
	    {
		mir = 0;
		break;
	    }
	    else
		k--;
	}
	
	printf("%s -- ", s);
	if(pal && mir) printf("is a mirrored palindrome.\n\n");
	else if(pal) printf("is a regular palindrome.\n\n");
	else if(mir) printf("is a mirrored string.\n\n");
	else printf("is not a palindrome.\n\n");
	
	memset(s, 0, 20);
    }
    
    return 0;
}