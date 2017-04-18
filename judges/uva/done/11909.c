#include<stdio.h>
#include<math.h>

#define PI acos(-1)

int main()
{
	double l, w, h, teta, h1, h2, v, l1;
	
	while(scanf("%lf %lf %lf %lf", &l, &w, &h, &teta) == 4)
	{
		h2 = l*tan(teta*PI/180.0);
		if(h2 >= h)
		{
			l1 = h*tan((90-teta)*PI/180.0);
			v = w*h*l1/2;
		}
		else
		{
			h1 = h - h2;
			v = w*l*(h1 + h2/2);
		}
		printf("%.3lf mL\n", v);
	}
	
	return 0;
}