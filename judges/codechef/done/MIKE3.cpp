#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

#define MMAX 22

int n, m, k, x;
set<int> tree[MMAX];
set<int>:: iterator it;
bool can[MMAX][MMAX];

int solve(int mask, int i)
{
	if(i == m) return 0;
	
	int sol = solve(mask, i+1);

	bool lcan = 1;
	for(int j=0; lcan && j<i; ++j)
		if(((1 << j) & mask) && !can[i][j])
			lcan = 0;
	if(lcan) sol = max(sol, 1 + solve(mask | (1 << i), i+1));

	return sol;
}

int main()
{	
	memset(can, 0, sizeof(can));
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
	{
		scanf("%d", &k);
		while(k--) scanf("%d", &x), tree[i].insert(x);

		for(int j=0; j<i; ++j)
		{
			can[i][j] = can[j][i] = 1;
			for(it=tree[j].begin(); it!=tree[j].end(); ++it)
				if(tree[i].find(*it) != tree[i].end())
				{
					can[i][j] = can[j][i] = 0;
					break;
				}
		}
	}

	printf("%d\n", solve(0, 0));

	return 0;
}
