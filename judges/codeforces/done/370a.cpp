#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	int x1, x2, y1, y2;

	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	
	if(x1 == x2 && y1 == y2) 
	{
		puts("0 0 0");
		return 0;
	}

	printf("%d", ((x2 == x1) || (y2 == y1)) ? 1 : 2);
	if((x1%2==0 && y1%2==1) || (x1%2==1 && y1%2==0)) //black
	{
		if((x2%2==0 && y2%2==1) || (x2%2==1 && y2%2==0)) //black
		{
			if(abs(x2-x1) == abs(y2-y1)) printf(" 1");
			else printf(" 2");
		}
		else printf(" 0");
	}
	 
	if((x1%2==1 && y1%2==1) || (x1%2==0 && y1%2==0)) //white
	{
		if((x2%2==1 && y2%2==1) || (x2%2==0 && y2%2==0)) //white
		{
			if(abs(x2-x1) == abs(y2-y1)) printf(" 1");
			else printf(" 2");
		}
		else printf(" 0");
	}

	printf(" %d\n", (abs(x2-x1) == abs(y2-y1)) ? abs(x2-x1) : max(abs(x2-x1), abs(y2-y1)));
	
	return 0;
}
