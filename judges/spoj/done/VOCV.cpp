#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define pb push_back

#define MAX 100015
#define MOD 10007

int t, n, dad[MAX], dpLight[MAX][2], dpCount[MAX][2];
vector<int> g[MAX];
bool mark[MAX];

void dfs(int u, int dadu)
{
	mark[u] = 1;
	dad[u] = dadu;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(!mark[v]) dfs(v, u);
	}
}

int optLight(int u, int light)
{
	int &state = dpLight[u][light];
	if(state != -1) return state;
	
	int sol = 0;
	if(light) sol = 1;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(v != dad[u])
		{
			if(!light) sol += optLight(v, 1);
			else sol += min(optLight(v, 1), optLight(v, 0));
		}
	}
	
	return state = sol;
}

int optCount(int u, int light)
{
	int &state = dpCount[u][light];
	if(state != -1) return state;
	
	int sol = 1;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(v != dad[u])
		{
			if(!light) sol = (sol * optCount(v, 1))%MOD;
			else if(optLight(v, 1) < optLight(v, 0)) sol = (sol * optCount(v, 1))%MOD;
			else if(optLight(v, 1) > optLight(v, 0)) sol = (sol * optCount(v, 0))%MOD;
			else sol = (sol * (optCount(v, 0) + optCount(v, 1)))%MOD;
		}
	}
		
	return state = sol;
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=0; i<n; ++i) g[i].clear();
		for(int i=1; i<n; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			--u; --v;
			g[u].pb(v); g[v].pb(u);
		}
		
		for(int i=0; i<n; ++i) mark[i] = 0, dpLight[i][0] = dpLight[i][1] = dpCount[i][0] = dpCount[i][1] = -1;
		dfs(0, -1);
		
		if(optLight(0, 0) < optLight(0, 1)) printf("%d %d\n", optLight(0, 0), optCount(0, 0)%MOD);
		else if(optLight(0, 0) > optLight(0, 1)) printf("%d %d\n", optLight(0, 1), optCount(0, 1)%MOD);
		else printf("%d %d\n", optLight(0, 0), (optCount(0, 0) + optCount(0, 1))%MOD);
	}

	return 0;
}

