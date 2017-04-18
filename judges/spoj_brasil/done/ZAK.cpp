#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

#define MAX 1010
#define INF (int) 3e9

typedef struct
{
	int mana, dano;
}Magia;

vector< Magia > magia; 
int m, pd[MAX][MAX];

int opt(int i, int v)
{
	if(v <= 0)
		return 0;
	if(i == m)
		return INF;
	if(pd[i][v] != -1)
		return pd[i][v];
	return pd[i][v] = min(opt(i+1, v), magia[i].mana + opt(i, v - magia[i].dano));
}

int main()
{
	vector< vector<int> > g;
	vector< vector<int> > monstro;
	int n, gal, k, mana, dano, u, v, vida, dist[MAX], w;
	bool mark[MAX];
	vector<int> ve;
	set< pair<int, int> > heap;
	Magia ma;
	
	ve.clear();
	
	while(scanf("%d %d %d %d", &m, &n, &gal, &k))
	{
		if(!m && !n && !gal && !k)
			break;
		
		g.assign(n, ve);
		monstro.assign(n, ve);
		magia.assign(m, ma);
		for(int i=0; i<m; ++i)
			for(int j=0; j<MAX; ++j)
				pd[i][j] = -1;
		
		for(int i=0; i<m; ++i)
		{
			scanf("%d %d", &mana, &dano);
			magia[i].mana = mana;
			magia[i].dano = dano;
		}
		while(gal--)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		while(k--)
		{
			scanf("%d %d", &u, &vida);
			--u;
			monstro[u].push_back(vida);
		}
		
		int s=0, t=n-1;
		memset(mark, 0, n*sizeof(bool));
		for(int i=0; i<n; ++i)
			dist[i] = INF;
		w = 0;
		for(int j=0; j<(int)monstro[s].size(); ++j)
			w += opt(0, monstro[s][j]);
		dist[s] = w;
		heap.clear();
		heap.insert(make_pair(dist[s], s));
		while(!heap.empty())
		{
			v = (heap.begin())->second;
			heap.erase(heap.begin());
			mark[v] = 1;
			if(v == t)
				break;
			
			for(int i=0; i<(int)g[v].size(); ++i)
			{
				u = g[v][i];
				w = 0;
				for(int j=0; j<(int)monstro[u].size(); ++j)
					w += opt(0, monstro[u][j]);
				
				if(!mark[u] && dist[u] > dist[v] + w)
				{
					heap.erase(make_pair(dist[u], u));
					dist[u] = dist[v] + w;
					heap.insert(make_pair(dist[u], u));
				}
			}
		}
		
		if(!mark[t])
			puts("-1");
		else
			printf("%d\n", dist[t]);
	}
	
	return 0;
}
