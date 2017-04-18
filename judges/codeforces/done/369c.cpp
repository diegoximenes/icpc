#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 100010

bool isLeaf[MAX], mark[MAX];
int set[MAX], countLeafs, n, auxn;
vector<int> g[MAX];
vector< pair<int, int> > edges;

void init(int n)
{
	for(int i=0; i<n; ++i) set[i] = i;
}

int find(int i)
{
	return (set[i] == i) ? i : set[i] = find(set[i]);
}

void unionSet(int i, int j)
{
	set[find(j)] = find(i);
	--countLeafs;
}

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	memset(mark, 0, sizeof(mark)); mark[s] = 1;
	for(int i=0; i<n; ++i) isLeaf[find(i)] = 1;
	while(!q.empty())
	{
		int v = q.front(); q.pop();
		bool l = 1;
		for(int i=0; i<(int)g[v].size(); ++i)
		{
			int u = g[v][i];
			if(!mark[u])
			{
				isLeaf[v] = 0;
				l = 0;
				q.push(u); mark[u] = 1;
			}
		}
		if(!l) --countLeafs;
	}
}

int main()
{	
	scanf("%d", &n);
	countLeafs = auxn = n;
	init(n);
	for(int i=0; i<n-1; ++i)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		if(w == 1) unionSet(min(u, v), max(u, v)), auxn--;
		else edges.pb(mp(u, v));
	}
	for(int i=0; i<(int)edges.size(); ++i) g[find(edges[i].first)].pb(find(edges[i].second)), g[find(edges[i].second)].pb(find(edges[i].first));
	bfs(find(0));
	
	if(auxn == 1) puts("0");
	else
	{
		printf("%d\n", countLeafs);
		bool first;
		memset(mark, 0, sizeof(mark));
		for(int i=0; i<n; ++i)
			if(isLeaf[find(i)] && !mark[find(i)])
			{
				mark[find(i)] = 1;
				if(first) printf("%d", find(i)+1), first = 0;
				else printf(" %d", find(i)+1);
			}
		puts("");
	}

	return 0;
}
