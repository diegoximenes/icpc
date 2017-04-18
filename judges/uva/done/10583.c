#include<stdio.h>

int cnj[50100], count;

void init(int n)
{
    int i;
    
    for(i=0; i<n; ++i)
	cnj[i] = i;
    
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
    
    cnj[find(i)] = find(j);
    
    --count;
}

int main()
{
    int n, m, i, a, b;
    
    for(i=1; ; ++i)
    {
	scanf("%d %d", &n, &m);
	if((n == 0) && (m == 0))
	    break;
	
	init(n);
	
	while(m--)
	{
	    scanf("%d %d", &a, &b);
	    
	    unioncnj(a-1, b-1);
	}
	
	printf("Case %d: %d\n", i, count);
    }
    
    return 0;
}