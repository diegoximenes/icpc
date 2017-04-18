#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

#define MAX 55
#define MAXV 4000*26+100
#define pb push_back
#define mp make_pair
#define INF (int) 1e9
#define MAXL 26

int main()
{
	int n, v, s, t, u, nv, len, e, dw, nt, ns;
	int dist[MAXV];
	bool mark[MAXV];
	char s1[MAX], s2[MAX], w[MAX];
	map<string, int> dic;
	vector< pair<int, int> > g[MAXV];
	set< pair<int, int> > heap;

	while(scanf("%d", &n) && n)
	{
		scanf("%s %s", s1, s2);
		dic.clear();
		s = 0; t = 1;
		dic[s1] = s; dic[s2] = t;
		nv = 2;

		for(int i=0; i<n; ++i)
		{
			scanf("%s %s %s", s1, s2, w);
			if(dic.find(s1) == dic.end())
				dic[s1] = nv++;
			if(dic.find(s2) == dic.end())
				dic[s2] = nv++;
			
			u = dic[s1]*MAXL; v = dic[s2]*MAXL;
			dw = w[0] - 'a';
			len = strlen(w);
			for(int i=0; i<MAXL; ++i)
				if(i != dw)
				{
					g[u + dw].pb(mp(v + i, len)); 
					g[v + dw].pb(mp(u + i, len));
				}
		}

		t = t*MAXL; s = s*MAXL;
		nt = nv*MAXL; ns = nt + 1;
		for(int i=0; i<MAXL; ++i)
		{
			g[t + i].pb(mp(nt, 0));
			g[ns].pb(mp(s + i, 0));
		}
		s = ns; t = nt;	
		
		heap.clear();
		for(int i=0; i<=ns; ++i)
		{
			dist[i] = INF;
			mark[i] = 0;
		}
		heap.insert(mp(0, s));
		dist[s] = 0;
		while(!heap.empty())
		{
			v = heap.begin()->second;
			mark[v] = 1;
			if(v == t)	break;
			heap.erase(heap.begin());

			for(int i=0; i<(int)g[v].size(); ++i)
			{
				u = g[v][i].first; e = g[v][i].second;
				if(!mark[u] && dist[u] > dist[v] + e)
				{
					heap.erase(mp(dist[u], u));
					dist[u] = dist[v] + e;
					heap.insert(mp(dist[u], u));
				}
			}
		}

		if(!mark[t]) puts("impossivel");
		else printf("%d\n", dist[t]);

		for(int i=0; i<nv*MAXL; ++i)
			g[i].clear();
	}
		
	return 0;
}
