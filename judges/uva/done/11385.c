#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 110

int main()
{
	int fib[MAX], i, t, v[MAX], j, n;
	char in[MAX], out[MAX];
	
	fib[0] = 1; fib[1] = 2;
	for(i=2; i<MAX; ++i)
		fib[i] = fib[i-1] + fib[i-2];
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i=0; i<n; ++i)
			scanf("%d", &v[i]);
		getchar();
		gets(in);
		for(i=0, j=0; j<n; ++i)
			if(isalpha(in[i]) && !islower(in[i]))
			{
				in[j] = in[i];
				++j;
			}
		
		memset(out, 0, sizeof out);
		for(i=0; i<n; ++i)
		{
			for(j=0; j<MAX; ++j)
				if(fib[j] == v[i])
					break;
				
			if(j != MAX)
				out[j] = in[i];
		}
		
		for(i=0, j=0; j<n; ++i)
		{
			if(out[i] == 0)
				putchar(' ');
			else
			{
				putchar(out[i]);
				++j;
			}
		}
		putchar('\n');
	}
	
	return 0;
}