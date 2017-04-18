#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
using namespace std;

#define INF (int) 1e9
#define MAX 6000*('z'-'a'+1)+100
#define NL 'z'-'a'+1

int main()
{
	int n, nv, s, t, u, v, dist[MAX], w;
	bool mark[MAX];
	char s1[60], s2[60], word[60];
	vector< vector< pair<int, int> > > g;
	map<string, int> dic;
	set< pair<int, int> > heap;
	vector< pair<int, int> > ve;
	
	g.assign(MAX, ve);
	ve.clear();
	nv = 0;

	while(scanf("%d", &n) && n)
	{
		dic.clear();
		
		for(int i=0; i<nv; ++i)
			g[i] = ve;
		
		scanf("%s %s", s1, s2);
		dic[s1] = 2;
		dic[s2] = 2+NL;
		nv = 2+2*NL;
		for(int i=0; i<NL; ++i)
		{
			g[0].push_back(make_pair(2+i, 0));
			g[2+NL+i].push_back(make_pair(1, 0));
		}
		
		while(n--)
		{
			scanf("%s %s %s", s1, s2, word);

			if(dic.find(s1) == dic.end())
				dic[s1] = nv; nv += NL;
			if(dic.find(s2) == dic.end())
				dic[s2] = nv; nv += NL;
			
			v = dic[s1];
			u = dic[s2];
			w = strlen(word);
			for(int i=0; i<NL; ++i)
				if(i != word[0]-'a')
				{
					g[v + word[0]-'a'].push_back(make_pair(u+i, w));
					g[u + word[0]-'a'].push_back(make_pair(v+i, w));	
				}
		}
		
		heap.clear();
		for(int i=0; i<nv; ++i)
			dist[i] = INF;
		memset(mark, 0, nv*sizeof(bool));
		s = 0; t = 1;
		dist[s] = 0;
		heap.insert(make_pair(dist[s], s));
		while(!heap.empty())
		{
			v = (heap.begin())->second;
			heap.erase(heap.begin());
			mark[v] = 1;
			if(v == t)
				break;
				
			for(int i=0; i<(int)g[v].size(); ++i)
			{
				u = g[v][i].first; w = g[v][i].second;
				if(!mark[u] && dist[u] > dist[v] + w)
				{
					heap.erase(make_pair(dist[u], u));
					dist[u] = dist[v] + w;
					heap.insert(make_pair(dist[u], u));
				}
			}
		}
		
		if(!mark[t])
			puts("impossivel");
		else
			printf("%d\n", dist[t]);
	}
	
	return 0;
}