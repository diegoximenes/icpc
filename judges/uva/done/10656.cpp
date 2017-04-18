#include<cstdio>
using namespace std;

#define MAX 1000+10

int main()
{
	int n, a;
	
	while(scanf("%d", &n) && n)
	{
		bool printed = 0;
		while(n--)
		{
			scanf("%d", &a);
			if(a)
			{
				if(printed)
					printf(" %d", a);
				else
				{
					printf("%d", a);
					printed = 1;
				}
			}
		}
		if(!printed)
			puts("0");
		else 
			puts("");
	}
	
	return 0;
}