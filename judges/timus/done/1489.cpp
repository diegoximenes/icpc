#include<cstdio>
#include<cmath>
using namespace std;

#define EPS 1e-9

double a, b, c;

int cmp(double x, double y)
{
	if(fabs(x - y) < EPS) return 0;
	if(x < y) return -1;
	return 1;
}

inline bool left(double x, double y)
{
	if(cmp(x, c) <= 0 && cmp(y, b+c) >= 0 && cmp(y, b+c+b) <= 0) return 1;
	return 0;
}

inline bool right(double x, double y)
{
	if(cmp(x, c+a) >= 0 && cmp(y, b+c) >= 0 && cmp(y, b+c+b) <= 0) return 1;
	return 0;
}

inline bool bottom(double x, double y)
{
	if(right(x, y) || left(x, y)) return 0;
	if(cmp(y, b+c) >= 0 && cmp(y, b+c+b) <= 0) return 1;
	return 0;
}

inline bool top(double x, double y)
{
	if(right(x, y) || left(x, y)) return 0;
	if(cmp(y, b) <= 0) return 1;
	return 0;
}

inline bool front(double x, double y)
{
	if(right(x, y) || left(x, y)) return 0;
	if(cmp(y, b) >= 0 && cmp(y, b+c) <= 0) return 1;
	return 0;
}

inline bool back(double x, double y)
{
	if(!left(x, y) && !right(x, y) && !bottom(x, y) && !top(x, y) && !front(x, y)) return 1;
	return 0;
}

void transform(double &x, double &y, double &z)
{
	if(left(x, y)) z = c-x, x = c;
	else if(right(x, y)) z = x-(c+a), x = c+a;
	else if(back(x, y)) z = y-(b+c+b), y = b+c+b;
	else if(front(x, y)) z = c-(y-b), y = c+b;
	else if(bottom(x, y)) z = 0;
	else z = c, y = c+(b-y)+b; //top
}

double dist(double x0, double y0, double z0, double x1, double y1, double z1)
{
	return sqrt((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0) + (z1-z0)*(z1-z0));
}

int main()
{
	double x0, y0, z0, x1, y1, z1;

	scanf("%lf %lf %lf %lf %lf %lf %lf", &a, &b, &c, &x0, &y0, &x1, &y1);
	
	transform(x0, y0, z0);
	transform(x1, y1, z1);

	printf("%.10lf\n", dist(x0, y0, z0, x1, y1, z1));

	return 0;
}
