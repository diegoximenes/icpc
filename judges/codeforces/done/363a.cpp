#include<cstdio>
using namespace std;

int main()
{
	int n;

	scanf("%d", &n);
	if(n == 0) puts("O-|-OOOO");
	while(n > 0)
	{
		int d = n%10;
		n /= 10;
		
		if(d >= 5) printf("-O"), d-=5;
		else printf("O-");
		putchar('|');

		int i;
		for(i=0; i<4 && d > 0; ++i, --d) putchar('O');
		putchar('-');
		for(; i<4; ++i) putchar('O');
		puts("");
	}

	return 0;
}