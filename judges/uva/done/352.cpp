#include<cstdio>
#include<vector>
#include<list>
#include<queue>
using namespace std;

typedef struct
{
	int i, j;
}Cel;

int main()
{
	int n, i, j, count, p;
	char m[30][30];
	bool marc[30][30];
	queue<Cel> f;
	Cel cel, cel2;
	
	for(p=1; ; ++p)
	{		
		if(scanf("%d", &n) == EOF)
			break;

		getchar();
		for(i=0; i<n; ++i)
		{
			for(j=0; j<n; ++j)
			{
				scanf("%c", &m[i][j]);
				if(m[i][j] == '0')
					marc[i][j] = 1;
				else if(m[i][j] == '1')
					marc[i][j] = 0;
				
			}
			getchar();
		}
		
		/*for(i=0; i<n; ++i)
		{
			for(j=0; j<n; ++j)
			{
				printf("%c", m[i][j]);
			}
			puts("");
		}*/
		
		count = 0;
		for(i=0; i<n; ++i)
		{
			for(j=0; j<n; ++j)
			{
				if(!marc[i][j])
				{
					cel.i = i;
					cel.j = j;
					
					marc[i][j] = 1;
					f.push(cel);
					
					++count;
					
					while(!f.empty())
					{
						cel = f.front();
						f.pop();
						
						for(int k=cel.i - 1; k<=cel.i + 1; ++k)
						{
							for(int l=cel.j - 1; l<=cel.j + 1; ++l)
							{
								if((k>=0) && (k<n) && (l>=0) && (l<n) && (!marc[k][l]) && (m[k][l] == '1'))
								{
									cel2.i = k;
									cel2.j = l;
									
									marc[k][l] = 1;
									f.push(cel2);
								}
									
							}
						}
					}
				}
			}
		}
		
		printf("Image number %d contains %d war eagles.\n", p, count);
	}
	
	return 0;
}