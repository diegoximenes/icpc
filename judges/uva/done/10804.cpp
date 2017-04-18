#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define MAX 110
#define INF 0x3f3f3f3f
#define NIL 0

vector<int> g[MAX];
int match[MAX], dist[MAX], nLeft, nRight;

pair<double, double> nodeLeft[MAX], nodeRight[MAX];

bool bfs()
{	
	int i, u, v;
	queue<int> q;
	
	for(i=1; i<=nLeft; ++i)
	{
		if(match[i] == NIL) dist[i] = 0, q.push(i);
		else dist[i] = INF;
	}

	dist[NIL] = INF;
	while(!q.empty())
	{
		u = q.front(); q.pop();
		if(u != NIL)
		{
			for(i=0; i<(int)g[u].size(); ++i)
			{
				v = g[u][i];
				if(dist[match[v]] == INF)
				{
					dist[match[v]] = dist[u] + 1;
					q.push(match[v]);
				}
			}
		}
	}
	
	return (dist[NIL] != INF);
}

bool dfs(int u)
{
	int i, v;
	
	if(u != NIL)
	{
		for(i=0; i<(int)g[u].size(); ++i)
		{
			v = g[u][i];
			if(dist[match[v]] == dist[u] + 1 && dfs(match[v]))
			{
				match[v] = u; match[u] = v;
				return 1;
			}
		}
		
		dist[u] = INF;
		return 0;
	}
	
	return 1;
}

int hopcroftKarp()
{
	int matching = 0, i;
	for(int i=0; i<=nLeft+nRight; ++i) match[i] = NIL;
	while(bfs())
		for(i=1; i<=nLeft; ++i)
			if(match[i] == NIL && dfs(i))
				++matching;
	return matching;
}

inline int idRight(int u) { return nLeft + u; }

inline double mydist(int i, int j) { return hypot(nodeLeft[i].first - nodeRight[j].first, nodeLeft[i].second - nodeRight[j].second); }

int main()
{
	int t, k;

	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf("%d %d %d", &nLeft, &nRight, &k);
		
		for(int i=1; i<=nLeft; ++i) scanf("%lf %lf", &nodeLeft[i].first, &nodeLeft[i].second);
		for(int i=1; i<=nRight; ++i) scanf("%lf %lf", &nodeRight[i].first, &nodeRight[i].second);
		
		vector<double> possibleDistances;
		for(int i=1; i<=nLeft; ++i)
			for(int j=1; j<=nRight; ++j)
				possibleDistances.pb(mydist(i, j));
		
		double sol = -1;
		possibleDistances.pb(0);
		sort(possibleDistances.begin(), possibleDistances.end());
		int l = 0, r = possibleDistances.size()-1;
		while(l <= r)
		{
			int mid = (l + r)/2;

			for(int i=0; i<=nLeft; ++i) g[i].clear();
			
			for(int i=1; i<=nLeft; ++i)
				for(int j=1; j<=nRight; ++j)
					if(mydist(i, j) <= possibleDistances[mid])
						g[i].pb(idRight(j));
			
			if(hopcroftKarp() >= nLeft-k) sol = possibleDistances[mid], r = mid-1;
			else l = mid+1;
		}
		
		printf("Case #%d:\n", tc);
		if(nLeft == 0) puts("0.000");
		else if(sol < 0) puts("Too bad.");
		else printf("%.3lf\n", sol);
		puts("");
	}
	
	return 0;
}

