#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 65

int main()
{
	int n, t, l[MAX], r[MAX];
	char d;

	while(scanf("%d", &n) == 1)
	{
		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		while(n--)
		{
			scanf("%d %c", &t, &d);
			if(d=='D')
				++r[t];
			else
				++l[t];
		}
		int count = 0;
		for(int i=30; i<=60; ++i)
			count += min(l[i], r[i]);
		printf("%d\n", count);
	}

	return 0;
}
