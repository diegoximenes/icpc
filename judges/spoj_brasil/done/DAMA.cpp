#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int x1, y1, x2, y2;

	while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2) && x1)
	{
		if(x1 == x2 && y1 == y2) puts("0");
		else if(x1 == x2 || y1 == y2 || abs(x2 - x1) == abs(y2 - y1)) puts("1");
		else puts("2");
	}

	return 0;
}
