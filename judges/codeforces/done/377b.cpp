#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;

#define mp make_pair
#define INF (int) 1e9 + 100000
#define MAX 100010

int main()
{
	bool can = 0;
	int n, m, s, localOut[MAX], out[MAX];
	pair<int, int> bug[MAX];
	pair<pair<int, int>, int> student[MAX];

	scanf("%d %d %d", &n, &m, &s);
	for(int i=0; i<m; ++i) scanf("%d", &bug[i].first), bug[i].second = i;
	for(int i=0; i<n; ++i) scanf("%d", &student[i].first.first), student[i].second = i;
	for(int i=0; i<n; ++i) scanf("%d", &student[i].first.second);
	sort(bug, bug + m);

	int l = 1, r = m;
	while(l <= r)
	{
		int mid = (l + r)/2, passes = 0;
		
		set< pair< pair<int, int>, int> > tree;
		set< pair< pair<int, int>, int> >::iterator it, itaux;
		for(int i=0; i<n; ++i) tree.insert(student[i]);
		set< pair<int, int> > heap;
		set< pair<int, int> >::iterator itheap;
	
		int i = m - 1;
		bool localCan = 1;
		while(localCan && i >= 0)
		{
			it = tree.upper_bound(mp(mp(bug[i].first-1, INF), INF));
			itaux = it;
			for(; it!=tree.end(); ++it) heap.insert(mp(it->first.second, it->second));
			tree.erase(itaux, tree.end());
			
			if(heap.empty()) localCan = 0;
			else
			{
				pair<int, int> p = *heap.begin();
				heap.erase(heap.begin());

				passes += p.first;
				if(passes > s) localCan = 0;

				for(int j=0; j<mid && i>=0; ++j, --i) localOut[bug[i].second] = p.second;
			}
		}
		
		if(localCan)
		{
			can = 1;
			memcpy(out, localOut, sizeof(out));
			r = mid - 1;
		}
		else l = mid + 1;
	}
	
	if(!can) puts("NO");
	else
	{
		printf("YES\n%d", out[0] + 1);
		for(int i=1; i<m; ++i) printf(" %d", out[i] + 1);
		puts("");
	}

	return 0;
}
