#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

#define MAX 22
#define mp make_pair
#define pb push_back

int n, m;
int g[MAX][MAX];
const int neighbor[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

bool can(int i, int j)
{
	if(i>=0 && i<n && j>=0 && j<m)
		return 1;
	return 0;
}

int solve(int i, int j)
{
	int ni, nj, nni, nnj, sol = 0;
	
	for(int k=0; k<4; ++k)
	{
		ni = i + neighbor[k][0]; nj = j + neighbor[k][1];
		nni = ni + neighbor[k][0]; nnj = nj + neighbor[k][1];
		if(can(ni, nj) && g[ni][nj] == 2 && can(nni, nnj) && g[nni][nnj] == 0)
		{
			g[ni][nj] = 0; g[i][j] = 0; g[nni][nnj] = 1;
			sol = max(sol, 1 + solve(nni, nnj));
			g[ni][nj] = 2; g[i][j] = 1; g[nni][nnj] = 0;
		}
	}	

	return sol;
}

int main()
{
	vector< pair<int, int> > initial;

	while(scanf("%d %d", &n, &m) && n)
	{
		int i=0, j=0, upper = ceil(((double)n*(double)m)/2.0);
		initial.clear();
		for(int k=0; k<upper; ++k)
		{
			scanf("%d", &g[i][j]);
			if(g[i][j] == 1) initial.pb(mp(i, j));
			j += 2;
			if(j >= m)
			{
				++i;
				j = i%2;
			}
		}
		
		int sol = 0;
		for(int k=0; k<(int)initial.size(); ++k)
			sol = max(sol, solve(initial[k].first, initial[k].second));
		printf("%d\n", sol);
	}
	
	return 0;
}
