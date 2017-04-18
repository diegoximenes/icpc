#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int w, h, n, x1, x2, y1, y2, i, j, count;
    bool m[510][510];
    
    while(1)
    {
	scanf("%d %d %d", &w, &h, &n);
	if((w == 0) && (h == 0) && (n == 0))
	    break;
	
	//printf("w= %d, h=%d, n=%d\n", w, h, n);
	
	for(i=0; i<w; ++i)
	    for(j=0; j<h; ++j)
		m[i][j] = 0;
	
	while(n--)
	{
	    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	    
	    for(i=min(x1, x2)-1; i<max(x1, x2); ++i)
		for(j=min(y1, y2)-1; j<max(y1, y2); ++j)
		    m[i][j] = 1;
	}
	
	count = 0;
	for(i=0; i<w; ++i)
	    for(j=0; j<h; ++j)
		if(!m[i][j])
		    ++count;
	
	/*for(i=0; i<n; ++i)
	{
	    for(j=0; j<n; ++j)	
		printf("%d ", m[i][j]);
	    puts("");
	}*/
	
	if(!count)
	    puts("There is no empty spots.");
	else if(count == 1)
	    puts("There is one empty spot.");
	else
	    printf("There are %d empty spots.\n", count);
    }
    
    return 0;
}