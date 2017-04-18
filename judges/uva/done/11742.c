#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20

int a[MAX], b[MAX], c[MAX], count;

void permutation(int *perm, int *mark, int size, int level, int sizecons)
{
	if(level == size)
	{
		int i;
		++count;
		for(i=0; i<sizecons; ++i)
		{
			int cond1 = (c[i] < 0) && (abs(perm[a[i]] - perm[b[i]]) < -c[i]);
			int cond2 = (c[i] > 0) && (abs(perm[a[i]] - perm[b[i]]) > c[i]);
			if(cond1 || cond2)
			{
				--count;
				return;
			}
		}
	}
	else
	{
		int i;
		for(i=0; i<size; ++i)
			if(!mark[i])
			{
				perm[level] = i;
				mark[i] = 1;
				permutation(perm, mark, size, level+1, sizecons);
				mark[i] = 0;
			}
	}
}

int main()
{
	int n, m, mark[8], perm[8];
	
	while(scanf("%d %d", &n, &m) && n)
	{
		int i;
		for(i=0; i<m; ++i)
			scanf("%d %d %d", &a[i], &b[i], &c[i]);
		
		count = 0;
		memset(mark, 0, sizeof(mark));
		permutation(perm, mark, n, 0, m);
		printf("%d\n", count);
	}
	
	return 0;
}