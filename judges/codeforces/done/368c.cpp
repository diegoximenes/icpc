#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

#define MAX 100010

int main()
{
	char s[MAX];
	int count[MAX][3], n, l, r;
	
	scanf(" %s", s);
	int len = strlen(s);
	count[0][0] = count[0][1] = count[0][2] = 0;
	count[1][0] = count[1][1] = count[1][2] = 0;
	count[1][s[0] - 'x']++;
	for(int i=2; i<=len; ++i)
	{
		count[i][0] = count[i-1][0];
		count[i][1] = count[i-1][1];
		count[i][2] = count[i-1][2];
		count[i][s[i-1] - 'x']++;
	}
	
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d %d", &l, &r);
		if(r - l + 1 < 3) puts("YES");
		else
		{
			int x = count[r][0] - count[l-1][0];
			int y = count[r][1] - count[l-1][1];
			int z = count[r][2] - count[l-1][2];
			
			if((x == y && y == z) || (abs(x - y) == 1 && (y == z || x == z))  || (abs(x - z) == 1 && (x == y || z == y)) || (abs(z - y) == 1 && (z == x || y == x))) puts("YES");
			else puts("NO");
		}
	}

	return 0;
}
