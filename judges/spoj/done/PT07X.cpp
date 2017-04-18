#include<cstdio>
#include<cstring>
#include<list>
#include<queue>
using namespace std;

#define pb push_back
#define MAX 100010

int n;
bool mark[MAX];
list<int> g[MAX];
list<int>::iterator it, it2;

int vertexCoverTree()
{
	queue<int> q;
	for(int i=0; i<n; ++i)
		if((int)g[i].size() == 1)
			q.push(i);

	int sol = 0;
	memset(mark, 0, sizeof(mark));
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(!mark[u] && (int)g[u].size() == 1)
		{
			mark[u] = 1;
			int v = *g[u].begin();
			if(!mark[v]) //v is in vertex cover set
			{
				mark[v] = 1;
				++sol;
				for(it=g[v].begin(); it!=g[v].end(); ++it)
				{
					int x = *it;
					for(it2=g[x].begin(); it2!=g[x].end(); ++it2)
						if(*it2 == v)
						{
							g[x].erase(it2);
							break;
						}
					if((int)g[x].size() == 1) q.push(x);
				}
			}
		}
	}

	return sol;
}

int main()
{
	int u, v;
	
	scanf("%d", &n);
	for(int i=1; i<n; ++i)
	{
		scanf("%d %d", &u, &v);
		--u; --v;
		g[u].pb(v); g[v].pb(u);
	}

	printf("%d\n", vertexCoverTree());

	return 0;
}
