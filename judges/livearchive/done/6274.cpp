#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;

#define MAX 2010
#define WHITE -1
#define pb push_back

int c, judges;

vector<int> g[MAX], s;
int n, dfsCounter, numScc, low[MAX], num[MAX], component[MAX]; 
bool mark[MAX];

void tarjan(int u)
{
	low[u] = num[u] = dfsCounter++;
	s.pb(u);
	mark[u] = 1;

	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(num[v] == WHITE)	tarjan(v);
		if(mark[v]) low[u] = min(low[u], low[v]);
	}

	if(low[u] == num[u])
	{
		++numScc;
		while(1)
		{
			int v = s.back(); s.pop_back(); mark[v] = 0;
			component[v] = numScc;
			if(u == v) break;
		}
	}
}

inline int notId(int i)
{
	return i + c;
}

int main()
{
	int u, v;

	while(scanf("%d %d", &c, &judges) == 2)
	{
		n = 2*c;

		for(int i=0; i<=n; ++i) g[i].clear();
		
		g[notId(0)].pb(0); 	
		while(judges--)
		{
			scanf("%d %d", &u, &v);
			int a = abs(u) - 1, b = abs(v) - 1;
			if(u > 0 && v > 0) g[notId(a)].pb(b), g[notId(b)].pb(a);
			else if(u < 0 && v > 0) g[a].pb(b), g[notId(b)].pb(notId(a));
			else if(u > 0 && v < 0) g[notId(a)].pb(notId(b)), g[b].pb(a);
			else g[a].pb(notId(b)), g[b].pb(notId(a));
		}
		
		//tarjan
		s.clear();
		dfsCounter = numScc = 0;
		for(int i=0; i<n; ++i)
		{
			mark[i] = 0;
			low[i] = 0;
			num[i] = component[i] = WHITE;
		}
		for(int i=0; i<n; ++i)
			if(num[i] == WHITE)
				tarjan(i);
		
		//2sat verification
		bool sat = 1;
		for(int i=0; i<c && sat; ++i) //for don't iterate over not
			if(component[i] == component[notId(i)])
				sat = 0;

		(sat) ? puts("yes") : puts("no");
	}

	return 0;
}
