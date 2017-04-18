#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 1010

int main()
{
	int n, p, i, j, indi, indj, anti, posi, countant, countpos;
	int pilha[MAX][MAX];
	
	while(scanf("%d %d", &n, &p) && n && p)
	{
		for(i=0; i<p; ++i)
		{
			scanf("%d", &pilha[i][0]);
			for(j=1; j<=pilha[i][0]; ++j)
			{
				scanf("%d", &pilha[i][j]);
				if(pilha[i][j] == 1)
				{
					indi = i;
					indj = j;
				}
			}
		}
		
		anti = 0;
		for(i=indi-1; i>=0; --i)
			if(pilha[i][0] < indj)
			{
				anti = i+1;
				break;
			}
		countant = 0;
		for(i= anti; i<indi; ++i)	
			countant += pilha[i][0] - indj + 1;
		
		posi = p-1;
		for(i=indi+1; i<p; ++i)
			if(pilha[i][0] < indj)
			{
				posi = i-1;
				break;
			}
		countpos = 0;
		for(i=posi; i>indi; --i)	
			countpos += pilha[i][0] - indj + 1;
		
		printf("%d\n", pilha[i][0]-indj + min(countpos, countant));
	}
	
	return 0;
}