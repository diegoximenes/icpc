#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 100100

int main()
{
	int a, b, va[MAX], vb[MAX], i, n, counta, countb;
	
	while(scanf("%d %d", &a, &b))
	{
		if(!a && !b)
			break;
		
		memset(va, 0, MAX*sizeof(int));
		memset(vb, 0, MAX*sizeof(int));
		
		for(i=0; i<a; ++i)
		{
			scanf("%d", &n);
			va[n] = 1;
		}
		for(i=0; i<b; ++i)
		{
			scanf("%d", &n);
			vb[n] = 1;
		}
		
		counta = countb = 0;
		for(i=0; i<MAX; ++i)
		{
			if(va[i] && !vb[i])
				++counta;
			
			if(vb[i] && !va[i])
				++countb;
		}
		
		printf("%d\n", min(counta, countb));
	}
	
	return 0;
}