#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define NMAX 50005
#define KMAX 505

vector<int> g[NMAX];
int n, k, dad[NMAX];
ll cntDist[NMAX][KMAX];

void dfs(int u, int dadu)
{
	dad[u] = dadu;
	cntDist[u][0] = 1;
	for(int i=1; i<=k; ++i) cntDist[u][i] = 0;

	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(v != dadu)
		{
			dfs(v, u);
			for(int j=0; j<k; ++j) cntDist[u][j+1] += cntDist[v][j];
		}
	}
}

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n-1; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		g[u].pb(v); g[v].pb(u);
	}

	dfs(0, -1);
	
	ll sol = 0, sol1 = 0;
	for(int u=0; u<n; ++u)
	{
		sol1 += cntDist[u][k];
		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int v = g[u][i];
			if(v == dad[u]) continue;

			for(int j=1; j<k; ++j)
				sol += cntDist[v][j-1] * (cntDist[u][k-j] - cntDist[v][k-j-1]);
		}
	}

	cout << sol1 + sol/2 << endl;

	return 0;
}
