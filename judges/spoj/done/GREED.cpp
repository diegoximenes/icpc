#include<cstdio>
#include<cstring>
#include<limits>
#include<queue>
using namespace std;

#define pb push_back
#define INF 1e9
#define MAX 505

int n;
int cost[MAX][MAX];
int xy[MAX], yx[MAX];
int match_num;
int lx[MAX], ly[MAX];
bool s[MAX], t[MAX];
int prev[MAX];

int hungarian()
{
	memset(xy, -1, sizeof(xy));
	memset(yx, -1, sizeof(yx));
	memset(ly, 0, sizeof(ly));
	match_num = 0;
	int x, y;
	
	for(x=0; x<n; ++x)
	{
		lx[x] = cost[x][0];
		for(y=1; y<n; ++y) lx[x] = max(lx[x], cost[x][y]);
	}
	
	for(x=0; x<n; ++x)
		for(y=0; y<n; ++y)
			if((cost[x][y] == lx[x] + ly[y]) && (yx[y] == -1))
			{
				xy[x] = y;
				yx[y] = x;
				match_num++;
				break;
			}
	
	while(match_num < n)
	{
		memset(s, 0, sizeof(s));
		memset(t, 0, sizeof(t));
		memset(prev, -1, sizeof(prev));
		queue<int> q;
		for(x=0; x<n; ++x)
		{
			if(xy[x] == -1)
			{
				q.push(x);
				s[x] = 1;
				break;
			}
		}
		
		bool flg = 0;
		while(!q.empty() && !flg)
		{
			x = q.front();
			q.pop();
			for(y=0; y<n; ++y)
			{
				if(cost[x][y] == lx[x] + ly[y])
				{
					t[y] = 1;
					if(yx[y] == -1)
					{
						flg = 1;
						break;
					}
					if(!s[yx[y]])
					{
						s[yx[y]] = 1;
						q.push(yx[y]);
						prev[yx[y]] = x;
					}
				}
			}
		}

		if(flg)
		{
			int t1, t2;
			while(x != -1)
			{
				t1 = prev[x];
				t2 = xy[x];
				xy[x] = y;
				yx[y] = x;
				x = t1;
				y = t2;
			}
			match_num++;
		}
		else
		{
			int alpha = INF;
			for(x = 0; x<n; ++x)
				if(s[x])
					for(y=0; y<n; ++y)
						if(!t[y])
							alpha = min(alpha, lx[x] + ly[y] - cost[x][y]);
			for(x=0; x<n; ++x) if(s[x]) lx[x] -= alpha;
			for(y=0; y<n; ++y) if(t[y]) ly[y] += alpha;
		}
	}

	int ret = 0;
	for(x=0; x<n; ++x) ret += cost[x][xy[x]];
	return ret;
}


int cntCards[MAX], dist[MAX];
bool mark[MAX];
vector<int> gBfs[MAX];

void bfs(int s)
{
	dist[s] = 0; mark[s] = 1;
	queue<int> q; q.push(s);

	while(!q.empty())
	{
		int u = q.front(); q.pop();
		for(int i=0; i<(int)gBfs[u].size(); ++i)
		{
			int v = gBfs[u][i];
			if(!mark[v]) mark[v] = 1, dist[v] = dist[u] + 1, q.push(v);
		}
	}
}

int main()
{
	int tc, m, u, v;
	
	scanf("%d", &tc);
	while(tc--)
	{
		scanf("%d", &n);

		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j) cost[i][j] = 0, gBfs[i].clear();
			cntCards[i] = 0;
		}
		
		for(int i=0; i<n; ++i)
		{
			int x;
			scanf("%d", &x); --x;
			cntCards[x]++;
		}
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d %d", &u, &v); --u; --v;
			gBfs[u].pb(v); gBfs[v].pb(u);
		}
		
		int nv = 0;
		for(u=0; u<n; ++u)
		{
			for(v=0; v<n; ++v) dist[v] = INF, mark[v] = 0;
			bfs(u);
			
			for(; cntCards[u] > 0; --cntCards[u], ++nv)
				for(v=0; v<n; ++v) 
					cost[nv][v] = -dist[v];
		}
		
		printf("%d\n", -hungarian());
	}
}
