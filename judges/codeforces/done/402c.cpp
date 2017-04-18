#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define INF 1e9
#define MAX 25

int main()
{
	int t, n, p;
	bool g[MAX][MAX];
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &p);
		set< pair<int, int> > tree;
		set< pair<int, int> >::iterator it, it2;
		
		memset(g, 0, sizeof(g));
		for(int i=0; i<n; ++i) tree.insert(mp(0, i));
		
		vector< pair<int, int> > out;
		int upper = 2*n + p;
		for(int i=0; i<upper; ++i)
		{
			bool solved = 0;
			for(it=tree.begin(); !solved && it!=tree.end(); ++it)
			{
				it2 = it; ++it2;
				for(; !solved && it2!=tree.end(); ++it2)
					if(!g[it->second][it2->second])
					{
						int u = it->second, v = it2->second, degu = it->first, degv = it2->first;
						g[u][v] = g[v][u] = 1;
						solved = 1;
						
						tree.erase(it); tree.erase(it2);
						tree.insert(mp(degu+1, u)); tree.insert(mp(degv+1, v));
						out.pb(mp(u, v));
					}
			}
		}

		for(int i=0; i<(int)out.size(); ++i) printf("%d %d\n", out[i].first+1, out[i].second+1);
	}


	return 0;
}
