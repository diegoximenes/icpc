#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 2010
#define INF 1e9

int n, c, t1, t2, pnt[MAX], dp[MAX], next[MAX][2];

int opt(int first, int i)
{
	if(i == -1 || i == 2*n || i >= first + n) return 0;

	int &state = dp[i];
	if(state != - 1) return state;

	return state = min(t1 + opt(first, next[i][0]), t2 + opt(first, next[i][1]));
}

int main()
{
	while(scanf("%d %d %d %d", &n, &c, &t1, &t2) == 4)
	{
		for(int i=0; i<n; ++i) scanf("%d", &pnt[i]);
		for(int i=n; i<2*n; ++i) pnt[i] = c + pnt[i-n];

		for(int i=0; i<2*n; ++i)
		{
			bool solved1 = 0, solved2 = 0;
			next[i][0] = next[i][1] = -1;
			for(int j=i+1; j<2*n; ++j)
			{
				int diff = pnt[j] - pnt[i];
				
				if(!solved1 && diff > t1) next[i][0] = j, solved1 = 1;
				if(!solved2 && diff > t2) next[i][1] = j, solved2 = 1;

				if(solved1 && solved2) break;
			}
		}
		
		int sol = INF;
		for(int i=0; i<n; ++i)
		{
			memset(dp, -1, sizeof(dp));
			sol = min(sol, opt(i, i));
		}
		printf("%d\n", sol);
	}

	return 0;
}
