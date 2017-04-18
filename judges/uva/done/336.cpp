#include<cstdio>
#include<cstring>
#include<vector>
#include<list>
#include<queue>
#include<map>
using namespace std;

int main()
{
	int n, i, v, vini, ttl, nivel[35], p=1, a, b, count, nv, v1, v2;
	bool marc[35];
	vector< list<int> > g;
	list<int> l;
	list<int>::iterator it;
	map<int, int> dic;
	
	l.clear();
	
	while(1)
	{
		scanf("%d", &n);
		if(!n)
			break;
		
		dic.clear();
		
		l.clear();
		g.assign(35, l);
		
		nv = 0;
		for(i=0; i<n; ++i)
		{
			scanf("%d %d", &a, &b);
			
			if(dic.find(a) != dic.end())
				v1 = dic[a];
			else
			{
				dic[a] = nv;
				v1 = nv;
				++nv;
			}
			
			if(dic.find(b) != dic.end())
				v2 = dic[b];
			else
			{
				dic[b] = nv;
				v2 = nv;
				++nv;
			}
			
			g[v1].push_back(v2);
			g[v2].push_back(v1);
		}
		
		for(; ; ++p)
		{
			scanf("%d %d", &vini, &ttl);
			if(!vini && !ttl)
				break;
			
			queue<int> f;
			
			memset(marc, 0, 35*sizeof(bool));
			memset(nivel, 0, 35*sizeof(int));
			
			v = dic[vini];
			//printf("v = %d\n", v);
			f.push(v);
			marc[v] = 1;
			nivel[v] = 0;
			
			count = -1;
			
			while(!f.empty())
			{
				v = f.front();
				f.pop();
				
				++count;
				
				if(nivel[v] < ttl)
				{
					for(it=g[v].begin(); it!=g[v].end(); ++it)
					{
						if(!marc[*it])
						{
							f.push(*it);
							marc[*it] = 1;
							
							nivel[*it] = nivel[v] + 1;
						}
					}
				}
			}
			//printf("nv= %d, count= %d\n", nv, count);
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", p, (nv-1)-count, vini, ttl);
		}
	}
	return 0;
}