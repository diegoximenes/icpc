#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int t, n, x;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		int sol = 0;
		for(int i=0; i<n; ++i) scanf("%d", &x), sol = max(sol, x + i);
		printf("%d\n", sol);
	}

	return 0;
}
