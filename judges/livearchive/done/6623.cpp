#include<cstdio>
#include<vector>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 455

bool g[MAX][MAX];
int weight[MAX];

int main()
{
	int n, m;

	while(scanf("%d %d", &n, &m) == 2)
	{
		for(int i=0; i<n; ++i) scanf("%d", &weight[i]);
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
				g[i][j] = 0;
		
		vector< pair<int, vector<int> > > clique2;
		vector< pair<int, vector<int> > > clique3;

		int sol = 0;
		while(m--)
		{
			int u, v, w;
			scanf("%d %d", &u, &v);
			--u; --v;
			g[u][v] = g[v][u] = 1;

			w = weight[u] + weight[v];
			sol = max(sol, w);

			vector<int> aux; aux.pb(u); aux.pb(v);
			clique2.pb(mp(w, aux));
		}

		for(int i=0; i<(int)clique2.size(); ++i)
		{
			int u = clique2[i].second[0];
			int v = clique2[i].second[1];
			int w = clique2[i].first;

			for(int j=0; j<n; ++j)
				if(g[u][j] && g[v][j])
				{
					int nw = w + weight[j];
					sol = max(sol, nw);

					vector<int> aux = clique2[i].second; aux.pb(j);
					clique3.pb(mp(nw, aux));
				}
		}

		for(int i=0; i<(int)clique3.size(); ++i)
		{
			int u = clique3[i].second[0];
			int v = clique3[i].second[1];
			int x = clique3[i].second[2];
			int w = clique3[i].first;

			for(int j=0; j<n; ++j)
				if(g[u][j] && g[v][j] && g[x][j])
				{
					int nw = w + weight[j];
					sol = max(sol, nw);
				}
		}

		printf("%d\n", sol);
	}

	return 0;
}
