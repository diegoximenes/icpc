//dijkstra

#include<cstdio>
#include<vector>
#include<set>
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
	int n, m, s, t, v, u, w;
	char type[50];
	vector< pair<int, int> > g[MAX];
	
	scanf("%d %d", &n, &m);
	s = n*3; t = n*3+1;
	g[s].push_back(mp(0, 0));
	g[(n-1)*3 + LIC].push_back(mp(t, 0));
	g[(n-1)*3 + PIR].push_back(mp(t, 0));
	g[(n-1)*3 + CRA].push_back(mp(t, 0));
	while(m--)
	{
		scanf("%d %d %d %s", &v, &u, &w, type);
		--v; --u;
		if(type[0] == 'L')
			g[v*3 + LIC].push_back(mp(u*3 + LIC, w));
		else if(type[0] == 'P') 
		{
			g[v*3 + LIC].push_back(mp(u*3 + PIR, w));
			g[v*3 + PIR].push_back(mp(u*3 + PIR, w));
			g[v*3 + CRA].push_back(mp(u*3 + PIR, w));
		}
		else
		{
			g[v*3 + PIR].push_back(mp(u*3 + CRA, w));
			g[v*3 + CRA].push_back(mp(u*3 + CRA, w));
			g[v*3 + LIC].push_back(mp(u*3 + LIC, w));
		}
	}
	
	set< pair<long long int, int> > heap;
	long long int dist[MAX];
	bool mark[MAX];
	for(int i=0; i<=3*n+1; ++i)
	{
		mark[i] = 0; dist[i] = INF;
	}
	dist[s] = 0;
	heap.insert(mp(dist[s], s));
	while(!heap.empty())
	{
		v = heap.begin()->second;
		mark[v] = 1;
		if(v == t)
			break;
		heap.erase(heap.begin());
		
		for(int i=0; i<(int)g[v].size(); ++i)
		{
			u = g[v][i].first; 
			long long int w1 = g[v][i].second;
			if(!mark[u] && dist[u] > dist[v] + w1)
			{
				heap.erase(mp(dist[u], u));
				dist[u] = dist[v] + w1;
				heap.insert(mp(dist[u], u));
			}
		}
	}
	
	if(!mark[t])
		puts("Offline");
	else
		cout << "Online" << endl << dist[t] << endl;
	
	return 0;
}