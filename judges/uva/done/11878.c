#include<stdio.h>
#include<string.h>

int main()
{
	int a, b, c, count = 0, k, i;
	char op, aux[4];
	
	while(scanf("%d%c%d=%s", &a, &op, &b, aux) == 4)
	{
		if(aux[0] == '?')
			continue;
		
		c = 0; k = 1;
		for(i=strlen(aux)-1; i>=0; --i, k*=10)
			c += (aux[i]-'0')*k;	
			
		if(op == '-')
			b *= -1;
		if(c == a+b)
			++count;
	}
	printf("%d\n", count);
	
	return 0;
}