/*
Find distance between two tree nodes.
Find the kth node in path from two nodes.
Tested with: http://www.spoj.com/problems/QTREE2/
*/

#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

#define pb push_back
#define mp make_pair

#define NMAX 10010
#define LOGNMAX 15

const int root = 0;
vector< pair<int, int> > g[NMAX];
int level[NMAX], dad[NMAX], ancestor[NMAX][LOGNMAX], dist[NMAX][LOGNMAX];
bool mark[NMAX];

inline int log2(int x)
{
	int log;
	for(log=1; (1 << log) <= x; ++log);
	--log;
	return log;
}

void build(int n)
{
	memset(ancestor, -1, sizeof(ancestor));

	for(int i=0; i<n; ++i) ancestor[i][0] = dad[i];
	for(int j=1; (1 << j) < n; ++j)
		for(int i=0; i<n; ++i)
			if(ancestor[i][j-1] != -1)
			{
				ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
				dist[i][j] = dist[i][j-1] + dist[ancestor[i][j-1]][j-1];
			}
}

//first is the node, second is the dist from p to level l
pair<int, int> findAncestorOnLevel(int p, int l, int log)
{
	int totalDist = 0;
	for(int i=log; i>=0; --i)
		if(level[p] - (1 << i) >= l)
		{
			totalDist += dist[p][i];
			p = ancestor[p][i];
		}
	return mp(p, totalDist);
}

//first is the common ancestor and second is the dist between p and q
pair<int, int> findCommonAncestor(int p, int q)
{
	if(level[p] < level[q]) swap(p, q);

	int log = log2(level[p]);

	pair<int, int> tuple = findAncestorOnLevel(p, level[q], log);	
	p = tuple.first;
	int totalDist = tuple.second;
	
	if(p == q) return mp(p, totalDist);

	for(int i=log; i>=0; --i)
		if(ancestor[p][i] != -1 && ancestor[p][i] != ancestor[q][i])
		{
			totalDist += dist[p][i] + dist[q][i];
			p = ancestor[p][i], q = ancestor[q][i];
		}
	
	return mp(dad[p], totalDist + dist[p][0] + dist[q][0]);
}

//return kth node in path from p to q
int lcaKth(int p, int q, int k)
{
	int commonAncestor = findCommonAncestor(p, q).first;
	--k; //now k is the number of edges between p and the return node

	if(k == 0) return p;
	else if(level[p] - level[commonAncestor] == k) return commonAncestor; //kth element is the commonAncestor
	else if(level[p] - level[commonAncestor] < k) //kth element is on the path [commonAncestor -> q]
	{
		k -= (level[p] - level[commonAncestor]);
		if(level[q] - level[commonAncestor] == k) return q;
		
		int logq = log2(level[q]);
		return findAncestorOnLevel(q, level[commonAncestor] + k, logq).first;
	}
	else //kth element is on the path[p -> commonAncestor]
	{
		int logp = log2(level[p]);
		return findAncestorOnLevel(p, level[p] - k, logp).first;
	}
}

void dfs(int v, int dadv, int l, int d)
{
	mark[v] = 1; level[v] = l; dad[v] = dadv; dist[v][0] = d;
	for(int i=0; i<(int)g[v].size(); ++i)
		if(!mark[g[v][i].first])
			dfs(g[v][i].first, v, l + 1, g[v][i].second);
}

int main()
{
	int t, u, v, w, n, k;
	char op[10];
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i=0; i<n; ++i) g[i].clear();
		for(int i=1; i<n; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			--u; --v;
			g[u].pb(mp(v, w)); g[v].pb(mp(u, w));	
		}
		
		memset(mark, 0, sizeof(mark));
		dfs(root, -1, 0, 0);
		build(n);

		while(scanf(" %s ", op) && strcmp(op, "DONE") != 0)
		{	
			scanf("%d %d", &u, &v);
			--u; --v;
			if(!strcmp(op, "DIST")) printf("%d\n", findCommonAncestor(u, v).second);
			else
			{
				scanf("%d", &k);
				printf("%d\n", lcaKth(u, v, k)+1);
			}
		}
		puts("");
	}
	return 0;
}
