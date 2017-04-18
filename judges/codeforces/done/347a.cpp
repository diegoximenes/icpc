#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n, v[105];

	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &v[i]);
	sort(v, v+n);
	printf("%d", v[n-1]);
	for(int i=1; i<n-1; ++i) printf(" %d", v[i]);
	printf(" %d\n", v[0]);

	return 0;
}

