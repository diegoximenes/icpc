#include<cstdio>
using namespace std;

int main()
{
	int a, b, c, x, y, z;

	scanf("%d %d %d", &a, &b, &c);
	z = (c-b+a)/2;
	y = b - a + z;
	x = a - z;
	if(c-b+a < 0 || (c-b+a)%2 != 0 || y < 0 || x < 0) puts("Impossible");
	else printf("%d %d %d\n", x, y, z);

	return 0;
}
