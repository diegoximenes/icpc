#include<cstdio>
using namespace std;

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a%b)); }

int main()
{
	int d1, d2, d3;

	while(scanf("%d %d %d", &d1, &d2, &d3) == 3)
	{
		int num = d1 * d2, den = d3 - d2, g = gcd(num, den);

		printf("%d/%d\n", num/g, den/g);
	}
}
