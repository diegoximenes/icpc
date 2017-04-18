#include<stdio.h>

int main()
{
    long long int nu; 
    int n;    
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
    {
	scanf("%lld", &nu);
	
	int it = 0;
	while(1)
	{
	    it++;
	    
	    int m1 = 1;
	    long long nuaux = nu;
	    while(nuaux > 9)
	    {
		nuaux /= 10;
		m1 *= 10;
	    }
	    	    
	    nuaux = nu;
	    long long nurev = 0;
	    int m2 = m1;
	    while(nuaux > 0)
	    {
		nurev += m2*(nuaux%10);
		nuaux /= 10;
		m2 /= 10;
	    }
	    
	    long long sum = nu + nurev;	    
	    
	    //printf("nu = %lld, nurev = %lld, sum = %lld, m1 = %d\n", nu, nurev, sum, m1);
	    
	    long long sumaux = sum;
	    bool palind = 1;
	    while(1)
	    {
		//printf("1: sumaux/m1 = %lld, sumaux = %lld, m1 = %d\n", sumaux/m1, sumaux, m1);
		if(sumaux%10 != sumaux/m1)
		{
		    palind = 0;
		    break;
		}
		
		if(sumaux/10 < 10 ) break;
		
		sumaux -= sumaux/m1*m1;
		sumaux /= 10;
				
		m1 /= 100;
		
		//printf("2: sumaux/m1 = %lld, sumaux = %lld, m1 = %d\n", sumaux/m1, sumaux, m1);

	    }
	    
	    if(palind)
	    {
		printf("%d %lld\n", it, sum);
		break;
	    }
	    
	    nu = sum;
	}
    }
    
    return 0;
}