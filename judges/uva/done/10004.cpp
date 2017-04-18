#include<cstdio>
#include<cstring>
#include<vector>
#include<list>
#include<queue>
using namespace std;

int main()
{
	int marc[210], flag, n, e, v1, v2;
	vector< list<int> >g;
	list<int> l;
	list<int>::iterator it;
	g.assign(210, l);
	queue<int> f;
	
	while(1)
	{
		scanf("%d %d", &n, &e);
		if(!n)
			break;
		
		memset(marc, 0, (n+1)*sizeof(int));
		g.assign(n+1, l);
		
		while(e--)
		{
			scanf("%d %d", &v1, &v2);
			
			g[v1].push_front(v2);
			g[v2].push_front(v1);
		}
		
		v1 = 0;
		marc[v1] = 1;
		f.push(v1);
		
		flag = 0;
		
		while(!f.empty() && !flag)
		{
			v1 = f.front();
			f.pop();
			
			for(it=g[v1].begin(); it!=g[v1].end(); ++it)
			{
				if(!marc[*it])
				{
					if(marc[v1] == 1)
						marc[*it] = 2;
					else
						marc[*it] = 1;
					
					f.push(*it);
				}
				else if(marc[*it] == marc[v1])
				{
					flag = 1;
					break;
				}
				
			}
		}
		
		if(!flag)
			puts("BICOLORABLE.");
		else
			puts("NOT BICOLORABLE.");
	}
	
	return 0;
}