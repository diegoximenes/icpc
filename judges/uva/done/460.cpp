#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int t, xl1, yl1, xr1, yr1, xl2, yl2, xr2, yr2;
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d %d", &xl1, &yl1, &xr1, &yr1);
		scanf("%d %d %d %d", &xl2, &yl2, &xr2, &yr2);
		
		if((xl2 >= xr1) || (xr2 <= xl1) || (yl2 >= yr1) || (yr2 <= yl1))
			puts("No Overlap");
		else
			printf("%d %d %d %d\n", max(xl1, xl2), max(yl1, yl2), min(xr1, xr2), min(yr1, yr2));
		if(t != 0)
			puts("");
	}
	
	return 0;
}
