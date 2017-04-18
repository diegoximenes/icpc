#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 1010
#define mp make_pair
#define pb push_back

int set[MAX], n, m;
vector< pair< pair<int, int>, pair<int, int> > > edges;
vector<int> upper;

inline void init(int n)
{
	for(int i=0; i<n; ++i) set[i] = i;
}

int find(int i)
{
	return (set[i] == i) ? i : set[i] = find(set[i]);
}

bool sameSet(int i, int j)
{
	return find(i) == find(j);
}

inline void unionSet(int i, int j)
{
	if(sameSet(i, j)) return;
	set[find(j)] = find(i);
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
	{
		int u, v, l, r;
		scanf("%d %d %d %d", &u, &v, &l, &r);
		--u; --v;
		upper.pb(r);
		edges.pb(mp(mp(l, r), mp(u, v)));
	}
	sort(upper.begin(), upper.end());
	sort(edges.begin(), edges.end());
	
	int sol = -1;
	for(int i=0; i<m; ++i)
	{
		init(n);
		for(int j=0; j<m; ++j)
		{
			if(upper[i] <= edges[j].first.second && upper[i] >= edges[j].first.first)
				unionSet(edges[j].second.first, edges[j].second.second);
			if(sameSet(0, n-1))
			{
				sol = max(upper[i] - edges[j].first.first + 1, sol);
				break;
			}
		}
	}

	if(sol == -1) puts("Nice work, Dima!");
	else printf("%d\n", sol);
	return 0;
}
