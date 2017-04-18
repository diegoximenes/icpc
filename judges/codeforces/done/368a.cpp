#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n, d, a[105], m;

	scanf("%d %d", &n, &d);
	for(int i=0;i<n; ++i) scanf("%d", &a[i]);
	sort(a, a+n);

	scanf("%d", &m);
	int count = 0;
	for(int i=0; i<m; ++i)
	{
		if(i >= n) count -= d;
		else count += a[i];
	}
	printf("%d\n", count);

	return 0;
}
