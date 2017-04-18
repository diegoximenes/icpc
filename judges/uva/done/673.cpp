//17:40 - 18:21

#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;

int main()
{
    int n;
    char s[128], c;
    
    scanf("%d%c", &n, &c);
    
    for(int i=0; i<n; i++)
    {
	memset(s, 0, 128);
	stack<char> p;

	for(int j=0; ; j++)
	{
	    if(scanf("%c", &c) == EOF)
		break;
	    if(c == '\n')
		break;
	    
	    s[j] = c;
	}
	
	//printf("%d - %s - %d\n", i, s, strlen(s));
	
	bool ok = 1;
	for(int j=0; j<strlen(s); j++)
	{
	    if((s[j] == '(') || (s[j] == '['))
		p.push(s[j]);
	    else if(p.empty())
	    {
		ok = 0;
		break;
	    }
	    else if(((s[j] == ')') && (p.top() == '(')) || ((s[j] == ']') && (p.top() == '[')))
		p.pop();
	    else
	    {
		ok = 0;
		break;
	    }
	}
	
	if((ok == 0) || (!p.empty()))
	    printf("No\n");
	else
	    printf("Yes\n");
    }
    
    return 0;
}
