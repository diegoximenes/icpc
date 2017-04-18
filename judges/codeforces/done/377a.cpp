#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 505

bool mark[MAX][MAX];
int n, m, k, cnt, cntEmpty;
char g[MAX][MAX];
const int neigh[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

inline bool can(int i, int j)
{
	if(i>=0 && i<n && j>=0 && j<m) return 1;
	return 0;
}

void dfs(int i, int j)
{
	if(cnt == cntEmpty - k) return;
	mark[i][j] = 1;
	cnt++;
	for(int l=0; l<4; ++l)
	{
		int ni = i + neigh[l][0], nj = j + neigh[l][1];
		if(can(ni, nj) && g[ni][nj] == '.' && !mark[ni][nj]) dfs(ni, nj);
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0; i<n; ++i) scanf(" %s", g[i]);
	
	cntEmpty = 0;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(g[i][j] == '.')
				++cntEmpty;

	cnt = 0; memset(mark, 0, sizeof(mark));
	bool called = 0;
	for(int i=0; !called && i<n; ++i)
		for(int j=0; !called && j<m; ++j)
			if(g[i][j] == '.')
				dfs(i, j), called = 1;
	
	for(int i=0; i<n; ++i, puts(""))
		for(int j=0; j<m; ++j)
		{
			if(g[i][j] == '.' && !mark[i][j]) putchar('X');
			else putchar(g[i][j]);
		}

	return 0;
}
