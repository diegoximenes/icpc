#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 255
#define MAX2 300
#define INF 1e9

int main()
{
	int n, xmin = INF, xmax = -INF, ymin = INF, ymax = -INF, x[MAX], y[MAX];
	char m[MAX2][MAX2];
		
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf("%d %d", &x[i], &y[i]);
		xmin = min(xmin, x[i]);
		xmax = max(xmax, x[i]);
		ymin = min(ymin, y[i]);
		ymax = max(ymax, y[i]);
	}
	int dy = 0, dx = 0;
	if(ymin < 0)
		dy = -ymin;
	if(xmin < 0)
		dx = -xmin;
	for(int i = min(0, xmin); i <= max(0, xmax); ++i)
		for(int j = min(0, ymin); j <= max(0, ymax); ++j)
		{
			int yaux = j + dy, xaux = i + dx;
			if(i == 0 && j == 0)
				m[xaux][yaux] = '+';
			else if(j == 0)
				m[xaux][yaux] = '-';
			else if(i == 0)
				m[xaux][yaux] = '|';
			else
				m[xaux][yaux] = '.';
		}
	for(int i=0; i<n; ++i)
		m[x[i]+dx][y[i]+dy] = '*';
	
	for(int j = max(0, ymax); j >= min(0, ymin); --j, puts(""))
		for(int i = min(0, xmin); i <= max(0, xmax); ++i)
			putchar(m[i+dx][j+dy]);
		
	return 0;
}