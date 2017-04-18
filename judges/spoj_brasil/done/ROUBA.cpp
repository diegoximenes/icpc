#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

#define MAXJ 22
#define MAXN 10010

typedef struct
{
	int count, topo;
}Monte;

int main()
{
	int n, j, i, e, descarte[MAXN];
	queue<int> compra;
	Monte monte[MAXJ];
	
	while(scanf("%d %d", &n, &j) && n && j)
	{
		memset(descarte, 0, sizeof(descarte));
		for(i=0; i<j; ++i)
		{
			monte[i].count = 0;
			monte[i].topo = -1;
		}
		for(i=0; i<n; ++i)
		{
			scanf("%d", &e);
			compra.push(e);
		}
		
		i = 0;
		while(!compra.empty())
		{
			//printf("%d\n", i);
			int vez = compra.front(); compra.pop();
			
			if(descarte[vez])
			{
				--descarte[vez];
				monte[i].count += 2;
				monte[i].topo = vez;
				continue;
			}
			
			bool flag = 0;
			for(int k=0; k<j; ++k)
			{
				if((k != i) && (monte[k].topo == vez))
				{
					monte[i].count += monte[k].count+1;
					monte[k].count = 0;
					monte[i].topo = vez;
					monte[k].topo = -1;
						
					flag = 1;
				}
			}		
			if(flag)
				continue;
			
			if(monte[i].topo == vez)
			{
				++monte[i].count;
				continue;
			}
		
			++descarte[vez];
			++i; i%=j;
		}
		
		int maxi = -1;
		for(i=0; i<j; ++i)
			maxi = max(maxi, monte[i].count);
		printf("%d", maxi);
		for(i=0; i<j; ++i)
			if(monte[i].count == maxi)
				printf(" %d", i+1);
		puts("");
	}
	
	return 0;
}