#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int t, x, y, p, n;	

	scanf("%d", &t);
	while(t--)
	{
		p = 0;
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
		{
			scanf("%d %d", &x, &y);
			double d = hypot(x, y);
			for(int i=1; i<=10; ++i)
				if(d <= 20*i)
				{
					p += 11-i; 
					break;
				}	
		}
		printf("%d\n", p);
	}

	return 0;
}
