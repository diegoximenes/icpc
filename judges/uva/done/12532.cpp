#include<cstdio>
using namespace std;

#define MAX (int) 1e5+10

int tree[4*MAX], n;

void build(int node, int begin, int end, int *v)
{
	if(begin == end)
		tree[node] = v[begin];
	else
	{
		int mid = (begin+end)/2;
		build(2*node, begin, mid, v);
		build(2*node+1, mid+1, end, v);
		tree[node] = tree[2*node]*tree[2*node+1];
	}
}

void update(int node, int begin, int end, int pos, int value)
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
		tree[node] = tree[2*node]*tree[2*node+1];
	}
}

int query(int node, int begin, int end, int left, int right)
{
	if(begin>=left && end<=right)
		return tree[node];
	else
	{
		int mid = (begin+end)/2;
		int res = 1;
		if(mid >= left && begin <= right)
			res *= query(2*node, begin, mid, left, right);
		if(end >= left && mid+1 <= right)
			res *= query(2*node+1, mid+1, end, left, right);
		return res;
	}
}

void construct(int size, int *v)
{
	n = size;
	build(1, 1, n, v);
}

void update(int pos, int value)
{
	update(1, 1, n, pos, value);
}

int query(int left, int right)
{
	return query(1, 1, n, left, right);
}

int normalize(int a)
{
	if(a > 0)
		return 1;
	if(a < 0)
		return -1;
	return 0;
}

int main()
{
	int v[MAX], size, k;
	char line[100];

	while(scanf("%d %d", &size, &k) == 2)
	{
		for(int i=1; i<=size; ++i)
		{
			scanf("%d", &v[i]);
			v[i] = normalize(v[i]);
		}
		construct(size, v);
		getchar();
		while(k--)
		{
			int l, r, res;
			char op;

			gets(line);
			sscanf(line, "%c %d %d", &op, &l, &r);
			if(op == 'P')
			{
				res = query(l, r);
				if(res == 0)
					putchar('0');
				else if(res == 1)
					putchar('+');
				else putchar('-');
			}
			else
			{
				r = normalize(r);
				update(l, r);
			}
		}
		puts("");
	}

	return 0;
}
