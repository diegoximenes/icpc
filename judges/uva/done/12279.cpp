#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	int n, fut, past, i, test=0;
	
	while(scanf("%d", &n) && n)
	{
		past =0; fut =0;
		while(n--)
		{
			scanf("%d", &i);
			if(i>=1 && i<=99)
				fut++;
			else if(i == 0)
				past++;
		}
		printf("Case %d: %d\n", ++test, fut-past);
	}

	return 0;
}
