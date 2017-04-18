#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 105

int main()
{
	int v[MAX], n;
	char c;

	for(n=0; ; ++n)
	{
		scanf("%d", &v[n]);
		if(scanf("%c", &c) != 1 || c != '+')
			break;
	}
	sort(v, v + n + 1);
	
	for(int i=0; i<n; ++i)
		printf("%d+", v[i]);
	printf("%d\n", v[n]);

	return 0;
}

