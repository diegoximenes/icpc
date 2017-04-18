#include<cstdio>
#include<cstring>
#include<list>
#include<set>
using namespace std;

#define mp make_pair
#define pb push_back
#define MAX 1000010

list<int> next[MAX];
bool full[MAX];
int time[MAX], out[MAX];

int main()
{
	int t, n, m;

	scanf("%d", &t);
	while(t--)
	{
		set< pair<int, int> > tree;
		bool can = 1;
		int cntOut = 0;

		scanf("%d %d", &n, &m);
		for(int i=0; i<=n; ++i)
		{
			full[i] = 1;
			next[i].clear();
		}

		for(int i=0; i<m; ++i)
		{
			scanf("%d", &time[i]);
			
			if(time[i])
			{
				if(next[time[i]].empty()) tree.insert(mp(i, time[i]));
				next[time[i]].pb(i);
			}
		}

		for(int i=0; can && i<m; ++i)
		{
			if(time[i] == 0)
			{
				set< pair<int,int> >::iterator it = tree.upper_bound(mp(i, -1));		
				if(it == tree.end()) out[cntOut++] = 0;
				else
				{
					pair<int, int> p = *it;
					
					full[p.second] = 0;
					out[cntOut++] = p.second;
					next[p.second].erase(next[p.second].begin());
					tree.erase(p);
				}
			}
			else
			{
				if(full[time[i]]) can = 0;
				else
				{
					full[time[i]] = 1;
					if(!next[time[i]].empty()) tree.insert(mp(*next[time[i]].begin(), time[i]));
				}
			}
		}

		if(can)
		{
			puts("YES");
			printf("%d", out[0]);
			for(int i=1; i<cntOut; ++i) printf(" %d", out[i]);
			puts("");
		}
		else puts("NO");
	}

	return 0;
}
