/*
2SAT

Description, Example: (a v b) ^ (not(a) v c) ^ ... ^ (not(c) v d). Discover if there is a configuration that the expression is true.

Solution: 
a v b == not(a) -> b == not(b) -> a
Create implication graph G: add edges (not(a), b), (not(b), a), considering second and third expressions above.
if for any a there exists paths from a to not(a) and from not(a) to a then return UNSATISFIABLE else return SATISFIABLE

Corner case:
(expression) ^ a : add only (not(a), a) edge
(expression) ^ not(a) : add only (a, not(a)) edge
*/

#include<cstdio>
#include<vector>
using namespace std;

#define MAX 20010
#define WHITE -1
#define pb push_back

//problem variables
int p, c, x, y, z, w;

//2 sat variables
vector<int> g[MAX], s;
int n, dfsCounter, numScc, low[MAX], num[MAX], component[MAX]; //n number of boolean variables (considering a and not(a))
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

//returns id of not(i)
inline int notId(int i)
{
	return i + p;
}

int main()
{
	while(scanf("%d %d", &c, &p) && c)
	{
		n = 2*p;

		//clear graph
		for(int i=0; i<=n; ++i) g[i].clear();

		while(c--)
		{
			scanf("%d %d %d %d", &x, &y, &w, &z);
			--x; --y; --w; --z;
			if(x != -1 || y != -1) //problem condition
			{
				if(x > y) swap(x, y); //problem condition
				if(x == -1) g[notId(y)].pb(y); //(expression) ^ y
				else
				{ 
					//x v y
					g[notId(x)].pb(y); g[notId(y)].pb(x);
				}
			}
			if(w != -1 || z != -1)
			{
				if(w > z) swap(w, z);
				if(w == -1) g[z].pb(notId(z));
				else
				{
					//not(w) v not(z)
					g[w].pb(notId(z)); g[z].pb(notId(w));
				}
			}
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
		for(int i=0; i<p && sat; ++i) //for don't iterate over not
			if(component[i] == component[notId(i)])
				sat = 0;

		(sat) ? puts("yes") : puts("no");
	}

	return 0;
}
