#include<stdio.h>
#include<stdlib.h>

int cmp(const void *n1, const void *n2)
{
    if(*((int *)n1) > *((int *)n2)) return 1;
    if(*((int *)n1) < *((int *)n2)) return -1;
    else return 0;
}

int main()
{
    int n, i = 0, v[10000];
    
    while(scanf("%d", &n) != EOF)
    {
	v[i] = n;
	i++;
	
	//melhorar complexidade?
	qsort(v, i, sizeof(int), cmp);
	
	if(i%2 == 1) 
	    printf("%d\n", v[i/2]);
	else
	    printf("%d\n", (v[i/2 - 1] + v[i/2])/2);
    }
    
    return 0;
}