#include<stdio.h>

int main()
{
    int n, v[100000], i, q, e, inicio, meio, fim, flag; 
    
    scanf("%d", &n);
    
    for(i=0; i<n; ++i)
	scanf("%d", &v[i]);
    
    scanf("%d", &q);
    
    for(i=0; i<q; ++i)
    {
	scanf("%d", &e);
	
	/*bsearch*/
	flag = 0;
	inicio = 0;
	fim = n-1;
	while(fim >= inicio)
	{
	    meio = (inicio + fim)/2;
	    
	    if((v[meio] < e) && ((meio + 1 > n - 1) || (v[meio + 1] >= e)))
	    {
		flag = 1;
		printf("%d ", v[meio]);
		break;
	    }
	    else if(e <= v[meio])
		fim = meio - 1;
	    else
		inicio = meio + 1;
	}
	if(!flag)
	    printf("X ");
	
	flag = 0;
	inicio = 0;
	fim = n-1;
	while(fim >= inicio)
	{
	    meio = (inicio + fim)/2;
	    
	    if((v[meio] > e) && ((meio - 1 >= 0) && (v[meio - 1] <= e)))
	    {
		flag = 1;
		printf("%d\n", v[meio]);
		break;
	    }
	    else if(e < v[meio])
		fim = meio - 1;
	    else
		inicio = meio + 1;
	}
	if(!flag)
	    printf("X\n");
    }
    
    return 0;
}