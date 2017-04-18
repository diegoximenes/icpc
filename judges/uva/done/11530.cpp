#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    char c;
    
    scanf("%d%c", &n, &c);
    
    for(int i=0; i<n; i++)
    {
	char s[100];
	memset(s, 0, 100);

	gets(s);
	
	int nk = 0;
	for(int j=0; j < strlen(s); j++)
	{
	    if((s[j] == 'a') || (s[j] == 'd') || (s[j] == 'g') || (s[j] == 'j') || (s[j] == 'm') || (s[j] == 'p') || (s[j] == 't') || (s[j] == 'w') || (s[j] == ' '))
	    {
		nk++;
	    }
	    else if((s[j] == 'b') || (s[j] == 'e') || (s[j] == 'h') || (s[j] == 'k') || (s[j] == 'n') || (s[j] == 'q') || (s[j] == 'u') || (s[j] == 'x'))
	    {
		nk += 2;
	    }
	    else if((s[j] == 'c') || (s[j] == 'f') || (s[j] == 'i') || (s[j] == 'l') || (s[j] == 'o') || (s[j] == 'r') || (s[j] == 'v') || (s[j] == 'y'))
	    {
		nk += 3;
	    }
	    else if((s[j] == 's') || (s[j] == 'z'))
	    {
		nk += 4;
	    }
	}
	
	printf("Case #%d: %d\n", i+1, nk);
    }
    
    return 0;
}