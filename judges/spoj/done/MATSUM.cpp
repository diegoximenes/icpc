/*
BIT 2D

Tested with: MATSUM (spoj)
First indice: x = 1, y = 1
Missing: scale, findFreqGreatest
*/

#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 1100

int tree[MAX][MAX], n, m;

//increase value by v
inline void increase(int x, int y, int v)
{
	int i = x, j;
	while(i <= n)
	{
		j = y;
		while(j <= m)
		{
			tree[i][j] += v;
			j += (j & -j);
		}
		i += (i & -i);
	}
}

inline int read(int x, int y)
{
	int sum = 0;
	int i = x, j;
	while(i > 0)
	{
		j = y;
		while(j > 0)
		{
			sum += tree[i][j];
			j -= (j & -j);
		}
		i -= (i & -i);
	}
	return sum;
}

inline int read(int x1, int y1, int x2, int y2)
{
	return (read(x2, y2) - read(x1 - 1, y2) - read(x2, y1 - 1) + read(x1 - 1, y1 - 1));
}	

inline void update(int x, int y, int v)
{
	increase(x, y, -read(x, y, x, y));
	increase(x, y, v);
}



inline void init(int x, int y)
{
	n = x; m = y;
	memset(tree, 0, sizeof(tree));
}

int main()
{
	int tc, N, x1, x2, y1, y2, v;
	char op[5];
	
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d", &N);
		init(N, N);

		while(scanf(" %s", op) && strcmp(op, "END") != 0)
		{
			if(!strcmp(op, "SET"))
			{
				scanf("%d %d %d", &x1, &y1, &v); //x,y can be zero
				++x1; ++y1;
				update(x1, y1, v);
			}
			else
			{
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				++x1; ++y1; ++x2; ++y2;
				printf("%d\n", read(x1, y1, x2, y2));
			}
		}
	}

	return 0;
}
