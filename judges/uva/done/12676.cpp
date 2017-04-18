#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

typedef long long ll;
#define INF 1e17

struct Node
{
	int h;
	ll w;
	bool type;
	Node(int h, ll w, bool type) : h(h), w(w), type(type) {};
	bool operator<(Node o) const
	{
		if(h != o.h) return (h < o.h);
		if(w != o.w) return (w < o.w);
		return (type < o.type);
	}
};

int main()
{
	int n, x;
	ll level[55];
	
	while(scanf("%d", &n) == 1)
	{
		for(int i=0; i<55; ++i) level[i] = 1;
		priority_queue<Node> heap;
		for(int i=0; i<n; ++i) scanf("%d", &x), heap.push(Node(x, -INF, 0));
		
		ll sol = 0;
		while(heap.size() != 1)
		{
			Node n1 = heap.top(); heap.pop();
			Node n2 = heap.top(); heap.pop();
			
			level[n1.h] = max(level[n1.h], max(n1.w, n2.w));

			if(n1.type == 0) sol += level[n1.h + 1], n1.w = level[n1.h + 1];
			if(n2.type == 0) sol += level[n1.h + 1], n2.w = level[n1.h + 1];


			heap.push(Node(n1.h - 1, n1.w + n2.w, 1));
		}

		cout << sol << endl;
	}

	return 0;
}

