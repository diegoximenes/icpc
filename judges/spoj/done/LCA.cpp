/*
LCA: O(n*logn) for construction and O(logn) fo queries.
Tested with: www.spoj.com/problems/LCA 

BUILD:
ancestor[1,n][1,log(n)], ancestor[i][j] is 2^jth ancestor of i: 2^j = 2^(j-1) + 2^(j-1) : ancestor[ancestor[i][j-1] == 2^(j-1)][j-1]
if(j == 0) ancestor[i][j] = tree[i];
else ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1]


QUERY:
Let L[i] be the level of node i in the tree. We must observe that if p and q are on the same level in the tree we can compute LCA(p, q) using a meta-binary search. So, for every power j of 2 (between log(L[p]) and 0, in descending order), if P[p][j] != P[q][j] then we know that LCA(p, q) is on a higher level and we will continue searching for LCA(p = P[p][j], q = P[q][j]). At the end, both p and q will have the same father, so return T[p]. Let's see what happens if L[p] != L[q]. Assume, without loss of generality, that L[p] < L[q]. We can use the same meta-binary search  for finding the ancestor of p situated on the same level with q, and then we can compute the LCA
*/

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define pb push_back

#define NMAX 1010
#define LOGNMAX 10

vector<int> g[NMAX];
int level[NMAX], dad[NMAX], ancestor[NMAX][LOGNMAX];
bool mark[NMAX];

//O(n*logn)
void build(int n)
{
	memset(ancestor, -1, sizeof(ancestor));

	for(int i=0; i<n; ++i) ancestor[i][0] = dad[i];

	for(int j=1; (1 << j) < n; ++j)
		for(int i=0; i<n; ++i)
			if(ancestor[i][j-1] != -1)
				ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
}

//O(logn)
int lca(int p, int q)
{
	int log;
	
	//if v is situated on a higher level than u then swap them
	if(level[p] < level[q]) swap(p, q);

	//compute log(level[v])
	for(log=1; (1 << log) <= level[p]; ++log);
	--log;
	
	//find the ancestor of v situated on the same level of u
	for(int i=log; i>=0; --i)
		if(level[p] - (1 << i) >= level[q])
			p = ancestor[p][i];

	if(p == q) return p;

	for(int i=log; i>=0; --i)
		if(ancestor[p][i] != -1 && ancestor[p][i] != ancestor[q][i])
			p = ancestor[p][i], q = ancestor[q][i];
	
	return dad[p];
}

void dfs(int v, int dadv, int dist)
{
	if(mark[v]) return;
	mark[v] = 1; level[v] = dist; dad[v] = dadv;
	for(int i=0; i<(int)g[v].size(); ++i)
		dfs(g[v][i], v, dist + 1);
}

//problem stuff
int main()
{
	int t, u, v, root, n, k, q;
	bool isRoot[NMAX];
	
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf("%d", &n);
		for(int i=0; i<n; ++i) g[i].clear(), isRoot[i] = 1;
		for(int i=0; i<n; ++i)
		{
			scanf("%d", &k);
			while(k--)
			{
				scanf("%d", &u);
				--u;
				g[u].pb(i); g[i].pb(u);
				isRoot[u] = 0;
			}
		}
		for(int i=0; i<n; ++i)
			if(isRoot[i])
			{
				root = i;
				break;
			}
		memset(mark, 0, sizeof(mark));
		dfs(root, 0, 0);
		build(n);
		
		printf("Case %d:\n", tc);
		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			printf("%d\n", lca(u, v) + 1);
		}
	}
	return 0;
}
