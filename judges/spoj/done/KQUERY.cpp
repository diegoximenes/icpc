#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 30000+10
#define MAXQ 200000+10
#define mp make_pair

int size;
int tree[4*MAX];

struct E
{
	int k, l, r, i;

	E(int k=0, int l=0, int r=0, int i=0) : k(k), l(l), r(r), i(i) {}
	bool operator<(E e) const
	{
		if(k == e.k)
		{
			if(l == e.l)
			{
				if(r == e.r)
					return (i < e.i);
				else
					return (r < e.r);
			}
			else 
				return (l < e.l);
		}
		else
			return (k < e.k);
	}
};

void update(int node, int begin, int end, int pos)
{
	if(begin == end)
		tree[node] = 1;
	else
	{
		int mid = (begin+end)/2;
		if(pos <= mid)
			update(2*node, begin, mid, pos);
		else
			update(2*node+1, mid+1, end, pos);
		tree[node] = tree[2*node] + tree[2*node+1];
	}
}

int query(int node, int begin, int end, int left, int right)
{
	if((begin >= left) && (end <= right))
		return tree[node];
	else
	{
		int mid = (begin+end)/2, res = 0;
		if((mid >= left) && (begin <= right))
			res += query(2*node, begin, mid, left, right);
		if((end >= left) && (mid+1 <= right))
			res += query(2*node+1, mid+1, end, left, right);
		return res;
	}
}

void update(int pos)
{
	update(1, 1, size, pos);
}

int query(int left, int right)
{
	return query(1, 1, size, left, right);
}

int main()
{
	int n, q, ans[MAXQ];
	vector<E> v;
	E e;
 	
	scanf("%d", &n);
	memset(tree, 0, sizeof(tree));	
	size = n;
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &e.k);
		e.l = e.r = 0;
		e.i = i;
		e.k = -e.k;
		v.push_back(e);
	}
	scanf("%d", &q);
	for(int i=0; i<q; ++i)
	{
		scanf("%d %d %d", &e.l, &e.r, &e.k);
		e.l = -e.l;
		e.i = i;
		e.k = -e.k;
		v.push_back(e);
	}
	
	sort(v.begin(), v.end());
	for(int i=0; i<(int)v.size(); ++i)
	{
		if(v[i].l == 0)
			update(v[i].i);
		else
			ans[v[i].i] = query(-v[i].l, v[i].r);
	}

	for(int i=0; i<q; ++i)
		printf("%d\n", ans[i]);


	return 0;
}
