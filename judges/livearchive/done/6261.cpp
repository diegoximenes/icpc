#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define pb push_back
#define MAX 200005
#define INF 2e9

class Point
{
	public:
	int x, y, c;

	Point(int x=0, int y=0, int c=0) : x(x), y(y), c(c) {};

	bool operator<(Point o) const
	{
		if(y != o.y) return (y < o.y);
		if(x != o.x) return (x < o.x);
		return (c < o.c);
	}
};

int tree[MAX], ntree;
multiset<int> color[MAX], color2[MAX];
multiset<int>::iterator it, itr, itl;
map<int, int> dic;

inline int read(int idx)
{
	int sum = 0;
	while (idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

inline int read(int a, int b)
{
	return read(b) - read(a-1);
}

inline void update(int idx, int val)
{
	while(idx <= ntree)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

void init(int n)
{
	ntree = n;
	for(int i=0; i<=ntree; ++i) tree[i] = 0;
}

int main()
{
	int t, k, n;
	
	scanf("%d", &t);
	while(t--)
	{
		vector<Point> v;
		set<int> xaxis;
		int minx = INF, maxx = -1;
		
		scanf("%d %d", &n, &k);
		dic.clear();
		for(int i=1; i<=k; ++i) color[i].clear(), color2[i].clear();
		for(int i=0; i<n; ++i)
		{
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c);
			v.pb(Point(x, y, c));
			
			xaxis.insert(x);
		}

		for(it=xaxis.begin(); it!=xaxis.end(); ++it) dic[*it] = dic.size();
		minx = *xaxis.begin(); maxx = *xaxis.rbegin();
		dic[maxx + 1] = dic.size();	dic[minx - 1] = 0;		

		sort(v.begin(), v.end());
		init(n+1);
		
		vector<int> increase;
		int sol = 0, lasty = -1;
		for(int i=0; i<n; ++i)
		{	
			if(v[i].y != lasty)
			{
				for(int j=0; j<(int)increase.size(); ++j) update(dic[increase[j]], 1);
				increase.clear();
			}
			increase.pb(v[i].x);
			lasty = v[i].y;

			itr = color[v[i].c].lower_bound(v[i].x);
			itl = color2[v[i].c].lower_bound(-v[i].x);
			
			int r = maxx + 1;
			if(itr != color[v[i].c].end()) r = *itr;
			int l = minx - 1;
			if(itl != color2[v[i].c].end()) l = -*itl;
			
			sol = max(sol, read(dic[l] + 1, dic[r] - 1));
			
			//printf("i= %d, v[i]= (%d, %d, %d), l= %d, r= %d, sol= %d, dic[r]= %d, dic[l]= %d\n", i, v[i].x, v[i].y, v[i].c, l, r, sol, dic[r], dic[l]);

			color[v[i].c].insert(v[i].x);
			color2[v[i].c].insert(-v[i].x);
		}
		for(int j=0; j<(int)increase.size(); ++j) update(dic[increase[j]], 1);

		for(int i=1; i<=k; ++i)
		{
			for(it=color[i].begin(); it!=color[i].end(); ++it)
			{
				itr = ++it; it--;
				
				//printf("i= %d, *it= %d, *itr= %d\n", i, *it, *itr);

				int r = maxx + 1;
				if(itr != color[i].end()) r = *itr;

				sol = max(sol, read(dic[*it] + 1, dic[r] - 1));
				
				//printf("i= %d, l= %d, r= %d\n", i, *it, r);

				if(it == color[i].begin()) sol = max(sol, read(1, dic[*it] - 1));
			}
		}

		printf("%d\n", sol);
	}

	return 0;
}
