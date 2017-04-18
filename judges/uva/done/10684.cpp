#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    int n, v[10100], pd[10100], maior;
    bool flag;
    
    while(scanf("%d", &n))
    {
	if(n == 0)
	    break;
	
	for(int i=1; i<=n; ++i)
	    scanf("%d", &v[i]);
	
	pd[0] = 0;
	
	for(int i=1; i<=n; ++i)
	    pd[i] = max(v[i], pd[i-1] + v[i]);
	
	flag = 0;
	maior = 0;
	for(int i=0; i<=n; ++i)
	{
	    if(pd[i] > maior)
	    {
		maior = pd[i];
		flag = 1;
	    }
	}
	
	if(!flag)
	    printf("Losing streak.\n");
	else
	    printf("The maximum winning streak is %d.\n", maior);
    }
    
    return 0;
}
