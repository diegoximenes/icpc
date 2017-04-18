#include<stdio.h>

int main()
{
    int t, i, j, k, n;
    char m[15][15], c;
    
    scanf("%d", &t);

    for(i=1; i<=t; ++i)
    {
	scanf("%d", &n);
	getchar();

	for(j=0; j<n; ++j)
	{
	    for(k=0; k<n; ++k)
		scanf("%c", &m[j][k]);
	    getchar();
	}
	
	for(j=0; j<n; ++j)
	    for(k=0; k<n; ++k)
		if(m[j][k] == '.')	    
		    for(c='A'; c<='Z'; ++c)
		    {
			if((j-1 >= 0) && (m[j-1][k] == c))
			    continue;
			if((j+1 < n) && (m[j+1][k] == c))
			    continue;
			if((k-1 >= 0) && (m[j][k-1] == c))
			    continue;
			if((k+1 < n) && (m[j][k+1] == c))
			    continue;
			
			m[j][k] = c;
			break;
		    }
	
	printf("Case %d:\n", i);
	for(j=0; j<n; ++j)
	{
	    for(k=0; k<n; ++k)
		printf("%c", m[j][k]);
	    puts("");
	}
    }
    
    return 0;
}