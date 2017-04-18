#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

#define MAX 205
#define INF 1e9
#define pb push_back
#define mp make_pair

inline double dista(pair< pair<int, int>, int > u, pair< pair<int, int>, int > v)
{
	return sqrt(pow(u.first.first - v.first.first, 2) + pow(u.first.second - v.first.second, 2) + pow((u.second - v.second)*5, 2));
}

int main()
{
	int n, m, q, u, v, f, dad[MAX][MAX]; 
	double dist[MAX][MAX];
	pair< pair<int, int>, int > pnt[MAX];
	char op[20];
	bool blank = 0;
	
	while(scanf("%d %d", &n, &m) == 2)
	{
		if(blank) puts("");

		for(int i=0; i<n; ++i) scanf("%d %d %d", &f, &u, &v), pnt[i] = mp(mp(u, v), f);

		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
			{
				if(i == j) dist[i][i] = 0;
				else dist[i][j] = INF;
				dad[i][j] = i;
			}

		while(m--)
		{
			scanf("%d %d %s", &u, &v, op);
			if(strcmp(op, "walking") == 0 || strcmp(op, "stairs") == 0) dist[u][v] = dist[v][u] = dista(pnt[u], pnt[v]);
			else if(strcmp(op, "lift") == 0) dist[u][v] = dist[v][u] = 1;
			else
			{
				double d = dista(pnt[u], pnt[v]);
				dist[u][v] = 1;
				dist[v][u] = d*3;
			}
		}

		for(int k=0; k<n; ++k)
			for(int i=0; i<n; ++i)
				for(int j=0; j<n; ++j)
					if(dist[i][j] > dist[i][k] + dist[k][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						dad[i][j] = dad[k][j];
					}
		
		scanf("%d", &q);
		while(q--)
		{
			scanf("%d %d", &u, &v);
			vector<int> path;
			while(1)
			{
				path.pb(v);
				v = dad[u][v];
				if(v == path.back()) break;
			}
			
			printf("%d", path.back());
			for(int i=path.size()-2; i>=0; --i) printf(" %d", path[i]);
			puts("");
		}

		blank = 1;
	}

	return 0;
}
