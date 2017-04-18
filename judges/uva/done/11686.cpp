#include<cstdio>
#include<cstring>
#include<vector>
#include<list>
#include<queue>
using namespace std;

int main()
{
	int n, m, a, b, v;
	vector< list<int> > g;
	vector<int> gentrada;
	list<int> l;
	list<int>::iterator it;
	queue<int> f, f2;
	
	while(1)
	{
		scanf("%d %d", &n, &m);
		
		if(!n && !m)
			break;
		
		l.clear();
		g.assign(n+1, l);
		gentrada.assign(n+1, 0);
		
		while(m--)
		{
			scanf("%d %d", &a, &b);
			
			g[a].push_front(b);
			
			++gentrada[b];
		}
		
		for(v=1; v<=n; ++v)
			if(gentrada[v] == 0)
				f.push(v);
		
			while(!f.empty())
			{
				v = f.front();
				f.pop();
				
				f2.push(v);
				
				for(it=g[v].begin(); it!=g[v].end(); ++it)
				{
					--gentrada[*it];
					
					if(gentrada[*it] == 0)
						f.push(*it);
				}
			}
			
			if(f2.size() != n)
				puts("IMPOSSIBLE");
			else
			{
				while(!f2.empty())
				{
					v = f2.front();
					f2.pop();
					
					printf("%d\n", v);
				}
			}
				
	}
	
	return 0;
}