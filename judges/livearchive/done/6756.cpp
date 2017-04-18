#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

#define mp make_pair
#define pb push_back
#define NMAX 155
#define MMAX 3005
#define INF 0x3f3f3f3f

inline int next_int() 
{
	int n = 0;
	char c = getchar_unlocked();
	while (!('0' <= c && c <= '9')) c = getchar_unlocked();
	while ('0' <= c && c <= '9') 
	{
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return n;
}

int next[MMAX][2], last[NMAX];
pair<int, pair<int, int> > edge[MMAX];
int dist[NMAX][NMAX][NMAX];
int m, n;
bool mark[NMAX][NMAX][MMAX][2];

void calc(int s, int e, int i, int useEdge)
{
	if(e >= n) return;
	if(mark[s][e][i][useEdge]) return;
	mark[s][e][i][useEdge] = 1;
	
	int u = edge[i].second.first;
	int v = edge[i].second.second;
	if(useEdge)
	{
		int w = edge[i].first;
		dist[s][v][e] = min(dist[s][v][e], dist[s][u][e-1] + w);
	}
	
	if(useEdge && next[i][1] != -1) calc(s, e+1, next[i][1], 1), calc(s, e, next[i][1], 0);
	else if(!useEdge && next[i][0] != -1) calc(s, e+1, next[i][0], 1), calc(s, e, next[i][0], 0);
}	

int main()
{
	int t, q;

	//scanf("%d", &t);
	t = next_int();
	while(t--)
	{
		//scanf("%d %d %d", &n, &m, &q);
		n = next_int(); m = next_int(); q = next_int();
		for(int i=0; i<m; ++i)
		{
			int u, v, w;
			//scanf("%d %d %d", &u, &v, &w);
			u = next_int(); v = next_int(); w = next_int();
			--u; --v;
			edge[i] = mp(w, mp(u, v));
		}
		
		memset(dist, INF, sizeof(dist));
		for(int i=0; i<n; ++i) dist[i][i][0] = 0;
		memset(mark, 0, sizeof(mark));
		
		sort(edge, edge + m);
		memset(next, -1, sizeof(next));
		memset(last, -1, sizeof(last));

		for(int i=m-1; i>=0; --i)
		{
			int u = edge[i].second.first;
			int v = edge[i].second.second;
			next[i][0] = last[u];
			next[i][1] = last[v];
			last[u] = i;
		}

		for(int i=0; i<m; ++i) calc(edge[i].second.first, 1, i, 1);

		while(q--)
		{
			int u, v, e;
			//scanf("%d %d %d", &u, &v, &e);
			u = next_int(); v = next_int(); e = next_int();
			--u; --v;
			int sol = INF, upper = min(e, n-1);
			for(int i=0; i<=upper; ++i) sol = min(sol, dist[u][v][i]);

			if(sol == INF) puts("-1");
			else printf("%d\n", sol);
		}
	}

	return 0;
}
