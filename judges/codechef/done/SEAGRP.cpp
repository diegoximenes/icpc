/*
Maximum matching
O(n**3) // can be O(m*n**2)
*/

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define pb push_back
#define MAX 105

vector<int> g[MAX];
int n, match[MAX], base[MAX], p[MAX], q[MAX];
bool blossom[MAX];
bool usedLca[MAX], usedFindPath[MAX];

int lca(int a, int b)
{
	memset(usedLca, 0, sizeof(usedLca));
	while(1)
	{
		a = base[a];
		usedLca[a] = 1;
		if(match[a] == -1) break;
		a = p[match[a]];
	}
	while(1)
	{
		b = base[b];
		if(usedLca[b]) return b;
		b = p[match[b]];
	}
}

void markPath(int v, int b, int children)
{
	for(; base[v] != b; v = p[match[v]])
	{
		blossom[base[v]] = blossom[base[match[v]]] = 1;
		p[v] = children;
		children = match[v];
	}
}

int findPath(int root)
{
	memset(usedFindPath, 0, sizeof(usedFindPath));
	memset(p, -1, sizeof(p));
	memset(q, 0, sizeof(q));
	for(int i=0; i<n; ++i) base[i] = i;

	usedFindPath[root] = 1;
	int qh = 0, qt = 0;
	q[qt++] = root;
	while(qh < qt)
	{
		int v = q[qh++];
		for(int j=0; j<(int)g[v].size(); ++j)
		{
			int to = g[v][j];

			if(base[v] == base[to] || match[v] == to) continue;
			if(to == root || match[to] != -1 && p[match[to]] != -1)
			{
				int curbase = lca(v, to);
				memset(blossom, 0, sizeof(blossom));
				markPath(v, curbase, to);
				markPath(to, curbase, v);
				for(int i=0; i<n; ++i)
					if(blossom[base[i]])
					{
						base[i] = curbase;
						if(!usedFindPath[i])
						{
							usedFindPath[i] = 1;
							q[qt++] = i;
						}
					}
			}
			else if(p[to] == -1)
			{
				p[to] = v;
				if(match[to] == -1) return to;
				to = match[to];
				usedFindPath[to] = 1;
				q[qt++] = to;
			}
		}
	}
	return -1;
}

int maxMatching()
{
	memset(match, -1, sizeof(match));
	memset(p, 0, sizeof(p));
	for(int i=0; i<n; ++i)
		if(match[i] == -1)
		{
			int v = findPath(i);
			while(v != -1)
			{
				int pv = p[v], ppv = match[pv];
				match[v] = pv;
				match[pv] = v;
				v = ppv;
			}
		}

	int matches = 0;
	for(int i=0; i<n; ++i)
		if(match[i] != -1)
			++matches;
	return matches/2;
}

int main()
{
	int t, u, v, m;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i) g[i].clear();
		for(int i=0; i<m; ++i)
		{
			scanf("%d %d", &u, &v);
			u--; v--;
			g[u].pb(v); g[v].pb(u);
		}

		int match = maxMatching();
		if(match*2 == n && m > match) puts("YES");
		else puts("NO");
	}

	return 0;
}
