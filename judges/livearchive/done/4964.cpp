#include<cstdio>
using namespace std;

int main()
{
	int a, b, c;

	while(scanf("%d %d %d", &a, &b, &c) && (a || b || c))
	{
		if(c == (b - a) + b) printf("AP %d\n", c + (b - a));
		else printf("GP %d\n", c*(b/a));
	}

	return 0;
}
