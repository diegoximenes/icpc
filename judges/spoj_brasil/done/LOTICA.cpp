#include<cstdio>
using namespace std;

int main()
{
	int n, a, b, c, d, e;
	bool A, B, C, D, E;
	
	while(scanf("%d", &n) && n)
	{
		while(n--)
		{
			int p = 0;
			A = B = C = D = E = 0;
			scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
			if(a <= 127)
			{
				A = 1;
				++p;
			}
			if(b <= 127)
			{
				B = 1;
				++p;
			}
			if(c <= 127)
			{
				C = 1;
				++p;
			}
			if(d <= 127)
			{
				D = 1;
				++p;
			}
			if(e <= 127)
			{
				E = 1;
				++p;
			}
			
			if(p != 1)
				puts("*");
			else if(A)
				puts("A");
			else if(B)
				puts("B");
			else if(C)
				puts("C");
			else if(D)
				puts("D");
			else if(E)
				puts("E");
		}
	}
	
	return 0;
}