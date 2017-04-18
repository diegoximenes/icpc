#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
    char a[1010], b[1010];
    int i, j, n, m, pd[1010][1010];
    
    while(gets(a) && gets(b))
    {
	n = strlen(a);
	m = strlen(b);
	
	if(!n && !m)
	    break;
	
	for(i=0; i<=n; ++i)
	    pd[i][0] = 0;
	for(i=0; i<=m; ++i)
	    pd[0][i] = 0;
	for(i=1; i<=n; ++i)
	    for(j=1; j<=m; ++j)
	    {
		if(a[i-1] == b[j-1])
		    pd[i][j] = pd[i-1][j-1] + 1;
		else
		    pd[i][j] = max(pd[i-1][j], pd[i][j-1]);
	    }
	
	printf("%d\n", pd[n][m]);
    }
    
    return 0;
}