#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define MAX 500005
#define INF 0x3f3f3f3f

enum {OPEN, QUERY, MID, CLOSE};

struct Event
{
	int x, type, id;
	Event(int x=0, int type=0, int id=0) : x(x), type(type), id(id) {}
	bool operator<(Event o) const
	{
		if(x != o.x) return (x < o.x);
		return (type < o.type);
	}
};

int beginId[MAX], endId[MAX], out[MAX];

int main()
{
	int t, n, q;

	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		vector<Event> event;

		scanf("%d %d", &n, &q);
		for(int i=0; i<n; ++i)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			event.pb(Event(l, OPEN, i));
			event.pb(Event((l+r)/2, MID, i));
			event.pb(Event(r, CLOSE, i));
			
			beginId[i] = l;
			endId[i] = r;
		}
		for(int i=0; i<q; ++i)
		{
			int x; scanf("%d", &x);
			event.pb(Event(x, QUERY, i));
		}

		sort(event.begin(), event.end());
		set< pair<int, int> > begin, end;
		for(int i=0; i<(int)event.size(); ++i)
		{
			if(event[i].type == OPEN)
			{
				//printf("OPEN id= %d, x= %d\n", event[i].id, event[i].x);
				
				begin.insert(mp(event[i].x, event[i].id));
			}
			else if(event[i].type == MID)
			{
				//printf("MID id= %d, x= %d\n", event[i].id, event[i].x);
				
				begin.erase(mp(beginId[event[i].id], event[i].id));
				end.insert(mp(-endId[event[i].id], event[i].id));
			}
			else if(event[i].type == CLOSE)
			{
				//printf("CLOSE id= %d, x= %d\n", event[i].id, event[i].x);
				
				end.erase(mp(-event[i].x, event[i].id));
			}
			else if(event[i].type == QUERY)
			{
				//printf("QUERY x= %d\n", event[i].x);

				int sol = 0;
				if(!begin.empty()) sol = max(sol, event[i].x - begin.begin()->first);
				if(!end.empty()) sol = max(sol, -end.begin()->first - event[i].x);
				
				out[event[i].id] = sol;	
			}
			
		}
		
		printf("Case %d:\n", tc);
		for(int i=0; i<q; ++i) printf("%d\n", out[i]);

	}

	return 0;
}
