#include<cstdio>
#include<cstdlib>

int sum, m[8][8];

int podecolocar(int nivel, int tent, int *v)
{
	for(int i=1; i<=nivel; ++i)
	{
		if(v[i] == tent)
			return 0;
		
		if(abs(nivel-i) == abs(tent-v[i]))
			return 0;
	}
	
	return 1;
}

void rainhas(int nivel, int tam, int *v)
{
	if(nivel > tam)
	{
		int sum_aux = 0;
		
		/*printf("v = ");
		for(int i=1; i<=tam; ++i)
			printf("%d, ", v[i]);*/
		
		for(int i=1; i <= tam; ++i)
			sum_aux += m[v[i]-1][i-1];
		
		/*printf("sum_aux = %d\n", sum_aux);*/
		
		if(sum_aux > sum)
			sum = sum_aux;
	}
	else
	{
		for(int i=1; i<=tam; ++i)
		{
			if(podecolocar(nivel, i, v))
			{
				v[nivel] = i;
				rainhas(nivel + 1, tam, v);
				v[nivel] = 0;
			}
		}
	}
}

int main()
{
	int t, v[9];
	
	scanf("%d", &t);
	
	while(t--)
	{
		sum = 0;
		
		for(int i=0; i<8; ++i)
			for(int j=0; j<8; ++j)
				scanf("%d", &m[i][j]);
		
		/*for(int i=0; i<8; ++i)
		{
			for(int j=0; j<8; ++j)
				printf("%d ", m[i][j]);
			
			printf("\n");
		}*/
		
		rainhas(1, 8, v);
		
		printf("%5d\n", sum);
	}
	
	return 0;
}