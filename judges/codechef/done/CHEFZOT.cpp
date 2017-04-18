#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int n, sol = 0, len = 0, x;

	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &x);
		if(!x) sol = max(sol, len), len = 0;
		else len++;
	}
	sol = max(sol, len);

	printf("%d\n", sol);

	return 0;
}
