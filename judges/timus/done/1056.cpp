#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define pb push_back
#define INF 1e9
#define MAX 10005

bool mark[MAX];
int n, dad[MAX], dist[MAX];
vector<int> g[MAX];

void bfs(int s)
{
	queue<int> q;
	for(int i=0; i<n; ++i) dist[i] = INF, mark[i] = 0;
	mark[s] = 1; dist[s] = 0; q.push(s); dad[s] = -1;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int v = g[u][i];
			if(!mark[v]) mark[v] = 1, dist[v] = dist[u] + 1, dad[v] = u, q.push(v);
		}
	}
}

int farNode()
{
	int maxdist = -1, maxdistu = -1;
	for(int i=0; i<n; ++i)
		if(dist[i] > maxdist)
			maxdist = dist[i], maxdistu = i;
	return maxdistu;
}

int main()
{
	int u;

	scanf("%d", &n);
	for(int i=1; i<n; ++i)
	{
		scanf("%d", &u);
		g[u-1].pb(i); g[i].pb(u-1);
	}
	
	vector<int> out;

	bfs(0);
	u = farNode();
	bfs(u);
	int ufar = farNode();
	int minDist = INF;
	for(int v = ufar; v != -1; v = dad[v]) minDist = min(minDist, max(dist[v], dist[ufar] - dist[v]));
	for(int v = ufar; v != -1; v = dad[v])
		if(max(dist[v], dist[ufar] - dist[v]) == minDist)
			out.pb(v+1);
	
	//printf("mindist= %d, u= %d, ufar= %d\n", minDist, u, ufar);

	sort(out.begin(), out.end());
	printf("%d", out[0]);
	if(out.size() > 1) printf(" %d", out[1]);
	puts("");

	return 0;
}
