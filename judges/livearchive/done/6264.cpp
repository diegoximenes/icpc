#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

#define pb push_back
#define MAX 100010

vector<int> g[MAX];
int lab[MAX], t, n, m, u, v, deg[MAX];

int solve(bool first)
{
	queue<int> q1, q2;

	for(int i=0; i<n; ++i)
		for(int j=0; j<(int)g[i].size(); ++j)
			deg[g[i][j]]++;

	for(int i=0; i<n; ++i)
		if(!deg[i])
		{
			if(lab[i] == 1) q1.push(i);
			else q2.push(i);
		}
	
	int cnt = 0;
	while(!q1.empty() || !q2.empty())
	{
		if(first) 
		{
			if(!q1.empty()) v = q1.front(), q1.pop();
			else v = q2.front(), q2.pop(), first = 0, cnt++;
		}
		else
		{
			if(!q2.empty()) v = q2.front(), q2.pop();
			else v = q1.front(), q1.pop(), first = 1, cnt++;
		}
		for(int i=0; i<(int)g[v].size(); ++i)
		{
			u = g[v][i]; --deg[u];
			if(!deg[u])
			{
				if(lab[u] == 1) q1.push(u);
				else q2.push(u);
			}
		}
	}

	return cnt;
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i) g[i].clear(), scanf("%d", &lab[i]), deg[i] = 0;

		while(m--)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			g[u].pb(v); 
		}

		printf("%d\n", min(solve(0), solve(1)));
	}

	return 0;
}
