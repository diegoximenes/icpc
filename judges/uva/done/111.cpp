#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int n, i, j, k, e, pd[25][25], a[25], b[25];
    
    scanf("%d", &n);
    
    for(i=1; i<=n; ++i)
    {
	scanf("%d", &e);
	a[e] = i;
    }
    /*
    printf("a = ");
    for(i=0; i<n; ++i)
	printf("%d ", a[i]);
    puts("");
    */
    
    k = 1; 
    while(1)
    {
	if(k > n)
	{
	    /*printf("b = ");
	    for(i=1; i<=n; ++i)
		printf("%d ", b[i]);
	    puts("");*/
	    
	    
	    for(i=0; i<=n; ++i)
		pd[i][0] = pd[0][i] = 0;
	    
	    /*printf("pd = \n");
	    for(i=0; i<=n; ++i)
	    {
		for(j=0; j<=n; ++j)
		    printf("%d ", pd[i][j]);
		puts("");
	    }*/
	    
	    for(i=1; i<=n; ++i)
		for(j=1; j<=n; ++j)
		{
		    if(a[i] == b[j])
			pd[i][j] = pd[i-1][j-1] + 1;
		    else
			pd[i][j] = max(pd[i-1][j], pd[i][j-1]);
		}
	    
	    printf("%d\n", pd[n][n]);
	    
	    k = 1;
	}
	
	if(scanf("%d", &e) == EOF)
	    break;
	
	b[e] = k;
	
	++k;
    }
    
    return 0;
}