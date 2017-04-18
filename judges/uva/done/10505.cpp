#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MAX 210

int main()
{
	int t, n, p, v, mark[MAX], u;
	vector< vector<int> > g;
	vector<int> ve;
	
	ve.clear();
	g.resize(MAX);
	
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d", &n);
		
		g.assign(n, ve);
		
		for(v=0; v<n; ++v)
		{
			scanf("%d", &p);
			
			for(int i=0; i<p; ++i)
			{
				scanf("%d", &u);
				--u;
				
				g[v].push_back(u);
				g[u].push_back(v);
			}
		}
		
		int count = 0;
		memset(mark, 0, n*sizeof(int));
		for(int i=0; i<n; ++i)
		{
			queue<int> f;
			int count1 = 0, count2 = 0;
			bool flag = 0;
			
			if(!mark[i])
			{
				f.push(i);
				mark[i] = 1;
			}
			
			while(!f.empty())
			{
				v = f.front();
				f.pop();
				
				if(mark[v] == 1)
					++count1;
				else
					++count2;
				
				for(int j=0; j<(int)g[v].size(); ++j)
				{
					u = g[v][j];
					
					if(!mark[u])
					{
						if(mark[v] == 1)
							mark[u] = 2;
						else
							mark[u] = 1;
						
						f.push(u);
					}
					else if(mark[u] == mark[v])
						flag = 1;
				}
			}
			
			if(!flag)
				count += max(count1, count2);
		}
		
		printf("%d\n", count);
	}
	
	return 0;
}