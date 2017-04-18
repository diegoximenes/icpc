#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	double a, b, c;

	scanf("%lf %lf %lf", &a, &b, &c);
	
	int n = 1000;
	double y = c*n/(b + c*(b/a + 1));
	
	printf("%d\n", (int)round(b*y));

	return 0;
}
