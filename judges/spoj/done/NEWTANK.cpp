#include<cstdio>
using namespace std;

int main()
{
	int n, v, t;

	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d %d", &v, &t);
		printf("Case #%d: %d\n", i, v*t);
	}

	return 0;
}
