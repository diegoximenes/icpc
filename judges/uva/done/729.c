#include<stdio.h>

void permutacao(int *perm, int *qnt, int tam, int nivel)
{
    int i;
    
    if(tam == nivel)
    {
	for(i=0; i<tam; ++i)
	    printf("%d", perm[i]);
	printf("\n");
    }
    else
    {
	for(i=0; i<=1; ++i)
	{
	    if(qnt[i])
	    {
		perm[nivel] = i;
		--qnt[i];
		permutacao(perm, qnt, tam, nivel+1);
		++qnt[i];
	    }
	}
    }
}

int main()
{
    int t, tam, h, perm[20], qnt[2];
    
    scanf("%d", &t);
    
    while(t--)
    {
	scanf("%d %d", &tam, &h);
	
	qnt[1] = h;
	qnt[0] = tam - h;
	
	permutacao(perm, qnt, tam, 0);
	
	if(t != 0)
	    puts("");
    }
    
    return 0;
}