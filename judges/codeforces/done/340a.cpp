#include<cstdio>
using namespace std;

int gcd(int a, int b)
{
	return (b == 0 ? a : gcd(b, a%b));
}

int main()
{
	int x, y, a, b, c;

	scanf("%d %d %d %d", &x, &y, &a, &b);
	c = gcd(x, y);
	y /= c; x /= c;
	printf("%d\n", b/(c*x*y) - (a-1)/(c*x*y));

	return 0;
}
