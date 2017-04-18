#include<stdio.h>
#include<math.h>

int m[9][9], found;

int canplace(int r, int c, int num, int n)
{
	int i, j, nsqr, il, jl;
	
	for(i=0; i<n; ++i)
	{
		if((i != r) && (m[i][c] == num))
			return 0;
		
		if((i != c) && (m[r][i] == num))
			return 0;
	}
		
	nsqr = sqrt(n);
	il = nsqr*(r/nsqr);
	jl = nsqr*(c/nsqr);
	
	for(i=il; i < il + nsqr; ++i)
		for(j=jl; j<jl + nsqr; ++j)
		{
			if((i == r) && (j == c))
				continue;
			if(m[i][j] == num)
				return 0;
		}
			
	return 1;
}

void sudoku(int r, int c, int n)
{
	int i, j, k;

	if(!found)
	{
		if(r == n)
		{
			for(i=0; i<n; ++i)
			{
				for(j=0; j<n-1; ++j)
					printf("%d ", m[i][j]);
				printf("%d\n", m[i][n-1]);
			}
			
			found = 1;
		}
		else if(m[r][c] != 0)
		{
			if(c == n-1)
				sudoku(r + 1, 0, n);
			else
				sudoku(r, c + 1, n);
		}
		else
		{
			for(k=1; k<=n; ++k)
			{
				if(canplace(r, c, k, n))
				{
					m[r][c] = k;
					
					if(c == n-1)
						sudoku(r + 1, 0, n);
					else
						sudoku(r, c + 1, n);
					
					m[r][c] = 0;
				}
			}	
		}
	}
}

int main()
{
	int n, i, j, flag = 0;
	
	while(1)
	{
		if(scanf("%d", &n) == EOF)
			break;
		
		if(!flag)
			flag = 1;
		else
			puts("");
		
		n *= n;
		
		for(i=0; i<n; ++i)
			for(j=0; j<n; ++j)
				scanf("%d", &m[i][j]);
		
		found = 0;

		sudoku(0, 0, n);
		
		if(!found)
			puts("NO SOLUTION");
	}
	
	return 0;
}