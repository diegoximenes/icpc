//topological sort

#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

#define mp make_pair
#define INF 1e16
#define MAX 30005
#define LIC 0
#define PIR 1
#define CRA 2

int main()
{
	int n, m, s, t, v, u, w, degree[MAX];
	long long int dist[MAX];
	char type[50];
	vector< pair<int, int> > g[MAX];
	
	scanf("%d %d", &n, &m);
	s = n*3; t = n*3+1;
	for(int i=0; i<=3*n+1; ++i)
	{
		dist[i] = INF;
		degree[i] = 0;
	}
	dist[s] = 0; degree[s] = 0;
	g[s].push_back(mp(0, 0)); ++degree[0];
	g[(n-1)*3 + LIC].push_back(mp(t, 0));
	g[(n-1)*3 + PIR].push_back(mp(t, 0));
	g[(n-1)*3 + CRA].push_back(mp(t, 0));
	degree[t] += 3;
	
	while(m--)
	{
		scanf("%d %d %d %s", &v, &u, &w, type);
		--v; --u;
		if(type[0] == 'L')
		{
			g[v*3 + LIC].push_back(mp(u*3 + LIC, w));
			++degree[u*3 + LIC];
		}
		else if(type[0] == 'P') 
		{
			g[v*3 + LIC].push_back(mp(u*3 + PIR, w)); 
			g[v*3 + PIR].push_back(mp(u*3 + PIR, w));
			g[v*3 + CRA].push_back(mp(u*3 + PIR, w));
			degree[u*3 + PIR] += 3;
		}
		else
		{
			g[v*3 + PIR].push_back(mp(u*3 + CRA, w)); ++degree[u*3 + CRA];
			g[v*3 + CRA].push_back(mp(u*3 + CRA, w)); ++degree[u*3 + CRA];
			g[v*3 + LIC].push_back(mp(u*3 + LIC, w)); ++degree[u*3 + LIC];
		}
	}
	
	queue<int> q;
	for(int i=0; i<=3*n+1; ++i)
		if(!degree[i])
			q.push(i);
	while(!q.empty())
	{
		v = q.front(); q.pop();
		
		for(int i=0; i<(int)g[v].size(); ++i)
		{
			u = g[v][i].first; w = g[v][i].second;
			
			--degree[u];
			if(!degree[u])
				q.push(u);
			
			if(dist[v] != INF)
				dist[u] = min(dist[u], dist[v] + w);
		}
	}
	
	if(dist[t] == INF)
		puts("Offline");
	else
		cout << "Online" << endl << dist[t] << endl;
	
	return 0;
}