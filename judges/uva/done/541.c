#include<stdio.h>
#include<string.h>

int main()
{
    int n, i, j, row[110], col[110], e, countrow, countcol, inrow, incol;
    
    while(1)
    {
	scanf("%d", &n);
	if(n == 0)
	    break;
	
	memset(row, 0, n*sizeof(int));
	memset(col, 0, n*sizeof(int));
	
	for(i=0; i<n; ++i)
	    for(j=0; j<n; ++j)
	    {
		scanf("%d", &e);
		
		row[i] += e;
		col[j] += e;
	    }
	
	countrow = 0;
	for(i=0; i<n; ++i)
	{
	    if(row[i]%2 > 0)
	    {
		++countrow;
		inrow = i+1;
	    }
	    
	    if(countrow == 2)
		break;
	}
	
	countcol = 0;
	if(countrow != 2)
	{
	    for(i=0; i<n; ++i)
	    {
		if(col[i]%2 > 0)
		{
		    countcol++;
		    incol = i+1;
		}
		
		if((countcol == 2) || ((countrow == 0) && (countcol == 1)))
		    break;
	    }
	}
	
	if((countrow == 0) && (countcol == 0))
	    puts("OK");
	else if((countrow == 1) && (countcol == 1))
	    printf("Change bit (%d,%d)\n", inrow, incol);
	else
	    puts("Corrupt");
    }
    
    return 0;
}