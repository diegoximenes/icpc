#include<cstdio>

#define MAX 1010

int main()
{
	bool m[MAX][MAX];
	int p, n, c, e, count, palito;
	
	while(scanf("%d %d %d", &p, &n, &c) && p)
	{
		for(int i=0; i<n; ++i)
			for(int j=0; j<p; ++j)
			{
				scanf("%d", &e);
				m[i][j] = 1-e;
			}
		
		palito = 0;
		for(int i=0; i<n; ++i)
			for(int j=0; j<p; ++j)
			{
				if(!m[i][j])
				{
					count = 1;
					m[i][j] = 1;
					for(int k=i+1; k<n; ++k)
					{
						if(!m[k][j])
						{
							++count;
							m[k][j] = 1;
						}
						else
							break;
					}
					
					if(count >= c)
						++palito;
				}
			}
		
		printf("%d\n", palito);
	}
	
	return 0;
}