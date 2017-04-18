#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAX 110

int main()
{
	int t, n;
	pair<double, double> p[MAX];
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
			scanf("%lf %lf", &p[i].first, &p[i].second);
		sort(p, p+n);
		
		double length = 0, ymax = 0, a, xint;
		for(int i=n-2; i>=0; i-=2)
			if(p[i].second > ymax)
			{
				a = (p[i].second - p[i+1].second)/(p[i].first - p[i+1].first);
				xint = (ymax - p[i+1].second)/a + p[i+1].first;
				
				length += sqrt(pow(ymax - p[i].second, 2) + pow(xint - p[i].first, 2));
				ymax = p[i].second;
			}
		printf("%.2lf\n", length);
	}
	
	return 0;
}