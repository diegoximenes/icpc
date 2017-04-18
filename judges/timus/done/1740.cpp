#include<cstdio>
using namespace std;

int main()
{
	int l, k, h;
	double tmin, tmax;
	
	scanf("%d %d %d", &l, &k, &h);
	tmin = l/k*h;
	if(l%k == 0)
		tmax = tmin;
	else
		tmax = tmin + h;
	printf("%.8lf %.8lf\n", tmin, tmax);
	
	return 0;
}