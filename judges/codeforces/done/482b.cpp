#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<list>
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
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MAX 100010
#define allOne ((1 << 30) - 1)

int tree[4*MAX], lazy[4*MAX];
int size; 
bool changed[4*MAX];

void init()
{
	memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));
	memset(changed, 0, sizeof(changed));
}

inline void updateNode(int node, int start, int end, ull value){ tree[node] |= value; }

inline void propagate(int node, unsigned int value)
{
	int nodeLeft = 2*node, nodeRight = 2*node + 1;
	changed[nodeLeft] = changed[nodeRight] = 1;
	lazy[nodeLeft] |= value;
	lazy[nodeRight] |= value;
}

inline void updateLazy(int node, int start, int end)
{
	if(changed[node])
	{
		updateNode(node, start, end, lazy[node]);
		
		if(start != end) propagate(node, lazy[node]);

		lazy[node] = 0; changed[node] = 0;
	}
}

void update(int node, int start, int end, int left, int right, int value)
{
	updateLazy(node, start, end);

	if(left > end || right < start) return;
	if(start == end)
	{
		updateNode(node, start, end, value);
		return;
	}

	if(left <= start && right >= end)
	{
		propagate(node, value);	
		updateNode(node, start, end, value);
		return;
	}
 	
	int mid = (start+end)/2, nodeLeft = 2*node, nodeRight = 2*node + 1;
	
	update(nodeLeft, start, mid, left, right, value);
	update(nodeRight, mid+1, end, left, right, value);

	tree[node] = tree[nodeLeft] & tree[nodeRight];
}

int query(int node, int start, int end, int left, int right)
{
	updateLazy(node, start, end);
	
	if(left > end || right < start) return allOne;
	 
	if(left <= start && right >= end) return tree[node];
	
	int mid = (start + end)/2, nodeLeft = 2*node, nodeRight = 2*node + 1;

	int ret1 = query(nodeLeft, start, mid, left, right);
	int ret2 = query(nodeRight, mid+1, end, left, right);
	return (ret1 & ret2);
}

int query(int left, int right) { return query(1, 1, size, left, right); }
void update(int left, int right, int value) { update(1, 1, size, left, right, value); }

struct Query
{
	int l, r, q;
	Query(int _l=0, int _r=0, ull _q=0): l(_l), r(_r), q(_q) {}
};

int main()
{
	int n, m;
	vector<Query> inQuery;
		
	cin >> n >> m;	
	size = n; init();
	for(int i=0; i<m; ++i)
	{
		int l, r, q;
		cin >> l >> r >> q;
		inQuery.pb(Query(l, r, q));
		update(l, r, query(l, r) | q);
	}
	
	bool can = 1;
	for(int i=0; can && i<m; ++i)
		if(query(inQuery[i].l, inQuery[i].r) != inQuery[i].q) 
			can = 0;
	
	if(!can) cout << "NO" << endl;
	else
	{
		cout << "YES" << endl;
		cout << query(1, 1);
		for(int i=2; i<=n; ++i) cout << " " << query(i, i);
		cout << endl;
	}

	return 0;
}
