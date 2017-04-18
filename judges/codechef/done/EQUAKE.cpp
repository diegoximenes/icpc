#include<bits/stdc++.h>
using namespace std;

#define MAX 800005
#define AMAX 10005
#define nodeLen 12 //lcm(1, 2, 3, 4)

inline int next_int() 
{
	int n = 0;
	char c = getchar_unlocked();
	while (!('0' <= c && c <= '9')) c = getchar_unlocked();
	while ('0' <= c && c <= '9') 
	{
		n = n * 10 + c - '0';
		c = getchar_unlocked();
	}
	return n;
}

int tree[4*MAX][nodeLen];
int size, lazy[4*MAX];
bool changed[4*MAX];

int v[MAX], a[nodeLen], b[nodeLen];
int shifted[AMAX][nodeLen];

void init()
{
	memset(lazy, 0, sizeof lazy);
	memset(changed, 0, sizeof(changed));
}

inline void joinNode(int *nodeLeft, int *nodeRight, int *ret)
{
	for(int i=0; i<nodeLen; ++i) ret[i] = max(nodeLeft[i], nodeRight[i]);
}

void build(int node, int begin, int end)
{
	if(begin == end)
	{
		int h = v[begin], numLen = 0;
		
		if(shifted[h][0] == -1)
		{
			for(int i=0; i<nodeLen; ++i)
			{
				a[i] = h%10;
				h/=10;
				numLen++; 
				if(h == 0) break;
			}
			reverse(a, a+numLen);

			for(int i=0; i<nodeLen; ++i)
			{
				for(int j=0; j<numLen; ++j) b[j] = a[(j+i)%numLen];

				int k = 1, num = 0;
				for(int j=numLen-1; j>=0; --j, k*=10) num += b[j]*k;

				shifted[v[begin]][i] = num;

			}
		}

		for(int i=0; i<nodeLen; ++i) tree[node][i] = shifted[v[begin]][i];
	}
	else
	{
		int mid = (begin + end)/2, nodeLeft = 2*node, nodeRight = 2*node + 1;
		build(nodeLeft, begin, mid);
		build(nodeRight, mid + 1, end);

		joinNode(tree[nodeLeft], tree[nodeRight], tree[node]);
	}
}

inline void updateNode(int node, int updateTimes)
{
	memcpy(a, tree[node], sizeof(a));
	for(int i=0; i<nodeLen; ++i) tree[node][i] = a[(i + updateTimes)%nodeLen];
	/*for(int i=0; i<updateTimes; ++i)
	{
		memcpy(a, tree[node], sizeof(a));
		for(int j=0; j<nodeLen; ++j) tree[node][j] = a[(j + 1)%nodeLen];
	}*/
}

inline void updateLazy(int node, int start, int end)
{
	if(changed[node] == 1)
	{
		int nodeLeft = 2*node, nodeRight = 2*node + 1;
		updateNode(node, lazy[node]%nodeLen);

		if(start != end)
		{
			changed[nodeLeft] = changed[nodeRight] = 1;
			lazy[nodeLeft] += lazy[node]; lazy[nodeRight] += lazy[node];
		}
		lazy[node] = 0; changed[node] = 0;
	}
}

void query(int node, int start, int end, int left, int right, int *ret)
{
	int qleft[nodeLen], qright[nodeLen];

	updateLazy(node, start, end);

	if(left > end || right < start)
	{
		memset(ret, 0, sizeof(ret));
		return; 
	}

	if(left <= start && right >= end)
	{
		memcpy(ret, tree[node], sizeof(ret));
		return;
	}
	
	int mid = (start + end)/2, nodeLeft = 2*node, nodeRight = 2*node + 1;
	query(nodeLeft, start, mid, left, right, qleft);
	query(nodeRight, mid+1, end, left, right, qright);
	
	joinNode(qleft, qright, ret); 
}

int query(int left, int right)
{
	int ret[nodeLen];
	query(1, 1, size, left, right, ret);
	return ret[0];
}

void update(int node, int start, int end, int left, int right, int shift)
{
	updateLazy(node, start, end);

	if(left > end || right < start) return;
	if(start == end)
	{
		updateNode(node, shift%nodeLen);
		return;
	}

	int mid = (start + end)/2, nodeLeft = 2*node, nodeRight = 2*node + 1;
	if(left <= start && right >= end)
	{
		lazy[nodeLeft] += shift; lazy[nodeRight] += shift;
		changed[nodeLeft] = changed[nodeRight] = 1;

		updateNode(node, shift%nodeLen);
		return;
	}
	
	update(nodeLeft, start, mid, left, right, shift);
	update(nodeRight, mid+1, end, left, right, shift);
	
	joinNode(tree[nodeLeft], tree[nodeRight], tree[node]);

	return;
}

void update(int left, int right, int shift)
{
	update(1, 1, size, left, right, shift);
}

void construct(int n)
{
	size = n;
	init();
	build(1, 1, n);
}

int main()
{
	int n, m, op, l, r, shift;
	
	//scanf("%d", &n);
	n = next_int();
	for(int i=1; i<=n; ++i) v[i] = next_int(); //scanf("%d", &v[i]);
	memset(shifted, -1, sizeof(shifted));
	construct(n);
	
	//scanf("%d", &m);
	m = next_int();
	while(m--)
	{
		//scanf("%d %d %d", &op, &l, &r);
		op = next_int(); l = next_int(); r = next_int();
		++l; ++r;
		if(op)
		{
			//printf("query= %d, %d= ", l, r);
			printf("%d\n", query(l, r));
		}
		else
		{
			//scanf("%d", &shift); 
			shift = next_int();
			update(l, r, shift);
		}
	}
	
	return 0;
}
