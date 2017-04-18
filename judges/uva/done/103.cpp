#include<cstdio>
#include<cstring>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int m[35][15], gent[35];
vector< list<int> > g;

int main()
{
	int k, n, dist[35], dad[35];
	stack<int> s;
	queue<int> f;
	list<int> l, topord;
	list<int>::iterator it, it2;
	
	l.clear();
	g.resize(35);
	
	while(scanf("%d %d", &k, &n) != EOF)
	{
		for(int i=0; i<k; ++i)
			for(int j=0; j<n; ++j)
				scanf("%d", &m[i][j]);
		
		g.assign(k, l);
		memset(gent, 0, k*sizeof(int));
		for(int i=0; i<k; ++i)
			sort(m[i], m[i] + n);
				
		for(int i=0; i<k; ++i)
			for(int j=0; j<k; ++j)
				if(i != j)
				{
					int flag = 0;
					for(int l=0; l<n; ++l)
						if(m[j][l] <= m[i][l])
						{
							flag = 1;
							break;
						}
						
					if(!flag)
					{
						g[i].push_front(j);
						++gent[j];
					}
				}
		
		for(int i=0; i<k; ++i)
			if(!gent[i])
				f.push(i);
		
		topord.clear();	
			
		while(!f.empty())
		{
			int i = f.front();
			f.pop();
			
			topord.push_back(i);
			
			for(it=g[i].begin(); it!=g[i].end(); ++it)
			{
				--gent[*it];
				
				if(!gent[*it])
					f.push(*it);
			}
		}
		
		memset(dist, 0, k*sizeof(int));
		for(int i=0; i<k; ++i)
			dad[i] = i;
		
		for(it=topord.begin(); it!=topord.end(); ++it)
			for(it2=g[*it].begin(); it2!=g[*it].end(); ++it2)
			{
				if(dist[*it2] < dist[*it] + 1)
				{
					++dist[*it2];
					
					dad[*it2] = *it;
				}
			}
		
		int maxdist = -1, imax;
		for(int i=0; i<k; ++i)
			if(dist[i] > maxdist)
			{
				maxdist = dist[i];
				imax = i;
			}
		
		printf("%d\n", maxdist+1);
		
		s.push(imax+1);
		while(dad[imax] != imax)
		{
			imax = dad[imax];
			s.push(imax+1);
		}
		printf("%d", s.top());
		s.pop();
		while(!s.empty())
		{
			printf(" %d", s.top());
			s.pop();
		}
		puts("");
	}
	
	return 0;
}