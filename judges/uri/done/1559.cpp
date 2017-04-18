#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9

int main()
{
	int n = 4, t, g[10][10];	
	
	scanf("%d", &t);
	while(t--)
	{
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				scanf("%d", &g[i][j]);

		bool right = 0, left = 0, down = 0, up = 0, found2048 = 0;
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
			{
				if(g[i][j] == 0) continue;
				
				if(g[i][j] == 2048) found2048 = 1;

				//right
				if(j+1<n && (g[i][j+1] == 0 || g[i][j+1] == g[i][j])) right = 1;

				//left
				if(j-1>=0 && (g[i][j-1] == 0 || g[i][j-1] == g[i][j])) left = 1;

				//down
				if(i+1<n && (g[i+1][j] == 0 || g[i+1][j] == g[i][j])) down = 1;

				//up
				if(i-1>=0 && (g[i-1][j] == 0 || g[i-1][j] == g[i][j])) up = 1;

			}

		if((!left && !right && !up && !down) || found2048) printf("NONE");
		else
		{
			bool space = 0;
		
			if(down) printf("DOWN"), space = 1;
			
			if(left)
			{
				if(space) putchar(' ');
				printf("LEFT");
				space = 1;
			}
			
			if(right)
			{
				if(space) putchar(' ');
				printf("RIGHT");
				space = 1;
			}
			
			if(up)
			{
				if(space) putchar(' ');
				printf("UP");
				space = 1;
			}
		}
	
		puts("");
	}				

	return 0;
}
