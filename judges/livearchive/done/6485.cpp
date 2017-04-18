#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
using namespace std;

#define INF 1e9
#define mp make_pair
#define pb push_back
#define MAX 505
const int maxFuel = 480;

struct Node
{
	int u, fuel, w, start, end;
	Node(int u=0, int fuel = 0, int w = 0, int start = 0, int end = 0) : u(u), fuel(fuel), w(w), start(start), end(end) {}
};

vector<Node> g[MAX][MAX];
int dist[MAX][MAX];
bool mark[MAX][MAX];
int n, m;

int main()
{
	while(scanf("%d %d", &n, &m) && n)
	{
		for(int i=0; i<n; ++i)
			for(int j=0; j<=maxFuel; ++j)
				g[i][j].clear(), dist[i][j] = INF, mark[i][j] = 0;
		
		while(m--)
		{
			int u, v, start, end, w;
			scanf("%d %d", &u, &v);
			while(1)
			{	
				scanf("%d %d %d", &start, &end, &w);
				for(int fuel=1; fuel<=maxFuel; ++fuel)
					if(fuel >= 2*w)
					{
						g[u][fuel].pb(Node(v, fuel - 2*w, w, start, end));
						g[v][fuel].pb(Node(u, fuel - 2*w, w, start, end));
					}

				if(end == 1439) break;
			}
		}
		
		set< pair<int, pair<int, int> > > heap;
		dist[0][480] = 720; // 12*60
		heap.insert(mp(dist[0][480], mp(0, 480)));
		int sol;
		while(!heap.empty())
		{
			sol = heap.begin()->first;
			pair<int, int> p = heap.begin()->second;
			int u = p.first, fuel = p.second;
			
			heap.erase(heap.begin());
			mark[u][fuel] = 1;
			if(u == n-1) break;

			if(fuel+1 <= maxFuel && !mark[u][fuel+1] && dist[u][fuel+1] > dist[u][fuel] + 1)
			{
				heap.erase(mp(dist[u][fuel+1], mp(u, fuel+1)));
				dist[u][fuel+1] = dist[u][fuel] + 1;
				heap.insert(mp(dist[u][fuel+1], mp(u, fuel+1)));
			}

			for(int i=0; i<(int)g[u][fuel].size(); ++i)
			{
				int v = g[u][fuel][i].u, w = g[u][fuel][i].w, newFuel = fuel - 2*w;
				int start = g[u][fuel][i].start, end = g[u][fuel][i].end;
				
				int actualTime = dist[u][fuel]%(24*60), deltaTime;
				if(actualTime >= start && actualTime <= end) deltaTime = 0;
				else if(actualTime < start) deltaTime = start - actualTime;
				else deltaTime = 24*60 - actualTime + start; //actualTime > end
				
				if(!mark[v][newFuel] && dist[v][newFuel] > dist[u][fuel] + w + deltaTime)
				{
					heap.erase(mp(dist[v][newFuel], mp(v, newFuel)));
					dist[v][newFuel] = dist[u][fuel] + w + deltaTime;
					heap.insert(mp(dist[v][newFuel], mp(v, newFuel)));
				}
			}
		}
		
		printf("%d\n", sol - 720);
	}

	return 0;
}
