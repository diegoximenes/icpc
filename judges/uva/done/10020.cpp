#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

typedef struct
{
    int l, r;
}Seg;

int cmp(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int main()
{
    int t, m, i, j, ind_intervalo, latual, ratual, count;
    bool flag;
    Seg s[100100];
    vector<int> v;
    
    scanf("%d", &t);
    
    while(t--)
    {
	v.clear();
	
	scanf("%d", &m);
	
	for(i=0; ; ++i)
	{
	    scanf("%d %d", &(s[i].l), &(s[i].r));
	    
	    if((s[i].l == 0) && (s[i].r == 0))
		break;
	}
	
	qsort(s, i, sizeof(Seg), cmp);
	
	latual = 0;
	ratual = 0;
	count = 0;
	ind_intervalo = -1;
	while(1)
	{
	    flag = 0;
	    
	    j = ind_intervalo + 1;
	    for(; j<i; ++j)
	    {
		if((s[j].l <= latual) && (s[j].r > ratual))
		{
		    ratual = s[j].r;
		    
		    ind_intervalo = j;
		    
		    flag = 1;
		}
	    }
	    
	    if(!flag)
		break;
	    
	    ++count;
	    
	    v.push_back(ind_intervalo);
	    
	    if(ratual >= m)
		break;
	    
	    latual = ratual;
	}
	
	if(!flag)
	    printf("0\n");
	else
	{
	    printf("%d\n", count);
	    
	    for(i=0; i<count; ++i)
		printf("%d %d\n", s[v[i]].l, s[v[i]].r);
	}
	
	if(t != 0)
	    puts("");
    }
    
    return 0;
}