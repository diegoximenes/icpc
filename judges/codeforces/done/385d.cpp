#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAX (1 << 20)
#define MAX2 22
#define EPS 1e-8
#define PI acos(-1)
#define INF 1e9

double dp[MAX], a[MAX2], x[MAX2], y[MAX2];
int n, l, r;

inline double next(double actual, int i)
{
	double vx = actual - x[i], vy = -y[i]; //(vx, vy) is the vector from light point to actual position in x axis
	double ux = vx*cos(a[i]) - vy*sin(a[i]), uy = vx*sin(a[i]) + vy*cos(a[i]); //(ux, uv) is the vector (vx, vy) rotated

	if(uy >= 0) return r; //rotated vector is parallel to x axis or points upward, so iluminated until infinity

	double t = -y[i]/uy; //0 = pt + t*u, 0 = y[i] + t*uy
	double nx = x[i] + t*ux;
	
	return min(nx, (double)r);
}

int main()
{
	scanf("%d %d %d", &n, &l, &r);
	for(int i=0; i<n; ++i) scanf("%lf %lf %lf", &x[i], &y[i], &a[i]), a[i] *= PI/180.0;
	
	int upper = (1 << n);
	for(int i=0; i<upper; ++i) dp[i] = -INF;
	
	double sol = -INF;
	dp[0] = l;
	for(int i=0; i<upper; ++i)
		for(int j=0; j<n; ++j)
			if(!((1 << j) & i))
			{
				dp[(1 << j) | i] = max(dp[(1 << j) | i], next(dp[i], j));
				sol = max(sol, dp[(1 << j) | i]);
			}
	
	printf("%.9lf\n", sol - l);

	return 0;
}
