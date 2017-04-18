#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define mp make_pair
#define MAX 100
#define MAX2 10

inline bool can(int i, int j, int n)
{
	if(i >= 0 && i < n && j >= 0 && j < n) return 1;
	return 0;
}

int main()
{
	int n, v[MAX], out[MAX2][MAX2];
	bool mark[MAX2][MAX2];
	const int neigh[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	scanf("%d", &n);
	for(int i=0; i<n*n; ++i) scanf("%d", &v[i]);
	sort(v, v + n*n);
	
	int k = n*n - 1;
	queue< pair<int, int> > q;
	q.push(mp(n/2, n/2));
	memset(mark, 0, sizeof(mark));
	mark[n/2][n/2] = 1;
	while(!q.empty())
	{
		pair<int, int> u = q.front(); q.pop();
		out[u.first][u.second] = v[k--];

		for(int i=0; i<4; ++i)
		{
			int i2 = u.first + neigh[i][0], j2 = u.second + neigh[i][1];
			if(can(i2, j2, n) && !mark[i2][j2]) q.push(mp(i2, j2)), mark[i2][j2] = 1;
		}
	}
	
	for(int i=0; i<n; ++i, puts(""))
		for(int j=0; j<n; ++j)
		{
			printf("%d", out[i][j]);
			if(j < n-1) putchar(' ');
		}

	return 0;
}
