#include<stdio.h>

int main()
{
	double ncows, ncars, nshow, p1, p2, p3, p4;
	
	while(scanf("%lf %lf %lf", &ncows, &ncars, &nshow) == 3)
	{
		p1 = ncars/(ncars + ncows);
		p2 = (ncars - 1)/(ncars + ncows - nshow - 1);
		p3 = ncows/(ncars + ncows);
		p4 = ncars/(ncars + ncows - nshow - 1);
		
		printf("%.5lf\n", p1*p2 + p3*p4);
	}
		
	return 0;
}