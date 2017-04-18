#include<cstdio>
#include<vector>
#include<queue>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define MAX 40010

vector<int> g1[MAX], g2[MAX];
int n, q, dist11[MAX], dist12[MAX], dist21[MAX], dist22[MAX];
ll cum[MAX];
bool mark[MAX];

inline pair<int, int> bfs(vector<int> *g, int *dist, int s, int size)
{
	for(int i=0; i<size; ++i) mark[i] = 0;
	mark[s] = 1; dist[s] = 0;
	queue<int> q; q.push(s);
	int last = s;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int v = g[u][i];
			if(!mark[v]) mark[v] = 1, dist[v] = dist[u] + 1, q.push(v), last = v;
		}
	}
	
	return mp(last, dist[last]);
}

inline void diameter(vector<int> *g, int *dist1, int *dist2, int size, int &diam)
{
	int ext1, ext2;
	pair<int, int> p;
		
	p = bfs(g, dist1, 0, size);
	ext1 = p.first;
	p = bfs(g, dist1, ext1, size);
	diam = p.second;
	ext2 = p.first;

	bfs(g, dist2, ext2, size);

	if(!diam) diam = 1;
}

int main()
{
	while(scanf("%d %d", &n, &q) == 2)
	{
		int u, v;
		for(int i=0; i<n; ++i) g1[i].clear();
		for(int i=0; i<q; ++i) g2[i].clear();
		for(int i=1; i<n; ++i)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			g1[u].pb(v); g1[v].pb(u);
		}
		for(int i=1; i<q; ++i)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			g2[u].pb(v); g2[v].pb(u);
		}
		
		int diam1, diam2, diam;
		diameter(g1, dist11, dist12, n, diam1);
		diameter(g2, dist21, dist22, q, diam2);
		
		for(int i=0; i<n; ++i) dist11[i] = max(dist11[i], dist12[i]);
		for(int i=0; i<q; ++i) dist21[i] = max(dist21[i], dist22[i]);
		sort(dist21, dist21 + q);
		for(int i=0; i<q; ++i)
		{
			cum[i] = dist21[i];
			if(i != 0) cum[i] += cum[i-1];
		}
		diam = max(diam1, diam2);
	
		ll sum = 0;
		for(int i=0; i<n; ++i)
		{
			int j = upper_bound(dist21, dist21 + q, diam - dist11[i] - 1 - 1) - dist21;
			sum += diam*j + cum[q-1] - ((j > 0) ? cum[j-1] : 0) + (dist11[i] + 1)*((ll)q-(ll)j);
		}

		printf("%.3lf\n", (double)sum/(double)(n*q));
	}

	return 0;
}
