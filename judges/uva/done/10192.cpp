#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 

int main()
{
    char a[110], b[110];
    int n, m, t, pd[110][110];
    
    for(t=1; ; ++t)
    {
	gets(a);
	gets(b);
	if(a[0] == '#')
	    break;
	
	n = strlen(a);
	m = strlen(b);
	
	for(int i=0; i<=n; ++i) pd[i][0] = 0;
	for(int i=0; i<=m; ++i) pd[0][i] = 0;
	for(int i=1; i<=n; ++i)
	    for(int j=1; j<=m; ++j)    
	    {
		if(a[i-1] == b[j-1])
		    pd[i][j] = pd[i-1][j-1] + 1;
		else
		    pd[i][j] = max(pd[i-1][j], pd[i][j-1]);
	    }
	
	printf("Case #%d: you can visit at most %d cities.\n", t,  pd[n][m]);
    }
    
    return 0;
}