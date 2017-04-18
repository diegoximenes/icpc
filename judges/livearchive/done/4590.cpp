#include<cstdio>
#include<algorithm>
using namespace std;

#define INF (int) 1e9

int main()
{
	int u, d, n, m, x, y;
	
	while(scanf("%d %d", &n, &m) == 2)
	{
		int sol = INF;
		while(m--)
		{
			scanf("%d %d", &u, &d);
			x = d*n/(u + d) + 1;
			y = n - x;
			sol = min(sol, x*u - y*d);
		}
		printf("%d\n", sol);
	}

		
	return 0;
}
