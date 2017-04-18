#include<math.h>
#include<stdio.h>
#include<string.h>

int primo(int a, int b)
{
    int n = a+b, i;
    
    for(i=2; i<=sqrt(n); ++i)
	if(n%i == 0) return 0;
	
    return 1;
    
}

void permutacao(int *orig, int *perm, int *marca, int nivel, int tam)
{
    int i, cond1, cond2;
    /*int flag;*/
    
    if(nivel == tam+1)
    {
	/*
	flag = 0;
	for(i=1; i<tam; ++i)
	{
	    if(!primo(perm[i], perm[i+1]))
	    {
		flag = 1;
		break;
	    }
	}
	if(!primo(perm[1], perm[tam]))
	    flag = 1;
	
	if(!flag)
	{
	    for(i=1; i<tam; ++i)
		printf("%d ", perm[i]);
	    printf("%d\n", perm[tam]);
	}*/
	
	for(i=1; i<tam; ++i)
	    printf("%d ", perm[i]);
	printf("%d\n", perm[tam]);
    }
    else
    {
	for(i=2; i<=tam; ++i)
	{
	    /*falta testar isso para pos tam e 1*/
	    /*cond1 = (perm[i-1]%2 == 0) && (i%2 != 0);*/
	    /*cond2 = (perm[i-1]%2 != 0) && (i%2 == 0);*/
	    cond1 = primo(perm[nivel-1], orig[i]);
	    cond2 = 1;
	    if(nivel == tam)
		cond2 = primo(perm[1], orig[i]);
	    if( !marca[i] && cond1 && cond2)
	    {
		perm[nivel] = orig[i];
		marca[i] = 1;
		permutacao(orig, perm, marca, nivel+1, tam);
		marca[i] = 0;
	    }
	}
    }
}

int main()
{
    int n, i, vorig[20], v[20], marcado[20];
    
    for(i=1; i<=20; ++i)
	vorig[i] = i;
    
    v[1] = 1;
    
    for(i=1;;++i)
    {
	if(scanf("%d", &n) == EOF)
	    break;
	
	memset(marcado, 0, 20*sizeof(int));
	
	if(i != 1)
	    printf("\n");
	
	printf("Case %d:\n", i);
	permutacao(vorig, v, marcado, 2, n);
    }
    
    return 0;
}