#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n, m, sol = 4, a;

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
		{
			scanf("%d", &a);
			if(a && (j == 0 || j == m-1 || i == 0 || i == n-1)) sol = 2;
		}
	printf("%d\n", sol);

	return 0;
}
