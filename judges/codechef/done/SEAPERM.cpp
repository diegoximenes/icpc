#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 2005

int main()
{
	int t, n, v[MAX];
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %*d %*d", &n);
		for(int i=0; i<n; ++i) scanf("%*d"), v[i] = i + 1;
		
		printf("%d", v[0]);
		for(int i=1; i<n; ++i) printf(" %d", v[i]);
		puts("");
	}

	return 0;
}
