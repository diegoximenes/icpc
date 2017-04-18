#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define pb push_back
#define MAX 50010
typedef long long ll;

int n, m, win[MAX], mark[MAX];
ll sol2;
vector<int> g[MAX];

int dfs(int u)
{
	int cnt = win[u];
	bool counted = 0;
	
	mark[u] = 1;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(!mark[v])
		{
			int aux = dfs(v);
			cnt += aux;
			
			if(!win[u] && aux && !counted)
				counted = 1, sol2++;
		}
	}

	return cnt;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; ++i) scanf("%d", &win[i]);
	while(m--)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		--u; --v;
		g[u].pb(v); g[v].pb(u);
	}
	
	ll sol1 = 0;
	memset(mark, 0, sizeof(mark));
	for(int i=0; i<n; ++i)
		if(!mark[i] && win[i])
		{
			ll cnt = dfs(i);
			sol1 += cnt*(cnt-1)/(2LL);
			if(cnt > 1) sol2 += cnt;
		}
	cout << sol1 << " " << sol2 << endl;

	return 0;
}
