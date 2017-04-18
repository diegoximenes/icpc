#include<cstdio>
#include<bitset>
using namespace std;

#define MAX 100000010
#define MAX2 100010

int n, point[MAX2];
bitset<MAX> mark;

int main()
{
	point[0] = 0;
	while(scanf("%d", &n) == 1)
	{
		int cum = 0, x; 
		mark.reset(); mark[0] = 1;
		for(int i=1; i<=n; ++i) 
		{
			scanf("%d", &x);
			cum += x;
			mark[cum] = 1;
			if(i < n) point[i] = x + point[i-1];
		}
		
		if(cum%3 != 0) puts("0");
		else
		{
			int count = 0;
			for(int i=0; i<n; ++i)
				if(mark[(point[i] + cum/3)%cum] && mark[(point[i] + 2*cum/3)%cum])
					++count;
			printf("%d\n", count/3);
		}
	}

	return 0;
}
