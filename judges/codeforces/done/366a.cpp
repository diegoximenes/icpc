#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n, a, b, c, d;
	
	scanf("%d", &n);
	for(int i=0; i<4; ++i)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int c1 = min(a, b), c2 = min(c, d);
		if(c1 + c2 > n) continue;
		else if(c1 + c2 == n)
		{
			printf("%d %d %d\n", i+1, c1, c2);
			return 0;
		}
		else
		{ 
			if(c1 > c2) printf("%d %d %d\n", i+1, n-c1-c2+c1, c2);
			else printf("%d %d %d\n", i+1, c1, n-c1-c2+c2);
			return 0;
		}
	}
	puts("-1");
			
	return 0;
}
