#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;

#define MAX 256 + 10
#define INF (int) 1e9
#define pb push_back

int n, m;

inline int toInd(int i, int j)
{
	return i*m + j;
}

int main()
{
	int dist[MAX], ind, minDist[MAX], lastLine;
	bool mark[MAX];
	vector<int> g[MAX];

	scanf("%d %d", &n, &m);
	lastLine = (int)ceil((double)n/double(m)) - 1;
	for(int k=0; k<n-1; ++k)
	{
		int i = k/m, j = k%m; 
		g[k].pb(k+1); g[k+1].pb(k);
		
		ind = toInd(i+1, j);
		if(ind < n)
		{
			g[k].pb(ind); g[ind].pb(k);
		}
	}
	g[0].pb(n-1); g[n-1].pb(0);
	
	int minTotalDist = INF;
	for(int i=0; i<n; ++i)
	{
		memset(mark, 0, sizeof(mark));
		queue<int> q;
		q.push(i);
		dist[i] = 0;
		mark[i] = 1;
		while(!q.empty())
		{
			int v = q.front(); q.pop();
			for(int j=0; j<(int)g[v].size(); ++j)
			{
				int u = g[v][j];
				if(!mark[u])
				{
					q.push(u);
					mark[u] = 1;
					dist[u] = dist[v] + 1;
				}
			}
		}

		int totalDist = 0;
		for(int j=0; j<n; ++j)
			totalDist += dist[j];
		if(totalDist < minTotalDist)
		{
			minTotalDist = totalDist;
			memcpy(minDist, dist, sizeof(minDist));
		}
	}
	
	printf("Mean = %.2lf\n", (double)minTotalDist/(double)n);
	for(int i=0; i<=lastLine; ++i, puts(""))
	{
		printf("%d", minDist[toInd(i, 0)]);
		for(int j=1; j<m; ++j)
		{
			if(toInd(i, j) == n) { puts(""); return 0; }
			printf(" %d", minDist[toInd(i, j)]);
		}
	}

	return 0;
}

