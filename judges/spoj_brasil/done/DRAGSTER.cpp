#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

#define MAX 305
#define mp make_pair
#define pb push_back

double p[MAX][MAX];
vector< pair<int, double> > prob[2*MAX];

void inline calc(int u, int v, int x)
{
	for(int i=0; i<(int)prob[u].size(); ++i)
	{
		double pu = 0.0;
		for(int j=0; j<(int)prob[v].size(); ++j)
			pu += p[prob[u][i].first][prob[v][j].first]*prob[v][j].second;
		prob[x].pb(mp(prob[u][i].first, pu*prob[u][i].second));
	}
}

int main()
{
	int n, u, v, deg[2*MAX], last, count;
	vector<int> gdown[2*MAX];
	int gup[2*MAX];
	queue<int> q;

	while(scanf("%d", &n) && n)
	{
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
				scanf("%lf", &p[i][j]);
			prob[i].pb(mp(i, 1.0));
		}
		for(int i=n; i<=2*n-2; ++i)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			deg[i] = 0;
			gdown[i].pb(u); gdown[i].pb(v);
			gup[u] = i; gup[v]  = i;
			if(u >= n) ++deg[i];
			if(v >= n) ++deg[i];

			if(!deg[i]) q.push(i);
		}
		
		count = 0;
		while(!q.empty())
		{
			++count;
			int x = q.front(); q.pop();
			u = gdown[x][0]; v = gdown[x][1];
			
			if(count != n-1)
			{
				--deg[gup[x]];
				if(!deg[gup[x]]) q.push(gup[x]);
			}
			
			calc(u, v, x);
			calc(v, u, x);
			
			last = x;
		}
		
		for(int i=0; i<(int)prob[last].size(); ++i)
			if(prob[last][i].first == 0)
			{
				printf("%.6lf\n", prob[last][i].second);
				break;
			}

		for(int i=0; i<2*n; ++i)
		{
			gdown[i].clear();
			prob[i].clear();
		}
	}

	return 0;
}
