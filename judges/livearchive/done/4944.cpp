#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 110
#define EPS 1e-9
#define pb push_back
#define mp make_pair

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	if(p1.second != p2.second) return p1.second > p2.second;
	return p1.first < p2.first;
}

int main()
{
	int p, n, t, vorig[MAX];
	vector< pair<int, int> > v;
	
	scanf("%d", &t);
	while(t--)
	{
		v.clear();
		scanf("%d %d", &p, &n);
		for(int i=0; i<n; ++i) 
		{
			int e;
			scanf("%d", &e);
			v.pb(mp(e, -i));
			vorig[i] = e;
		}
		
		bool can = 1;
		sort(v.begin(), v.end());
		while(p != 0 && can)
		{
			int unit = p/n;
			if(unit == 0) unit = 1;
			can = 0;
			for(int i=n-1; i>=0; --i)
				if(v[i].first != 0)
				{
					p -= min(unit, v[i].first);
					v[i].first -= min(unit, v[i].first);
					can = 1;
					if(p == 0) break;
				}
		}
		if(!can) puts("IMPOSSIBLE");
		else
		{
			sort(v.begin(), v.end(), cmp);
			printf("%d", vorig[0] - v[0].first);
			for(int i=1; i<n; ++i) printf(" %d", vorig[i] - v[i].first);
			puts("");
		}
	}

	return 0;
}
