#include<stdio.h>
#include<math.h>

#define PI 2*acos(0)

int main()
{
	double l1, l2, l3, p, r, R, at, ac, aC;
	
	while(scanf("%lf %lf %lf", &l1, &l2, &l3) == 3)
	{
		p = (l1+l2+l3)/2;
		at = sqrt(p*(p-l1)*(p-l2)*(p-l3));
		r = 2*at/(l1+l2+l3);
		ac = PI*pow(r, 2);
		R = l1*l2*l3/(4*at);
		aC = PI*pow(R, 2);
		
		printf("%.4lf %.4lf %.4lf\n", aC-at, at-ac, ac);
	}
	
	return 0;
}
