#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define pb push_back
#define MAX 30

const int cntl = 'z' - 'a' + 1;
bool mark[MAX];
bool g[MAX][MAX];
int dad[MAX], dist[MAX], deg[MAX];
vector<int> vcycle;

bool dfs(int u, int dadu, int root)
{
	bool cycle = 0;

	mark[u] = 1;
	dad[u] = dadu;
	for(int i=0; i<cntl; ++i)
		if(i != dadu && g[u][i])
		{
			if(mark[i])
			{
				if(i == root)
				{
					cycle = 1;
					for(int v = u; v != i; v = dad[v]) vcycle.pb(v);
					vcycle.pb(i);
					reverse(vcycle.begin(), vcycle.end());
				}
			}
			else cycle = dfs(i, u, root);

			if(cycle) return 1;
		}
	return 0;
}

int main()
{
	int t, n;
	char dig[5];

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		
		vcycle.clear();	
		for(int i=0; i<cntl; ++i)
		{
			for(int j=0; j<cntl; ++j) g[i][j] = 1;
			deg[i] = cntl;
		}

		for(int i=0; i<n; ++i)
		{
			scanf(" %s ", dig);
			g[dig[0] - 'a'][dig[1] - 'a'] = 0;
			deg[dig[1] - 'a']--;
		}
		
		bool cycle = 0;
		for(char c='a'; !cycle && c<='z'; ++c)
		{
			memset(mark, 0, sizeof(mark));
			cycle = dfs(c - 'a', -1, c - 'a');
		}
		
		vector<char> out;
		if(cycle)
		{
			for(int i=0; i<39 ;++i) out.pb(vcycle[i%((int)vcycle.size())] + 'a');
			
		}
		else
		{
			queue<int> q;
			for(int i=0; i<cntl; ++i)
				if(!deg[i])
					q.push(i);

			memset(dist, 0, sizeof(dist));
			memset(dad, -1, sizeof(dad));
			while(!q.empty())
			{
				int u = q.front(); q.pop();
				for(int v=0; v<cntl; ++v)
					if(g[u][v])
					{
						--deg[v];
						if(!deg[v]) q.push(v);
						if(dist[v] < dist[u] + 1) dist[v] = dist[u] + 1, dad[v] = u;
					}
			}
			
			int maxdistu = -1, maxdist = -1;
			for(int u=0; u<cntl; ++u)
				if(dist[u] > maxdist && deg[u] == 0)
					maxdist = dist[u], maxdistu = u;
			
			for(int u = maxdistu; u != -1; u = dad[u]) out.pb(u + 'a');
			reverse(out.begin(), out.end());
		}
		
		int n = min((int)(out.size() + 1)/2, 20);
		if(cycle) n = 20;
		
		for(int i=0; i<n; ++i, puts(""))
			for(int j=i; j<i+n; ++j)
				putchar(out[j]);
	}


	return 0;
}
