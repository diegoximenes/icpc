#include<cstdio>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
	int t;
	double d, u, v;

	scanf("%d", &t);
	for(int k=1; k<=t; ++k)
	{
		scanf("%lf %lf %lf", &d, &v, &u);
		if((v >= u) || (u == 0) || (v == 0))
			printf("Case %d: can't determine\n", k);
		else
			printf("Case %d: %.3lf\n", k, d*(1/sqrt(u*u - v*v) - 1.0/u));
	}

	return 0;
}