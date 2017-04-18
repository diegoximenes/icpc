#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n, v[105], count;
	
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%d", &v[i]);
	sort(v, v+n);
	
	count = v[0] + v[n-1];
	for(int i=1; i<n; ++i)
		count += v[i];
	printf("%d\n", count);
	
	return 0;
}