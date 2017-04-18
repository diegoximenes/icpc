#include<cstdio>
using namespace std;

#define MAX 10010

int main()
{
	int d, p, n;
	double v[MAX];
	char line[1000000];
	
	while(gets(line) != NULL)
	{
		int pt = 0, k, x;
		n = 0;
		while(sscanf(line + pt, " %d%n", &x, &k) == 1)
		{
			if(n == 0) d = x;
			else if(n == 1) p = x;
			else v[n-2] = x;
			++n, pt += k;
		}
		
		n -= 2;	
		if(p < v[0]) puts("The spider is going to fall!");
		else
		{
			bool solved = 0;
			for(int i=0; i<d; ++i)
			{
				if(i >= n)
				{
					double a, b;
					if(v[i-4] == 0) a = v[i-2]/v[i-3], b = (v[i-1] - v[i-2]*a)/v[i-3];
					else
					{
						b = (v[i-2]*v[i-2] - v[i-1]*v[i-3])/(v[i-4]*v[i-2] - v[i-3]*v[i-3]);
						a = (v[i-1] - b*v[i-3])/v[i-2];
					}
					v[i] = a*v[i-1] + b*v[i-2];
				}
				if(v[i] > p)
				{
					printf("%d\n", d-i+1);
					solved = 1;
					break;
				}
			}
			if(!solved) puts("The spider may fall!");
		}
	}

	return 0;
}
