#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
    int *i1 = (int *)a;
    int *i2 = (int *)b;
    
    if(*i1 > *i2) return 1;
    if(*i1 < *i2) return -1;
    return 0;
}

int main()
{
    int t, r, i, v[500], sum, m;

    scanf("%d", &t);
    
    while(t--)
    {
	sum = 0;
	
	scanf("%d", &r);
	
	for(i=0; i<r; ++i)
	    scanf("%d", &v[i]);
	
	qsort(v, r, sizeof(int), cmp);
	
	m = v[(r-1)/2];
	
	for(i=0; i<r; ++i)
	    sum += abs(v[i] - m);
	
	printf("%d\n", sum);
    }
    
    return 0;
}