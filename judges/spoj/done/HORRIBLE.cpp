/*
Segment Tree - Lazy Propagation
Calculate sum of intervals in O(logn) - Can be converted to Range Minimum Query, Range Maximum Query, etc.

Tested with: spoj.com/HORRIBLE
*/

#include<cstdio>
#include<cstring>
using namespace std;

typedef long long unsigned ll;
#define MAX 100005

ll tree[4*MAX], lazy[4*MAX];
int size; //number of elements in array
bool changed[4*MAX];

void init()
{
	memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));
	memset(changed, 0, sizeof(changed));
}

//build is the same for the version without lazy propagation

//change according with required operation
inline void updateNode(int node, int start, int end, ll value)
{
	tree[node] += value * (end - start + 1);
}

inline void propagate(int node, ll value)
{
	int nodeLeft = 2*node, nodeRight = 2*node + 1;
	changed[nodeLeft] = changed[nodeRight] = 1;
	lazy[nodeLeft] += value;
	lazy[nodeRight] += value;
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

ll query(int node, int start, int end, int left, int right);

//add "value" to all elements in interval [left, right]
//O(logn)
void update(int node, int start, int end, int left, int right, ll value)
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

	tree[node] = tree[nodeLeft] + tree[nodeRight];
}

//O(logn)
ll query(int node, int start, int end, int left, int right)
{
	updateLazy(node, start, end);
	
	if(left > end || right < start) return 0; //-INF: Minimum Query, INF: Maximum Query

	if(left <= start && right >= end) return tree[node];
	
	int mid = (start + end)/2, nodeLeft = 2*node, nodeRight = 2*node + 1;

	ll ret1 = query(nodeLeft, start, mid, left, right);
	ll ret2 = query(nodeRight, mid+1, end, left, right);
	return ret1 + ret2; //min(s1, s2); //If the problem is Range Minimum Query
}

ll query(int left, int right)
{
	return query(1, 1, size, left, right);
}

void update(int left, int right, ll value)
{
	update(1, 1, size, left, right, value);
}

int main()
{
	int t, q, op;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &size, &q);
		init();
		while(q--)
		{
			int l, r;
			ll v;
			scanf("%d", &op);
			if(!op)
			{
				scanf("%d %d %lld", &l, &r, &v);
				update(l, r, v);
			}
			else
			{
				scanf("%d %d", &l, &r);
				printf("%lld\n", query(l, r));
			}
		}
	}
	
	return 0;
}
