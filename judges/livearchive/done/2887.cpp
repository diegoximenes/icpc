#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define MAX 1005

int n, m, k, deg[MAX], mark[MAX];
bool g[MAX][MAX];

int dfs(int u)
{
    mark[u] = 1;
    int sol = 1;
    for(int v=0; v<n; ++v)
        if(g[u][v] && !mark[v]) 
			sol += dfs(v);
	return sol;
}

int main()
{
    while(scanf("%d %d %d", &n, &m, &k) && n)
    {
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j) g[i][j] = 0;
            mark[i] = 0; deg[i] = 0;
        }

        while(m--)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            --u; --v;
            if(u == v || g[u][v]) continue;
            g[u][v] = g[v][u] = 1;
            deg[u]++; deg[v]++;
        }
		
		queue<int> q;	
		for(int i=0; i<n; ++i)
			if(deg[i] < k)
				q.push(i);
	
		while(!q.empty())
		{
			int u = q.front(); q.pop();
			for(int v=0; v<n; ++v)
				if(g[u][v])
				{
					g[u][v] = g[v][u] = 0;
					--deg[v]; --deg[u];
					if(deg[v] < k) q.push(v);
				}
		}
		
		int sol = 0;
        for(int i=0; i<n; ++i)
            if(!mark[i])
			{
				int lsol = dfs(i);
				if(lsol == 1) continue;
                sol = max(sol, lsol);
			}

        printf("%d\n", sol);
    }

    return 0;
}
