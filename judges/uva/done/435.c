#include<stdio.h>
#include<string.h>

#define MAX 20

int pindex[MAX];
double halfVotes;

void subset(int *v, int *mark, int size, int level)
{	
	if(level == size)
	{
		int i, votes = 0;
		
		for(i=0; i<size; ++i)
			if(mark[i])
				votes += v[i];
		if(votes > halfVotes)
			return;
		for(i=0; i<size; ++i)
			if((!mark[i]) && (votes + v[i] > halfVotes))
				++pindex[i];
	}
	else
	{
		mark[level] = 1;
		subset(v, mark, size, level + 1);
		mark[level] = 0;
		subset(v, mark, size, level + 1);
	}
}

int main()
{
	int t, n, v[MAX], mark[MAX], i;
	
	scanf("%d", &t);
	while(t--)
	{
		memset(pindex, 0, sizeof(pindex));
		halfVotes = 0.0;
		
		scanf("%d", &n);
		for(i=0; i<n; ++i)
		{
			scanf("%d", &v[i]);
			halfVotes += v[i];
		}
		halfVotes /= 2.0;
		
		subset(v, mark, n, 0);
		
		for(i=0; i<n; ++i)
			printf("party %d has power index %d\n", i+1, pindex[i]);
		puts("");
	}
	
	return 0;
}