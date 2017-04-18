#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 15
#define MASKMAX 33000
#define mp make_pair

int n, m;
int domino[MAX][2], dp[MASKMAX][MAX][MAX];
int left, right;
bool mark[MAX];

int opt(int mask, int i, int l)
{
	if(i == n)
	{
		if(l == right) return 1;
		return 0;
	}
	if(dp[mask][i][l] != -1) return dp[mask][i][l];	

	int sol = 0;
	for(int j=0; !sol && j<m; ++j)
		if(!((1 << j) & mask))
		{
			int aux;
			if(domino[j][0] == l) aux = domino[j][1]; 
			else if(domino[j][1] == l) aux = domino[j][0];
			else continue;
			sol = opt(mask | (1 << j), i+1, aux);
		}
	

	return dp[mask][i][l] = sol;
}

int main()
{
	while(scanf("%d %d", &n, &m) && n)
	{
		scanf("%*d %d %d %*d", &left, &right);
		for(int i=0; i<m; ++i) scanf("%d %d", &domino[i][0], &domino[i][1]);

		memset(mark, 0, sizeof(mark));
		memset(dp, -1, sizeof(dp));
		int can = opt(0, 0, left);
		puts(can ? "YES" : "NO");
	}

	return 0;
}
