#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 105

int main()
{
	int g, p, cor[MAX][MAX], s, clas[MAX], pt[MAX], k;
	
	while(scanf("%d %d", &g, &p) && g)
	{
		for(int i=0; i<g; ++i)
			for(int j=0; j<p; ++j)
				scanf("%d", &cor[i][j]);
		scanf("%d", &s);
		while(s--)
		{
			scanf("%d", &k);
			memset(pt, 0, sizeof(pt));
			for(int i=0; i<k; ++i)
				scanf("%d", &pt[i]);
			
			memset(clas, 0, sizeof(clas));
			for(int i=0; i<g; ++i)
				for(int j=0; j<p; ++j)
					clas[j] += pt[cor[i][j] - 1];
			
			int ptmax = -1;
			for(int i=0; i<p; ++i)
				ptmax = max(ptmax, clas[i]);
			bool flag = 0;
			for(int i=0; i<p; ++i)
				if(clas[i] == ptmax)
				{
					if(!flag)
					{
						printf("%d", i+1);
						flag = 1;
					}
					else
						printf(" %d", i+1);
				}
			puts("");
		}
		
	}
	
	return 0;
}