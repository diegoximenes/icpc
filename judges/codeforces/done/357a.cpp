#include<cstdio>
using namespace std;

#define MAX 105

int main()
{
	int c[MAX], cum[MAX], n, x, y;

	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &c[i]);
		if(i == 0) cum[i] = c[i];
		else cum[i] = cum[i-1] + c[i];
	}
	scanf("%d %d", &x, &y);
	
	for(int i=0; i<n; ++i)
		if(cum[i] >= x && cum[i] <= y && (cum[n-1] - cum[i] >= x) && (cum[n-1] - cum[i] <= y))
		{
			printf("%d\n", i+2);
			return 0;
		}
	puts("0");

	
	return 0;
}
