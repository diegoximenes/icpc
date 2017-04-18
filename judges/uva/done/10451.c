#include<stdio.h>
#include<math.h>

#define PI 2*acos(0)

int main()
{
	double ap, R, r, as, ao, n;
	int t;
	
	for(t=1;;++t)
	{
		scanf("%lf %lf", &n, &ap);
		if(n < 3)
			break;
		
		R = sqrt(2*ap/(n*sin(2*PI/n)));
		as = PI*pow(R, 2) - ap;
		r = R*cos(PI/n);
		ao = ap - PI*pow(r, 2);
		
		printf("Case %d: %.5lf %.5lf\n", t, as, ao);
	}
	
	return 0;
}