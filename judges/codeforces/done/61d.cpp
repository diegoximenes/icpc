#include<cstdio>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

#define MAX (int) 1e5 + 10
#define mp make_pair

vector< pair<int, int> > g[MAX];
bitset<MAX> mark;
long long int maxdist = -1, totaldist = 0;

void dfs(int v, long long int dist)
{
	mark[v] = 1;
	maxdist = max(dist, maxdist);

	for(int i=0; i<(int)g[v].size(); ++i)
	{
		int u = g[v][i].first, w = g[v][i].second;
		if(!mark[u])
		{
			totaldist += w+w;
			dfs(u, dist+w);
		}
	}
}

int main()
{
	int n, u, v, w;
	
	scanf("%d", &n);
	while(--n)
	{
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		g[u].push_back(mp(v, w)); g[v].push_back(mp(u, w));
	}
	
	mark.reset();
	dfs(0, 0);
	cout << totaldist-maxdist << endl;

	return 0;	
}

