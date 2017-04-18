/*
Stoer-Wagner
O(n*m + (n**2)*logn)
*/

#include<cstdio>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 155

int g[MAX][MAX], n; //n is the number vertexes, g is the graph matrix
//stoer-wagned variables
int w[MAX];
bool a[MAX], merged[MAX];

int stoerWagner()
{
	int best = INT_MAX;
	memset(merged, 0, sizeof(merged));
	merged[0] = 1;

	for(int phase=1; phase<n; ++phase)
	{
		a[0] = 1;
		for(int i=1; i<n; ++i)
		{
			if(merged[i]) continue;
			a[i] = 0;
			w[i] = g[0][i];
		}

		int prev = 0, next;

		for(int i=n-1-phase; i>=0; --i)
		{
			//find next vertex which is not in a
			next = -1;
			for(int j=1; j<n; ++j)
				if(!a[j] && (next == -1 || w[j] > w[next]))
					next = j;
			
			a[next] = 1;
			
			if(i > 0)
			{
				prev = next;
				//update weights
				for(int j=1; j<n; ++j)
					if(!a[j])
						w[j] += g[next][j];
			}
		}
		
		best = min(best, w[next]);

		//merge s and t
		for(int i=0; i<n; ++i)
		{
			g[i][prev] += g[next][i];
			g[prev][i] += g[next][i];
		}
		
		merged[next] = 1;
	}

	return best;
}

int main()
{
	int t, m, u, v, cap;

	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		memset(g, 0, sizeof(g));
		scanf("%d %d", &n, &m);
		while(m--)
		{
			scanf("%d %d %d", &u, &v, &cap);
			--v; --u;
			g[u][v] = g[v][u] = cap;
		}

		printf("Case #%d: %d\n", tc, stoerWagner());
	}

	return 0;
}

