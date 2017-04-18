#include<stdio.h>

int cnj[30100], size[30100], count, maior;

void init(int n)
{
    int i;
    
    for(i=0; i<n; ++i)
    {
	cnj[i] = i;
	size[i] = 1;
    }
    
    count = n;
}

int find(int i)
{
    if(cnj[i] == i)
	return i;
    
    cnj[i] = find(cnj[i]);
    return cnj[i];
}

int same(int i, int j)
{
    if(find(i) == find(j))
	return 1;
    else
	return 0;
}

void unioncnj(int i, int j)
{
    if(same(i, j))
	return;
    
    size[find(j)] += size[find(i)];
    
    if(size[find(j)] > maior)
	maior = size[find(j)];
    
    cnj[find(i)] = find(j);
    --count;
}

int main()
{
    int t, n, m, a, b;
    
    scanf("%d", &t);

    while(t--)
    {
	scanf("%d %d", &n, &m);

	init(n);
	
	if(n > 0)
	    maior = 1;
	else
	    maior = 0;
	
	while(m--)
	{
	    scanf("%d %d", &a, &b);

	    unioncnj(a-1, b-1);
	}
	
	printf("%d\n", maior);
    }
    
    return 0;
}