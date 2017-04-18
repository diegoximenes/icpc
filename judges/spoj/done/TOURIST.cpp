#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 105
#define INF 1e9

char g[MAX][MAX];
int dp[MAX][MAX][2*MAX], delta[4][2] = {{1, 1}, {1, 0}, {0, 1}, {0, 0}};
int w, h;

bool can(int r1, int c1, int r2, int c2)
{
	if(r1>=0 && r1<h && r2>=0 && r2<h && c1>=0 && c1<w && c2>=0 && c2<w)
		return 1;
	return 0;
}

int solve(int r1, int r2, int steps)
{
	int c1 = steps-r1, c2 = steps-r2, count = 0;
	
	if(!can(r1, c1, r2, c2))
		return -INF;

	if(dp[r1][r2][steps] != -1)
		return dp[r1][r2][steps];
	if(r1==h-1 && r2==h-1 && steps==h+w-2)
		return dp[r1][r2][steps] = (g[h-1][w-1]=='*' ? 1 : 0);
	if(g[r1][c1]=='#' || g[r2][c2]=='#')
		return dp[r1][r2][steps] = -INF;
	
	bool g1 = (g[r1][c1]=='*' ? 1 : 0), g2 = (g[r2][c2]=='*' ? 1 : 0);
	if(g1)
		++count;
	if(g2)
		++count;
	if(r1==r2 && c1==c2 && g1)
		--count;
	
	int countaux = -INF;
	for(int i=0; i<4; ++i)
		countaux = max(countaux, solve(r1+delta[i][0], r2+delta[i][1], steps+1));

	return dp[r1][r2][steps] = count + countaux;
}

int main()
{
	int t;
	char line[MAX+100];

	gets(line);
	sscanf(line, "%d", &t);
	while(t--)
	{
		gets(line);
		sscanf(line, "%d %d", &w, &h);
		for(int i=0; i<h; ++i)
			gets(g[i]);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", solve(0, 0, 0));
	}

	return 0;
}
