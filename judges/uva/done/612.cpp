#include<stdio.h>
#include<stdlib.h>

bool cmp(char a, char b)
{
	if(((a == 'T') && (b == 'G')) || ((a == 'T') && (b == 'C'))
	|| ((a == 'T') && (b == 'A')) || ((a == 'G') && (b == 'C'))
	|| ((a == 'G') && (b == 'A')) || ((a == 'C') && (b == 'A')))
	{
		return true;
	}
	else
		return false;
}

typedef struct
{
	int in, s;
}St;

int cmpsort(const void *St1, const void *St2)
{
	return ((St *)St1)->s - ((St *)St2)->s;
}
		
int main()
{
	int M, n, m;
	
	scanf("%d", &M);
	
	for(int i=0; i<M; i++)
	{
		scanf("%d %d", &n, &m);
		char c[m][n];	
		St st[m];
		
		for(int j=0; j<m; j++)
			for(int k=0; k<n; k++)
			{
				scanf("%c", &c[j][k]);
				if(c[j][k] == '\n') k--;
			}
		
		for(int j=0; j<m; j++)
		{
			int s = 0;
			for(int k=0; k<n; k++)
			{	
				for(int l=k+1; l<n; l++)		
					if(cmp(c[j][k], c[j][l]))
						s++;
			}
			st[j].in = j;
			st[j].s = s;
			/*printf("j=%d, s=%d\n", j, s);*/
		}
		
		qsort(st, m, sizeof(St), cmpsort);
		
		for(int j=0; j<m; j++)
		{
			int l = st[j].in;
			for(int k=0; k<n; k++)
				printf("%c", c[l][k]);
			printf("\n");
		}
		
		if(i != M-1) printf("\n");
	}
	
	return 0;
}
