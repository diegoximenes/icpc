#include<cstdio>
using namespace std;

int main()
{
	int n, x, dx, y, dy;

	while(scanf("%d", &n) && n)
	{
		scanf("%d %d", &dx, &dy);
		for(int i=0; i<n; ++i)
		{
			scanf("%d %d", &x, &y);
			if(x == dx || y == dy) puts("divisa");
			else if(x < dx && y < dy) puts("SO");
			else if(x < dx && y > dy) puts("NO");
			else if(y < dy) puts("SE");
			else puts("NE");
		}
	}

	return 0;
}
