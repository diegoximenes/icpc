#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
    return *((int *)b) - *((int *)a);
}

int main()
{
    int t, n, i, v[20100], disc;
    
    scanf("%d", &t);
    
    while(t--)
    {
	disc = 0;
	
	scanf("%d", &n);
	
	for(i=0; i<n; ++i)
	    scanf("%d", &v[i]);
	
	qsort(v, n, sizeof(int), cmp);
	
	for(i=2; i<n; i+=3)
	    disc += v[i];
	
	printf("%d\n", disc);
    }
    
    return 0;
}