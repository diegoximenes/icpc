#include<cstdio>
using namespace std;

#define MAX 305

int main()
{
	char g[MAX][MAX];
	int n;

	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf(" %s", g[i]);
	
	bool x = 1;
	for(int i=0; x && i<n; ++i)
	{
		if(g[i][i] != g[0][0]) x = 0;
		if(g[i][n-i-1] != g[0][0]) x = 0;

		for(int j=0; x && j<n; ++j)
			if(j != i && j != n-i-1 && n > 2 && (g[i][j] != g[0][1] || g[i][j] == g[0][0]))
				x = 0;
	}

	puts(x ? "YES" : "NO");

	return 0;
}
