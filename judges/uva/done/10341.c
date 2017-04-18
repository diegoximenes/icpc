#include<stdio.h>
#include<math.h>

int p, q, r, s, t, u;

double eq(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
    double inicio, fim, meio;
    
    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6)
    {
	inicio = 0.0;
	fim = 1.0;
	
	if(((eq(inicio) > 0) && (eq(fim) > 0)) || ((eq(inicio) < 0) && (eq(fim) < 0)))
	    printf("No solution\n");
	else
	{
	    while(inicio + 0.0000001 < fim)
	    {
		meio = (inicio + fim)/2;
		
		if(((eq(inicio) > 0) && (eq(meio) > 0)) || ((eq(inicio) < 0) && (eq(meio) < 0)))
		    inicio = meio;
		else
		    fim = meio;
	    }
	    
	    printf("%.4lf\n", meio);
	}
    }
    return 0;
}