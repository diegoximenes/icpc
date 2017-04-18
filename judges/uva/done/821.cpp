#include<cstdio>
#include<cstring>
#include<vector>
#include<list>
#include<queue>
using namespace std;

int main()
{
	int a, b, paths, nivel[110], sum, nv, v2, v;
	vector< list<int> > g;
	bool existe[110], marc[110];
	list<int> l;
	list<int>::iterator it;
	queue<int> f;
	
	for(int p=1; ; ++p)
	{
		scanf("%d %d", &a, &b);
		if(!a && !b)
			break;
		
		l.clear();
		g.assign(110, l);
		memset(existe, 0, 110*sizeof(bool));
		nv = 0;
		
		g[a].push_front(b);
		existe[a] = existe[b] = 1;
		nv += 2;
		
		while(1)
		{
			scanf("%d %d", &a, &b);
			if(!a && !b)
				break;
			
			g[a].push_front(b);
			
			if(!existe[a])
			{
				++nv;
				existe[a] = 1;
			}
			if(!existe[b])
			{
				++nv;
				existe[b] = 1;
			}
		}
		
		sum = 0;
		for(v=1; v<=100; ++v)
		{
			memset(marc, 0, 110*sizeof(bool));
			memset(nivel, 0, 110*sizeof(int));
			
			if(existe[v])
			{
				f.push(v);
				marc[v] = 1;
				nivel[v] = 0;
				
				while(!f.empty())
				{
					v2 = f.front();
					f.pop();
					
					for(it=g[v2].begin(); it!=g[v2].end(); ++it)
					{
						if(!marc[*it])
						{
							marc[*it] = 1;
							f.push(*it);
							
							nivel[*it] = nivel[v2] + 1;
						}
					}
				}
				
				for(int k=1; k<=100; ++k)
					sum += nivel[k];
				
				//printf("v = %d, sum= %d\n", v, sum);
			}
		}
		
		paths = nv*(nv-1);
		if(paths)
			printf("Case %d: average length between pages = %.3lf clicks\n", p, (double)sum/(double)paths);
		else
			printf("Case %d: average length between pages = 0.000 clicks\n", p);
	}
	
	return 0;
}