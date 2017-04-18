#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	double d, vf, vg, tf, tg;
	
	while(scanf("%lf %lf %lf", &d, &vf, &vg) == 3)
	{
		tf = 12.0/vf;
		tg = hypot(d, 12)/vg;
		if(tg <= tf)
			puts("S");
		else
			puts("N");
	}

	return 0;
}
