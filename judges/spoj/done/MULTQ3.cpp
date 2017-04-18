/*
Tested with: http://www.spoj.com/problems/MULTQ3/
Problem:
There are N numbers a[0],a[1]..a[N - 1]. Initally all are 0. You have to perform two types of operations :

1) Increase the numbers between indices A and B (inclusive) by 1. This is represented by the command "0 A B"
2) Answer how many numbers between indices A and B (inclusive) are divisible by 3. This is represented by the command "1 A B".

Input :
The first line contains two integers, N and Q. Each of the next Q lines are either of the form "0 A B" or "1 A B" as mentioned above.

Output :
Output 1 line for each of the queries of the form "1 A B" containing the required answer for the corresponding query.
*/

#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 100005

class Node
{
	public:
	int zero, one, two;
	Node(int zero=0, int one=0, int two=0) : zero(zero), one(one), two(two) {};
	Node operator+(Node other) { return Node(zero + other.zero, one + other.one, two + other.two); }
};

Node tree[4*MAX]; 
int size, lazy[4*MAX];
bool changed[4*MAX];

inline int nextInt() 
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

void init()
{
	memset(lazy, 0, sizeof lazy);
	memset(changed, 0, sizeof(changed));
}

void build(int node, int begin, int end)
{
	if(begin == end) tree[node] = Node(1, 0, 0);
	else
	{
		int mid = (begin + end)/2, nodeLeft = 2*node, nodeRight = 2*node + 1;
		build(nodeLeft, begin, mid);
		build(nodeRight, mid + 1, end);
		tree[node] = tree[nodeLeft] + tree[nodeRight];
	}
}

inline void updateNode(int node)
{
	tree[node] = Node(tree[node].two, tree[node].zero, tree[node].one);
}

inline void propagate(int node, int value)
{
	int nodeLeft = 2*node, nodeRight = 2*node + 1;
	changed[nodeLeft] = changed[nodeRight] = 1;
	lazy[nodeLeft] += value;
	lazy[nodeRight] += value;
}

inline void updateLazy(int node, int start, int end)
{
	if(changed[node] == 1)
	{
		int nodeLeft = 2*node, nodeRight = 2*node + 1, upper = lazy[node]%3;
		for(int i=0; i<upper; ++i) updateNode(node);

		if(start != end) propagate(node, lazy[node]);
	
		lazy[node] = 0; changed[node] = 0;
	}

}

Node query(int node, int start, int end, int left, int right)
{
	updateLazy(node, start, end);

	if(left > end || right < start) return Node(0, 0, 0); 
		
	if(left <= start && right >= end) return tree[node];
	
	int mid = (start + end)/2, nodeLeft = 2*node, nodeRight = 2*node + 1;
	Node n1 = query(nodeLeft, start, mid, left, right);
	Node n2 = query(nodeRight, mid+1, end, left, right);
	
	return (n1 + n2); 
}

Node query(int left, int right)
{
	return query(1, 1, size, left, right);
}

void update(int node, int start, int end, int left, int right)
{
	updateLazy(node, start, end);

	if(left > end || right < start) return;
	if(start == end)
	{
		updateNode(node);
		return;
	}

	if(left <= start && right >= end)
	{
		propagate(node, 1);
		updateNode(node);
		return;
	}
	
	int mid = (start + end)/2, nodeLeft = 2*node, nodeRight = 2*node + 1;
	update(nodeLeft, start, mid, left, right);
	update(nodeRight, mid+1, end, left, right);
	
	tree[node] = tree[nodeLeft] + tree[nodeRight];

	return;
}

void update(int left, int right)
{
	update(1, 1, size, left, right);
}

void construct(int n)
{
	size = n;
	init();
	build(1, 1, n);
}

int main()
{
	int n, q, op, l, r;

	n = nextInt(); q = nextInt();
	construct(n);
	while(q--)
	{
		op = nextInt(); l = nextInt(); r = nextInt();
		++l; ++r;
		if(op) printf("%d\n", query(l, r).zero);
		else update(l, r);
	}

	return 0;
}
