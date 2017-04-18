#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
using namespace std;

#define pb push_back
#define mp make_pair
#define INF (int) 1e9

int g[5][5], sol[5], localSol[5], comb[5];
bool mark[25];

inline pair<int, int> toPair(int i)
{
	return mp(i/5, i%5);
}

int main()
{
	int t, g[5][5], x, y, p, n, dist[5][5], sol[5], localSol[5];

	scanf("%d", &t);
	while(t--)
	{
		memset(g, 0, sizeof(g));
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d %d %d", &x, &y, &p);
			g[x][y] = p;
		}
		
		int cost = INF;	
		for(int a=0; a<25; ++a)
			for(int b=a+1; b<25; ++b)
				for(int c=b+1; c<25; ++c)
					for(int d=c+1; d<25; ++d)
						for(int e=d+1; e<25; ++e)
						{
							localSol[0] = a; localSol[1] = b; localSol[2] = c; localSol[3] = d; localSol[4] = d; localSol[4] = e;

							for(int j=0; j<5; ++j)
								for(int k=0; k<5; ++k)
									dist[j][k] = INF;

							
							for(int j=0; j<5; ++j)
							{
								pair<int, int> p = toPair(localSol[j]);
								dist[p.first][p.second] = 0;
								for(int k=0; k<5; ++k)
									for(int l=0; l<5; ++l)
										dist[k][l] = min(dist[k][l], g[k][l]*(abs(p.first - k) + abs(p.second - l)));
							}
							
							int localCost = 0;
							for(int j=0; j<5; ++j)
								for(int k=0; k<5; ++k)
									localCost += dist[j][k];
							if(localCost < cost)
							{
								cost = localCost;
								for(int j=0; j<5; ++j) sol[j] = localSol[j];
							}
						}

		printf("%d", sol[0]);
		for(int j=1; j<5; ++j) printf(" %d", sol[j]);
		puts("");
	}

	return 0;
}
