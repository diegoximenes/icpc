#include<cstdio>
using namespace std;

#define MAX 200005

double x[MAX], y[MAX];

int main()
{
	int n;

	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%lf %lf", &x[i], &y[i]);
	
	double area = 0;
	for(int i=0; i<n; ++i) area += (y[i] + y[(i+1)%n])*(x[(i+1)%n] - x[i])/2.0;
	
	if(area < 0) puts("ccw");
	else puts("cw");

	return 0;
}
