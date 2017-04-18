#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n, v[105], e;

	while(scanf("%d", &n) && n)
	{
		memset(v, 0, sizeof(v));
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
			{
				scanf("%d", &e);
				if(e) --v[j];
			}
		sort(v, v+n);
		printf("%d\n", -*v);
	}

	return 0;
}
