#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 100000+100

struct T
{
	int lf, rf, mf, ln, rn;
	
	void operator=(const T & b)
	{
		lf = b.lf; rf = b.rf; mf = b.mf; ln = b.ln; rn = b.rn;
	}
};

int size;
T tree[3*MAX];

void build(int node, int begin, int end, T *v)
{
	if(begin == end)
		tree[node] = v[begin];
	else
	{
		int mid = (begin+end)/2, aux = 0;
		build(2*node, begin, mid, v);
		build(2*node+1, mid+1, end, v);

		tree[node].lf = tree[2*node].lf;
		tree[node].ln = tree[2*node].ln;
		tree[node].rf = tree[2*node+1].rf;
		tree[node].rn = tree[2*node+1].rn;
		if(tree[2*node].rn == tree[2*node+1].ln)
		{
			aux = tree[2*node].rf + tree[2*node+1].lf;
			
			if(tree[2*node].ln == tree[2*node].rn)
				tree[node].lf = aux;
			if(tree[2*node+1].ln == tree[2*node+1].rn)
				tree[node].rf = aux;
		}

		tree[node].mf = max(aux, max(max(tree[2*node].mf, tree[2*node+1].mf), max(tree[node].lf, tree[node].rf)));
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
	
	int aux = 0;
	T ql, qr, q;
	ql = query(2*node, begin, mid, left, right);
	qr = query(2*node+1, mid+1, end, left, right);

	q.lf = ql.lf;
	q.ln = ql.ln;
	q.rf = qr.rf;
	q.rn = qr.rn;
	if(ql.rn == qr.ln)
	{
		aux = ql.rf + qr.lf;
			
		if(ql.ln == ql.rn)
			q.lf = aux;
		if(qr.ln == qr.rn)
			q.rf = aux;
	}

	q.mf = max(aux, max(max(ql.mf, qr.mf), max(q.lf, q.rf)));

	return q;
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

int main()
{
	T v[MAX];
	int q, n;
	
	while(scanf("%d %d", &n, &q) && n)
	{
		for(int i=1; i<=n; ++i)
		{
			scanf("%d", &v[i].ln);
			v[i].rn = v[i].ln;
			v[i].lf = v[i].rf = v[i].mf = 1;
		}
		
		construct(n, v);
		
		while(q--)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", query(l, r).mf);
		}
	}
		
	return 0;
}
