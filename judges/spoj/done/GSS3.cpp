#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 50000+100

typedef struct T
{
	//ls = sum of prefix, rs = sum of suffix, sum = total sum, mx = max subvector sum
	long long sum, ls, rs, mx;
	
	void operator=(const T & b)
	{
		sum = b.sum; ls = b.ls; rs = b.rs; mx = b.mx;
	}
}T;

int size;
T tree[3*MAX];

void build(int node, int begin, int end, T *v)
{
	if(begin == end)
		tree[node] = v[begin];
	else
	{
		int mid = (begin+end)/2;
		build(2*node, begin, mid, v);
		build(2*node+1, mid+1, end, v);
		tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
		tree[node].ls = max(tree[2*node].ls, tree[2*node].sum + tree[2*node+1].ls);
		tree[node].rs = max(tree[2*node+1].rs, tree[2*node+1].sum + tree[2*node].rs);
		tree[node].mx = max(max(tree[2*node].mx, tree[2*node+1].mx), tree[2*node].rs + tree[2*node+1].ls);
	}
}

T query(int node, int begin, int end, int left, int right)
{
	if((begin >= left) && (end <= right))
		return tree[node];
	
	int mid = (begin+end)/2;
	if(right <= mid)
		return query(2*node, begin, mid, left, right);
	if(left > mid)
		return query(2*node+1, mid+1, end, left, right);
	
	T p1, p2, p3;
	p1 = query(2*node, begin, mid, left, right);
	p2 = query(2*node+1, mid+1, end, left, right);
 
	p3.sum = p1.sum + p2.sum;
	p3.ls = max(p1.ls , p1.sum + p2.ls);
	p3.rs = max (p2.rs, p2.sum + p1.rs);
	p3.mx = max(max(p1.mx, p2.mx), p1.rs + p2.ls);
	return p3;
}

void update(int node, int begin, int end, int pos, T value)
{
	if(begin == end)
		tree[node] = value;
	else
	{
		int mid = (begin+end)/2;
		if(pos <= mid)
			update(2*node, begin, mid, pos, value);
		else
			update(2*node+1, mid+1, end, pos, value);
		tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
		tree[node].ls = max(tree[2*node].ls, tree[2*node].sum + tree[2*node+1].ls);
		tree[node].rs = max(tree[2*node+1].rs, tree[2*node+1].sum + tree[2*node].rs);
		tree[node].mx = max(max(tree[2*node].mx, tree[2*node+1].mx), tree[2*node].rs + tree[2*node+1].ls);
	}
}

void construct(int n, T *v)
{
	size = n;
	build(1, 1, size, v);
}

T query(int left, int right)
{
	return query(1, 1, size, left, right);
}

void update(int pos, T value)
{
	update(1, 1, size, pos, value);
}

int main()
{
	T v[MAX];
	int q, n;
	
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%lld", &v[i].sum);
		v[i].ls = v[i].rs = v[i].mx = v[i].sum;
	}
	construct(n, v);
	
	scanf("%d", &q);
	while(q--)
	{
		int op, l, r;
		scanf("%d %d %d", &op, &l, &r);
		if(op)
			printf("%lld\n", query(l, r).mx);
		else
		{
			T val;
			val.sum = val.ls = val.rs = val.mx = r;
			update(l, val);
		}
	}
	
	return 0;
}

