#include<cstdio>
#include<cstring>

#define MAX (int) 1e6 + 10

int main()
{
	int n, mark[MAX], count, e;
	
	while(scanf("%d", &n) && n)
	{
		memset(mark, 0, sizeof(mark));
		count = 0;
		
		for(int i=0; i<n; ++i)
		{
			scanf("%d", &e);
			if(!mark[e])
				count += e+i;
			else
				count += i + 1 - mark[e];
			
			mark[e] = i+1;
		}
		
		printf("%d\n", count);
	}
	
	return 0;
}