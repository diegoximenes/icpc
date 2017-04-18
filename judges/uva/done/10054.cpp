/*
Euler Tour

Description: Given an undirected graph find a path that starts in a vertex and finish in the same vertex passing over all edges only once
O(n + m)
*/

#include<cstdio>
#include<algorithm>
#include<list>
#include<queue>
#include<cstring>
#include<queue>
using namespace std;

#define MAX 60
#define pb push_back 
#define mp make_pair 

vector< pair<int, bool> > g[MAX]; 
int n; //n == number of vertexes

//used for find cycle
list<int> cycle;
bool mark[MAX];
int deg[MAX];

bool connected(int s)
{
	int count = 0;
	queue<int> q;
	
	memset(mark, 0, sizeof(mark));
	q.push(s); mark[s] = 1;
	while(!q.empty())
	{
		int v = q.front(); q.pop();
		++count;
		for(int i=0; i<(int)g[v].size(); ++i)
		{
			int u = g[v][i].first;
			if(!mark[u])
			{
				mark[u] = 1;
				q.push(u);
			}
		}
	}
	
	return (count == n);
}

bool eulerian(int s)
{
	if(!connected(s)) return 0;
	//for(int i=0; i<n; ++i)
	for(int i=0; i<MAX; ++i) //for based on the problem conditions. In general use the commented for
		if(deg[i]%2 != 0)
			return 0;
	return 1;
}

void eulerTour(list<int>::iterator it, int v)
{
	for(int i=0; i<(int)g[v].size(); ++i)
	{
		pair<int, int> u = g[v][i];
		if(u.second)
		{
			g[v][i].second = 0;
			for(int j=0; j<(int)g[u.first].size(); ++j)
			{
				pair<int, int> uu = g[u.first][j];
				if(uu.first == v && uu.second)
				{
					g[u.first][j].second = 0;
					break;
				}
			}
			eulerTour(cycle.insert(it, v), u.first);
		}
	}
}


//cycle start in vertex s
bool findCycle(int s)
{
	if(!eulerian(s)) return 0;
	
	cycle.clear();
	eulerTour(cycle.begin(), s);

	//print cycle
	for(list<int>::iterator it = cycle.begin(); ; ++it)
	{
		list<int>::iterator it2 = ++it; --it;
		if(it2 == cycle.end()) 
		{
			printf("%d %d\n", *it + 1, *cycle.begin() + 1);
			break;
		}
		printf("%d %d\n", *it + 1, *it2 + 1);
	}

	return 1;
}

int main()
{
	int u, v, t, m, s;
	bool color[MAX];

	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		//clear
		memset(deg, 0, sizeof(deg));
		memset(color, 0, sizeof(color)); //problem stuff
		//for(int i=0; i<n; ++i) g[i].clear();
		for(int i=0; i<MAX; ++i) g[i].clear(); //In general case use the commented for
		n = 0;
		
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d %d", &u, &v);
			--u; --v;
			g[u].pb(mp(v, 1)); g[v].pb(mp(u, 1));
			++deg[u]; ++deg[v];
			
			//problem stuff
			s = u;
			if(!color[v]) color[v] = 1, ++n;
			if(!color[u]) color[u] = 1, ++n;
		}
				
		printf("Case #%d\n", tc);
		if(!findCycle(s)) puts("some beads may be lost");
		if(tc < t) puts("");
	}

	return 0;
}
