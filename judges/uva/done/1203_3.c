#include<stdio.h>
#include<string.h>

#define MAX 3010
#define ARGUSMAX 1010

typedef struct
{
	int qnum, per;
}Argus;

Argus argus[ARGUSMAX];

void up(int i)
{
	int j = i/2;
	Argus aux;
	
	if(j>=1)
		if((argus[i].per < argus[j].per) || ((argus[i].per == argus[j].per) && (argus[i].qnum < argus[j].qnum)))
		{
			aux.qnum = argus[i].qnum;
			aux.per = argus[i].per;
			
			argus[i].qnum = argus[j].qnum;
			argus[i].per = argus[j].per;
			
			argus[j].qnum = aux.qnum;
			argus[j].per = aux.per;
			
			up(j);
		}
}

void down(int i, int n)
{
	int j = 2*i;
	Argus aux;
	
	if(j <= n)
	{
		if(j < n)
			if((argus[j+1].per < argus[j].per) || ((argus[j+1].per == argus[j].per) && (argus[j+1].qnum < argus[j].qnum)))
				j += 1;
		if((argus[i].per > argus[j].per) || ((argus[i].per == argus[j].per) && (argus[i].qnum > argus[j].qnum)))
		{
			aux.qnum = argus[i].qnum;
			aux.per = argus[i].per;
			
			argus[i].qnum = argus[j].qnum;
			argus[i].per = argus[j].per;
			
			argus[j].qnum = aux.qnum;
			argus[j].per = aux.per;
			
			down(j, n);
		}
	}
}

int main()
{
	char s[10];
	int qnum, per, k, peri[MAX], n;
	
	n = 0;
	while(scanf("%s", s))
	{
		if(!strcmp(s, "#"))
			break;
		
		scanf("%d %d", &qnum, &per);
		
		++n;
		argus[n].qnum = qnum;
		argus[n].per = per;
		up(n);
		
		peri[qnum] = per;
	}
	
	scanf("%d", &k);
	
	while(k--)
	{
		per = argus[1].per;
		qnum = argus[1].qnum;
		
		argus[1].per = argus[n].per;
		argus[1].qnum = argus[n].qnum;
		--n;
		down(1, n);
		
		printf("%d\n", qnum);
		
		++n;
		argus[n].qnum = qnum;
		argus[n].per = per + peri[qnum];
		up(n);
	}
	
	return 0;
}