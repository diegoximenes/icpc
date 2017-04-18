#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 500010

int main()
{
	int n, v[MAX];

	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &v[i]);
	
	sort(v, v+n);
	int i = 0, iupper = n/2, j = n/2, count = 0;
	while(i < iupper && j < n)
	{
		if(2*v[i] <= v[j]) ++i, ++j, ++count;
		else ++j;
	}
	printf("%d\n", n - count);

	return 0;
}
