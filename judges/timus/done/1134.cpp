#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 1005

bool mark[MAX][MAX];
int v[MAX];

int main()
{
	int n, m;

	scanf("%d %d", &n, &m);
	
	for(int i=0; i<m; ++i) scanf("%d", &v[i]);
	
	sort(v, v+m);
	memset(mark, 0, sizeof(mark));
	
	for(int i=0; i<m; ++i)
	{	
		if(v[i] > n)
		{
			puts("NO");
			return 0;
		}

		if(v[i] == 0)
		{
			if(mark[0][1])
			{
				puts("NO");
				return 0;
			}
			mark[0][1] = 1;
		}
		else if(v[i] == n)
		{
			if(mark[n-1][n])
			{
				puts("NO");
				return 0;
			}
			mark[n-1][n] = 1;
		}
		else
		{ 
			if(!mark[v[i]-1][v[i]]) mark[v[i]-1][v[i]] = 1;
			else if(!mark[v[i]][v[i]+1]) mark[v[i]][v[i]+1] = 1;
			else
			{
				puts("NO");
				return 0;
			}
		}
	}
	
	puts("YES");

	return 0;
}
