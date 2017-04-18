#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAXW 10000+10
#define MAXL 30

int main()
{
	char dic[MAXW][MAXL], w[MAXL], w2[MAXL];
	int n, q;
	
	scanf("%d", &n); getchar();
	for(int i=0; i<n; ++i)
		gets(dic[i]);
	scanf("%d", &q); getchar();
	while(q--)
	{
		scanf("%s", w);
		
		bool solved = 0;
		int lenw = strlen(w);
		for(int i=0; i<n; ++i)
			if(!strcmp(w, dic[i]))
			{
				solved = 1;
				printf("%s is correct\n", w);
				break;
			}
		for(int i=0; !solved && i<n; ++i)
		{
			int lend = strlen(dic[i]);
			if(abs(lend - lenw) <= 1)
			{
				if(lend == lenw)
				{
					//change one letter
					int change = 0;
					for(int j=0; change<=1 && j<lend; ++j)
						if(dic[i][j] != w[j])
							++change;
					if(change == 1)
					{
						//puts("change");
						solved = 1;
						printf("%s is a misspelling of %s\n", w, dic[i]);
						break;
					}
					
					//change order
					int swap = 0;
					for(int j=0; swap<=1 && j<lend; ++j)
					{
						if((dic[i][j] != w[j]) && (j+1 < lend) && (w[j+1] == dic[i][j] && dic[i][j+1] == w[j]))
						{
							++swap;
							++j;
						}
						else if(((dic[i][j] != w[j]) && (j+1 < lend) && (w[j+1] != dic[i][j] || dic[i][j+1] != w[j])) || (dic[i][j] != w[j] && j+1 == lend))
						{
							swap = 2;
							break;
						}
					}
					if(swap == 1)
					{
						//puts("order");
						solved = 1;
						printf("%s is a misspelling of %s\n", w, dic[i]);
						break;
					}
				}
				
				//too much
				if(lenw > lend)
				{
					for(int j=0; j<lenw; ++j)
					{
						int l = 0;
						memset(w2, 0, sizeof(w2));
						for(int k=0; k<lenw; ++k)
							if(j != k)
								w2[l++] = w[k];
						//printf("w2= %s, dic[i]= %s\n", w2, dic[i]);
						if(!strcmp(w2, dic[i]))
						{
							//puts("much");
							solved = 1;
							printf("%s is a misspelling of %s\n", w, dic[i]);
							break;
						}
					}
				}
					
				//missing
				if(lend > lenw)
				{
					for(int j=0; j<lend; ++j)
					{
						int l = 0;
						memset(w2, 0, sizeof(w2));
						for(int k=0; k<lend; ++k)
							if(j != k)
								w2[l++] = dic[i][k];
						
						if(!strcmp(w2, w))
						{
							//puts("miss");
							solved = 1;
							printf("%s is a misspelling of %s\n", w, dic[i]);
							break;
						}
					}
				}
			}	
		}
		if(!solved)
			printf("%s is unknown\n", w);
	}
	
	return 0;
}