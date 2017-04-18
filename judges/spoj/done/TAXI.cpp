#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define mp make_pair
#define pb push_back

#define MAX 610
#define INF (int)1e9
#define NIL 0

vector<int> g[MAX];
int match[MAX], dist[MAX], n, m;
//n == number of vertices in the left side, m == number of vertices in the right side

bool bfs()
{	
	int i, u, v, len;
	queue<int> q;
	for(i=1; i<=n; ++i)
	{
		if(match[i] == NIL)
		{
			dist[i] = 0;
			q.push(i);
		}
		else dist[i] = INF;
	}

	dist[NIL] = INF;
	while(!q.empty())
	{
		u = q.front(); q.pop();
		if(u != NIL)
		{
			len = g[u].size();
			for(i=0; i<len; ++i)
			{
				v = g[u][i];
				if(dist[match[v]] == INF)
				{
					dist[match[v]] = dist[u] + 1;
					q.push(match[v]);
				}
			}
		}
	}
	return (dist[NIL] != INF);
}

bool dfs(int u)
{
	int i, v, len;
	if(u != NIL)
	{
		len = g[u].size();
		for(i=0; i<len; ++i)
		{
			v = g[u][i];
			if(dist[match[v]] == dist[u] + 1)
			{
				if(dfs(match[v]))
				{
					match[v] = u;
					match[u] = v;
					return 1;
				}
			}
		}
		dist[u] = INF;
		return 0;
	}
	return 1;
}

int hopcroftKarp()
{
	int matching = 0, i;
	for(int i=0; i<=n+m; ++i) match[i] = NIL;
	while(bfs())
		for(i=1; i<=n; ++i)
			if(match[i] == NIL && dfs(i))
				++matching;
	return matching;
}

int main()
{
	int tc, t, p, x, y;
	double vel, time;
	vector< pair<int, int> > taxi, person;

	n = 0;
	scanf("%d", &tc);
	for(int i=0; i<tc; ++i)
	{
		person.clear(); taxi.clear();
		for(int j=0; j<=n; ++j) g[j].clear();

		scanf("%d %d %lf %lf", &p, &t, &vel, &time);
		for(int j=0; j<p; ++j)
		{
			scanf("%d %d", &x, &y);
			person.pb(mp(x, y));
		}
		for(int j=0; j<t; ++j)
		{
			scanf("%d %d", &x, &y);
			taxi.pb(mp(x, y));
		}
		
		n = taxi.size(); m = person.size();
		for(int j=0; j<(int)taxi.size(); ++j)
		{
			int indt = j + 1;

			for(int k=0; k<(int)person.size(); ++k)
			{
				double distance = 200.0*(abs(person[k].first - taxi[j].first) + abs(person[k].second - taxi[j].second));
				if(distance/vel <= time)
				{
					int indp = taxi.size() + k + 1;
					g[indt].pb(indp);
				}
			}
		}
		
		printf("%d\n", hopcroftKarp());
	}

	return 0;
}

