#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define MAX 105
#define INF 1e9
#define EPS 1e-9

int cmp(const void *a, const void *b)
{
	double n1 = *(double *)a, n2 = *(double *)b;
	if(fabs(n1 - n2) < EPS)
		return 0;
	else if(n1 < n2)
		return -1;
	else
		return 1;
}

int main()
{
	int f, r, front[MAX], rear[MAX];
	double ratio[MAX*MAX];
	
	while(scanf("%d %d", &f, &r) && f)
	{
		int i, j, count;
		double spread;
		
		for(i=0; i<f; ++i)
			scanf("%d", &front[i]);
		for(i=0; i<r; ++i)
			scanf("%d", &rear[i]);
		
		count = 0;
		for(i=0; i<r; ++i)
			for(j=0; j<f; ++j, ++count)
				ratio[count] = (double)rear[i]/(double)front[j];
	
		qsort(ratio, count, sizeof(double), cmp);
		
		spread = -INF;
		for(i=1; i<count; ++i)
			if(ratio[i]/ratio[i-1] > spread)
				spread = ratio[i]/ratio[i-1];
		printf("%.2lf\n", spread);	
	}
	
	return 0;
}