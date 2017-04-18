#include<cstdio>
#include<climits>
#include<cstring>
#include<iostream>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

#define MAX 200

int main()
{
	int n, m, g[MAX][MAX], w, nv, v1, v2, dist[MAX], pai[MAX], vmax;
	bool marc[MAX];
	string s1, s2;
	map<string, int> dic;
	
	for(int p=1;; ++p)
	{
		scanf("%d %d", &n, &m);
		if(!n && !m)
			break;
		
		//printf("n= %d, m=%d\n", n, m);
		
		dic.clear();
		
		nv = 0;
		while(m--)
		{
			cin >> s1;
			cin >> s2;
			scanf("%d", &w);
			
			if(dic.find(s1) == dic.end())
			{
				dic[s1] = nv;
				++nv;
			}
			if(dic.find(s2) == dic.end())
			{
				dic[s2] = nv;
				++nv;
			}
			
			v1 = dic[s1];
			v2 = dic[s2];
			
			g[v1][v2] = g[v2][v1] = w;
		}
		
		cin >> s1;
		cin >> s2;
		v1 = dic[s1];
		v2 = dic[s2];
		
		//cout << "s1 = " << s1 << ", s2 = " << s2 << ", v1=" << v1 << ", v2 = "<< v2<< endl;
		
		for(int i=0; i<n; ++i)
		{
			dist[i] = -1;
			pai[i] = -1;
		}
		dist[v1] = 0;
		
		memset(marc, 0, n*sizeof(bool));
		
		set< pair<int, int> > heap;
		heap.clear();
		heap.insert(make_pair(0, v1));
		
		while(1)
		{
			if(heap.empty())
				break;
			
			vmax = (heap.begin())->second;
			
			if(vmax == v2)
				break;
			
			marc[vmax] = 1;
			
			heap.erase(heap.begin());
			
			for(int u=0; u<MAX; ++u)
			{
				if(!marc[u] && (dist[u] < g[u][vmax]))
				{
					heap.erase(make_pair(-dist[u], u));
					dist[u] = g[u][vmax];
					pai[u] = vmax;
					heap.insert(make_pair(-dist[u], u));
				}
			}
		}
		
		int gargalo = INT_MAX;
		int v = v2;
		
		while(v != v1)
		{
			gargalo = min(gargalo, g[pai[v]][v]);
			
			v = pai[v];
		}
		
		printf("Scenario #%d\n%d tons\n\n", p, gargalo);
	}
	
	return 0;
}