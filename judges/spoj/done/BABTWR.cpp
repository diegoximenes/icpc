#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 1e9
#define MAX 35

int n, cube[MAX][4], dp[6*MAX][MAX][6];
const int rot[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}}, numberOfRot = 6;

int opt(int i, int last, int lastRotation)
{
	if(i == 6*n+1) return 0;
	int &state = dp[i][last][lastRotation];
	if(state != -1) return state;
	
	int sol = opt(i+1, last, lastRotation);
	int x = cube[last][rot[lastRotation][0]], y = cube[last][rot[lastRotation][1]];
	for(int k=1; k<=n; ++k)
		for(int j=0; j<numberOfRot; ++j)
		{
			int x2 = cube[k][rot[j][0]], y2 = cube[k][rot[j][1]], z2 = cube[k][rot[j][2]];
		
			if(x2 < x && y2 < y) sol = max(sol, z2 + opt(i+1, k, j));
		}
	
	return state = sol;
}

int main()
{
	while(scanf("%d", &n) && n)
	{
		for(int i=1; i<=n; ++i) scanf("%d %d %d", &cube[i][0], &cube[i][1], &cube[i][2]);
		cube[0][0] = cube[0][1] = cube[0][2] = INF;

		memset(dp, -1, sizeof(dp));
		printf("%d\n", opt(1, 0, 0));
	}


	return 0;
}
