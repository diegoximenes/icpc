#include<cstdio>
#include<utility>
using namespace std;

#define mp make_pair
#define MAX 30005

int size;
pair<int, int> tree[4*MAX];
char s[MAX];

void updateNode(pair<int, int> &node, pair<int, int> l, pair<int, int> r)
{
	node.first = l.first;
	node.second = r.second;
	if(l.second >= r.first) node.second += l.second - r.first;
	else node.first += r.first - l.second;
}

void build(int node, int begin, int end)
{
	if(begin == end)
	{
		if(s[begin-1] == ')') tree[node] = mp(1, 0);
		else tree[node] = mp(0, 1);
	}
	else
	{
		int mid = (begin+end)/2;
		build(2*node, begin, mid);
		build(2*node+1, mid+1, end);
		updateNode(tree[node], tree[2*node], tree[2*node+1]);
	}
}

void update(int node, int begin, int end, int pos)
{
	if(begin == end)
	{
		if(tree[node] == mp(1, 0)) tree[node] = mp(0, 1);
		else tree[node] = mp(1, 0);
	}
	else
	{
		int mid = (begin+end)/2;
		if(pos <= mid) update(2*node, begin, mid, pos);
		else update(2*node+1, mid+1, end, pos);
		
		updateNode(tree[node], tree[2*node], tree[2*node+1]);
	}
}

pair<int, int> query(int node, int begin, int end, int left, int right)
{
	if((begin >= left) && (end <= right)) return tree[node];
	else
	{
		int mid = (begin+end)/2;
		pair<int, int> ret = mp(0, 0), l = mp(0, 0), r = mp(0, 0);
		if((mid >= left) && (begin <= right)) l = query(2*node, begin, mid, left, right);
		if((end >= left) && (mid+1 <= right)) r = query(2*node+1, mid+1, end, left, right);
		updateNode(ret, l, r);
		return ret;
	}
}

void construct(int n)
{
	size = n;
	build(1, 1, size);
}

void update(int pos)
{
	update(1, 1, size, pos);
}

pair<int, int> query(int left, int right)
{
	return query(1, 1, size, left, right);
}

int main()
{
	int n, q;

	for(int tc=1; scanf("%d", &n) == 1; ++tc)
	{
		printf("Test %d:\n", tc);
		scanf(" %s %d", s, &q);
		
		construct(n);
		while(q--)
		{
			int x;
			scanf("%d", &x);
			//printf("query(1, n)= %d\n", query(1, n));
			if(x == 0) puts((query(1, n) == mp(0, 0)) ? "YES" : "NO");
			else update(x);
		}
	}

	
	return 0;
}
