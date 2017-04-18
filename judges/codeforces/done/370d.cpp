#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 2010
#define INF (int) 1e9

int n, m;
bool printed, mark[MAX][MAX];
char g[MAX][MAX];

void print(int x, int y, int len)
{
	if(x + len > n || x < 0 || y + len > m || y < 0 || printed) return;

	memset(mark, 0, sizeof(mark));
	for(int i=x; i<x+len; ++i)
	{
		if(g[i][y] != 'w') mark[i][y] = 1;
		if(g[i][y+len-1] != 'w') mark[i][y+len-1] = 1;
	}
	for(int i=y; i<y+len; ++i)
	{
		if(g[x][i] != 'w') mark[x][i] = 1;
		if(g[x+len-1][i] != 'w') mark[x+len-1][i] = 1;
	}
	
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(g[i][j] == 'w' && (i != x && i != x + len - 1 && j != y && j != y + len - 1))
				return;
	
	for(int i=0; i<n; ++i, puts(""))
		for(int j=0; j<m; ++j)
			printf("%c", (mark[i][j]) ? '+' : g[i][j]);
	printed = 1;
}

int main()
{
	int minx = INF, miny = INF, maxx = -INF, maxy = -INF;

	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i) scanf(" %s", g[i]);

	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(g[i][j] == 'w')
			{
				minx = min(minx, i);
				miny = min(miny, j);
				maxx = max(maxx, i);
				maxy = max(maxy, j);
			}
	int len = max(maxx - minx + 1, maxy - miny + 1);
	
	int x2 = maxx - len + 1, x3 = len - n + minx, x4 = len - maxx - 1;
	int y2 = maxy - len + 1, y3 = len - m + miny, y4 = len - maxy - 1;

	if(len > n || len > m) puts("-1"), printed = 1;
	
	print(minx, miny, len);
	print(minx, y2, len);
	print(minx, miny - y3, len);
	print(minx, maxy + y4, len);

	print(x2, miny, len);
	print(x2, y2, len);
	print(x2, miny - y3, len);
	print(x2, maxy + y4, len);
	
	print(minx - x3, miny, len);
	print(minx - x3, y2, len);
	print(minx - x3, miny - y3, len);
	print(minx - x3, maxy + y4, len);
	
	print(maxx + x4, miny, len);
	print(maxx + x4, y2, len);
	print(maxx + x4, miny - y3, len);
	print(maxx + x4, maxy + y4, len);

	print(0,0,0);
	if(!printed) puts("-1");

	return 0;
}
