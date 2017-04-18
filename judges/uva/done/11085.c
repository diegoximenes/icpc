#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int minmove;

int podecolocar(int nivel, int tent, int *v)
{
    int i;
    
    for(i=0; i<nivel; ++i)
    {
		if(v[i] == tent)
			return 0;
		
		if(abs(nivel-i) == abs(tent-v[i]))
			return 0;
    }
    
    return 1;
}

void rainhas(int tam, int nivel, int *row, int *rowaux)
{
    int i, moves;
    
    if(nivel == tam)
    {
		moves = 0;
		
		for(i=0; i<8; ++i)
			if(row[i] != rowaux[i])
				++moves;
			
		if(minmove > moves)
			minmove = moves;
    }
    else
    {
		for(i=0; i<tam; ++i)
		{
			if(podecolocar(nivel, i+1, row))
			{
				row[nivel] = i+1;
				rainhas(tam, nivel+1, row, rowaux);
			}
		}
    }
}

int main()
{	
	int rowaux[8], row[8], i, k, flag = 0;
	
	for(k=1; ; ++k)
	{
		for(i=0; i<8; ++i)
			if(scanf("%d", &rowaux[i]) == EOF)
			{
				flag = 1;
				break;
			}
			
		if(flag)
			break;

		minmove = INT_MAX;
		
		rainhas(8, 0, row, rowaux);
		
		printf("Case %d: %d\n", k, minmove);
	}
	return 0;
}