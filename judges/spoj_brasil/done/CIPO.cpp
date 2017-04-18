#include<cstdio>
#include<vector>
using namespace std;

#define MAX 1010
#define pb push_back
#define mp make_pair

int set[MAX];

inline int id(int w)
{
	if(w == 1235) return 0;
	if(w == 8977) return 1;
	return 2;
}

inline int weight(int i)
{
	if(i == 0) return 1235;
	if(i == 1) return 8977;
	return 10923;
}

void initSet(int n)
{
	for(int i=0; i<n; ++i)
		set[i] = i;
}

int findSet(int i)
{
	return (set[i] == i) ? i : (set[i] = findSet(set[i]));
}

bool isSameSet(int i, int j)
{
	return findSet(i) == findSet(j);
}

void unionSet(int i, int j)
{
	set[findSet(i)] = findSet(j);
}

int main()
{
	int n, m, u, v, w, mstcost;
	vector< pair<int, int> > edges[3];

	for(int tc=1; scanf("%d %d", &n, &m) == 2; ++tc)
	{
		for(int i=0; i<3; ++i) edges[i].clear();
		for(int i=0; i<m; ++i)
		{
			scanf("%d %d %d", &u, &v, &w);
			--u; --v;
			edges[id(w)].pb(mp(u, v));
		}
		
		mstcost = 0;
		initSet(n);
		for(int i=0; i<3; ++i)
			for(int j=0; j<(int)edges[i].size(); ++j)
			{
				u = edges[i][j].first; v = edges[i][j].second;
				if(!isSameSet(u, v))
				{
					mstcost += weight(i);
					unionSet(u, v);
				}
			}
		
		printf("Instancia %d\n%d\n\n", tc, mstcost);
	}

	return 0;
}
