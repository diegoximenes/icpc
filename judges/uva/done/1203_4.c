#include<stdio.h>

#define MAX 3010
#define ARGUSMAX 1010

typedef struct
{
	int qnum, per, per_ini;
}Argus;

int main()
{
	char s[10];
	int qnum, per_ini, per, k, n, i, j;
	Argus argus[ARGUSMAX], aux;
	
	n = 0;
	while(scanf("%s", s))
	{
		if(s[0] == '#')
			break;
		
		scanf("%d %d", &qnum, &per);
		
		++n;
		argus[n].qnum = qnum;
		argus[n].per = argus[n].per_ini = per;
		
		/*up(n, argus);*/
		i = n;
		j = i/2;
		while(1)
		{
			if(j>=1)
			{
				if((argus[i].per < argus[j].per) || ((argus[i].per == argus[j].per) && (argus[i].qnum < argus[j].qnum)))
				{
					aux.qnum = argus[i].qnum;
					aux.per = argus[i].per;
					aux.per_ini = argus[i].per_ini;
					
					argus[i].qnum = argus[j].qnum;
					argus[i].per = argus[j].per;
					argus[i].per_ini = argus[j].per_ini;
					
					argus[j].qnum = aux.qnum;
					argus[j].per = aux.per;
					argus[j].per_ini = aux.per_ini;
					
					/*up(j, argus);*/
					i = j;
					j /= 2;
				}
				else
					break;
			}
			else
				break;
		}
	}
	
	scanf("%d", &k);
	
	while(k--)
	{
		per = argus[1].per;
		per_ini = argus[1].per_ini;
		qnum = argus[1].qnum;
		
		argus[1].per = argus[n].per;
		argus[1].per_ini = argus[n].per_ini;
		argus[1].qnum = argus[n].qnum;
		--n;
		
		/*down(1, n, argus);*/
		i = 1;
		j = 2*i;
		while(1)
		{
			if(j <= n)
			{
				if(j < n)
					if((argus[j+1].per < argus[j].per) || ((argus[j+1].per == argus[j].per) && (argus[j+1].qnum < argus[j].qnum)))
						++j;
				if((argus[i].per > argus[j].per) || ((argus[i].per == argus[j].per) && (argus[i].qnum > argus[j].qnum)))
				{
					aux.qnum = argus[i].qnum;
					aux.per = argus[i].per;
					aux.per_ini = argus[i].per_ini;
					
					argus[i].qnum = argus[j].qnum;
					argus[i].per = argus[j].per;
					argus[i].per_ini = argus[j].per_ini;
					
					argus[j].qnum = aux.qnum;
					argus[j].per = aux.per;
					argus[j].per_ini = aux.per_ini;
					
					/*down(j, n, argus);*/
					i = j;
					j *= 2;
				}
				else
					break;
			}
			else
				break;
		}
		
		printf("%d\n", qnum);
		
		++n;
		argus[n].qnum = qnum;
		argus[n].per = per + per_ini;
		argus[n].per_ini = per_ini;
		
		/*up(n, argus);*/
		i = n;
		j = i/2;
		while(1)
		{
			if(j>=1)
			{
				if((argus[i].per < argus[j].per) || ((argus[i].per == argus[j].per) && (argus[i].qnum < argus[j].qnum)))
				{
					aux.qnum = argus[i].qnum;
					aux.per = argus[i].per;
					aux.per_ini = argus[i].per_ini;
					
					argus[i].qnum = argus[j].qnum;
					argus[i].per = argus[j].per;
					argus[i].per_ini = argus[j].per_ini;
					
					argus[j].qnum = aux.qnum;
					argus[j].per = aux.per;
					argus[j].per_ini = aux.per_ini;
					
					/*up(j, argus);*/
					i = j;
					j /= 2;
				}
				else
					break;
			}
			else
				break;
		}
	}
	
	return 0;
}