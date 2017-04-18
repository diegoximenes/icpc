#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 10010

int main()
{
	int n, r, v[MAX];

	while(scanf("%d %d", &n, &r) == 2)
	{
		int count = 0;
		memset(v, 0, sizeof(v));
		while(r--)
		{
			int a;
			scanf("%d", &a);
			v[a] = 1;
			++count;
		}
		if(count == n) puts("*");
		else
		{
			for(int i=1; i<=n; ++i)
				if(!v[i])
					printf("%d ", i);
			puts("");
		}		
	}

	return 0;
}
