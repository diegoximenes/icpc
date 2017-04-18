#include<cstdio>
#include<cmath>
using namespace std;

#define EPS 1e-9

int w, d, k;
double a, p1[9], p2[9], q1[9], q2[9];

double f(double *p, double *q, int k, double x)
{
	double n = 0.0, d = 0.0;
	for(int i=0; i<=k; ++i)
	{
		n += p[i]*pow(x, i);
		d += q[i]*pow(x, i);
	}
	return n/d;
}

double f1(double x)
{
	return f(p1, q1, k, x);
}

double f2(double x)
{
	return f(p2, q2, k, x);
}

int main()
{	
	while(scanf("%d %d %lf %d", &w, &d, &a, &k) == 4)
	{
		for(int i=0; i<=k; ++i) scanf("%lf", &p1[i]);
		for(int i=0; i<=k; ++i) scanf("%lf", &q1[i]);
		for(int i=0; i<=k; ++i) scanf("%lf", &p2[i]);
		for(int i=0; i<=k; ++i) scanf("%lf", &q2[i]);
		
		double ymin = 0.0, ymax = -d, y, x, dx = 0.0004;
		while(1)
		{
			y = (ymax + ymin)/2.0;
			
			double area, a1 = 0.0, a2 = 0.0;
			for(x=0.0; x+dx<=w; x+=dx)
			{
				double f1x = f1(x), f1dx = f1(x+dx), f2x = f2(x), f2dx = f2(x+dx);
				if((f1x > y) && (f1dx > y))
					a1 += dx*(-2*y + f1x + f1dx)/2.0;
				if((f2x > y) && (f2dx > y))
					a2 += dx*(-2*y + f2x + f2dx)/2.0;
			}
			if(w > x)
			{
				if((f1(x) > y) && (f1(w) > y))
					a1 += (w-x)*(-2*y + f1(x) + f1(w))/2.0;
				if((f2(x) > y) && (f2(w) > y))
					a2 += (w-x)*(-2*y + f2(x) + f2(w))/2.0;
			}
			area = a1 - a2;
			
			//printf("y= %lf, ymin= %lf, ymax= %lf, area= %lf\n", y, ymin, ymax, area);

			if(fabs(area - a) < EPS)
				break;
			else if(area > a)
				ymax = y;
			else
				ymin = y;
		}
		printf("%.5lf\n", fabs(y));
	}
	
	return 0;
}
