#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	double l, c, r1, r2;

	while(scanf("%lf %lf %lf %lf", &l, &c, &r1, &r2) && l)
	{
		if(hypot(r1 - (l - r2), r1 - (c - r2)) >= r1 + r2 && 2*r1 <= min(l, c) && 2*r2 <= min(l, c)) puts("S");
		else puts("N");
	}

	return 0;
}
