#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 1e9
#define MAX 110

int main()
{	
	int n, x, y, cntx = 0, cnty = 0;
	bool hasx[MAX], hasy[MAX];
	
	memset(hasx, 0, sizeof(hasx));
	memset(hasy, 0, sizeof(hasy));
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &x, &y);
		if(hasx[x] == 0) cntx++, hasx[x] = 1;
		if(hasy[y] == 0) cnty++, hasy[y] = 1;
	}

	printf("%d\n", min(cntx, cnty));

	return 0;
}
