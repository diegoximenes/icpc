#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define INF 0x3f3f3f3f

#define MAX 100000
typedef int point_type;
typedef int dist_type;

const int root = 1; //1 based tree
struct Point
{
	point_type x, y, z;
	Point(point_type _x=0, point_type _y=0, point_type _z=0) : x(_x), y(_y), z(_z) {}
};
bool cmpx(Point a, Point b) { return (a.x < b.x); }
bool cmpy(Point a, Point b) { return (a.y < b.y); }
bool cmpz(Point a, Point b) { return (a.z < b.z); }

//kd-tree
Point tree[4*MAX];
bool isLeaf[4*MAX];

//O(nlogn)
void build(int node, int left, int right, int depth, vector<Point> &pnt)
{
	if(left == right) tree[node] = pnt[left], isLeaf[node] = 1;	
	else
	{
		int mid = (left + right)/2, nodeLeft = 2*node, nodeRight = 2*node+1;

		nth_element(pnt.begin() + left, pnt.begin() + mid, pnt.begin() + right + 1, (depth%3==0) ? cmpx : ((depth%3==1) ? cmpy : cmpz));
		tree[node] = pnt[mid];
		
		build(nodeLeft, left, mid, depth+1, pnt);
		build(nodeRight, mid+1, right, depth+1, pnt);
	}
}
void build(vector<Point> &pnt) 
{ 
	memset(isLeaf, 0, sizeof(isLeaf)); 
	build(root, 0, pnt.size()-1, 0, pnt);
}

/*
Range search procedures
O(sqrt(n) + k)
*/
struct Rect
{
	Point p1, p2; //p1 is the left down point and p2 the right upper point
	Rect(){}
	Rect(Point _p1, Point _p2) : p1(_p1), p2(_p2) {}
};

inline bool in(Point p, Rect r) 
{ 
	return (p.x >= r.p1.x && p.x <= r.p2.x && p.y >= r.p1.y && p.y <= r.p2.y && p.z >= r.p1.z && p.z <= r.p2.z); 
}
inline bool in(Rect r1, Rect r2) //return 1 if r1 is in r2
{
	return ((r1.p1.x >= r2.p1.x) && (r1.p2.x <= r2.p2.x) && (r1.p1.y >= r2.p1.y) && (r1.p2.y <= r2.p2.y) && (r1.p1.z >= r2.p1.z) && (r1.p2.z <= r2.p2.z));
}
inline bool intersect(Rect r1, Rect r2)
{
	if((r1.p2.x < r2.p1.x) || (r2.p2.x < r1.p1.x) || (r1.p2.y < r2.p1.y) || (r2.p2.y < r1.p1.y) || (r1.p2.z < r2.p1.z) || (r2.p2.z < r1.p1.z)) return 0;
	return 1;
}
void report(int node, vector<Point> &ret) //get all points in subtree defined by node
{
	if(isLeaf[node]) ret.pb(tree[node]);
	else
	{
		int nodeLeft = 2*node, nodeRight = 2*node + 1;
		report(nodeLeft, ret);
		report(nodeRight, ret);
	}
}
void rangeSearch(int node, int depth, Rect actualr, Rect searchr, vector<Point> &ret)
{
	if(isLeaf[node])
	{
		if(in(tree[node], searchr)) ret.pb(tree[node]);
		return;
	}
		
	int nodeLeft = 2*node, nodeRight = 2*node+1;
	Rect leftr = actualr, rightr = actualr;
	point_type split = (depth%3==0) ? tree[node].x : ((depth%3==1) ? tree[node].y : tree[node].z);
	if(depth%3 == 0)
	{
		leftr.p2.x = split;
		rightr.p1.x = split;
	}
	else if(depth%3 == 1)
	{
		leftr.p2.y = split;
		rightr.p1.y = split;
	}
	else
	{
		leftr.p2.z = split;
		rightr.p1.z = split;
	}
	
	if(in(leftr, searchr)) report(nodeLeft, ret);
	else if(intersect(leftr, searchr)) rangeSearch(nodeLeft, depth+1, leftr, searchr, ret);

	if(in(rightr, searchr)) report(nodeRight, ret);
	else if(intersect(rightr, searchr)) rangeSearch(nodeRight, depth+1, rightr, searchr, ret);
}
void rangeSearch(Rect r, vector<Point> &ret) { rangeSearch(root, 0, Rect(Point(-INF, -INF, -INF), Point(INF, INF, INF)), r, ret); }

inline ll squaredDist(Point a, Point b)
{
	return (1LL*(a.x-b.x)*(a.x-b.x) + 1LL*(a.y-b.y)*(a.y-b.y) + 1LL*(a.z-b.z)*(a.z-b.z));
}

int main()
{
	int n, k;

	while(scanf("%d %d", &n, &k) && n)
	{
		vector<Point> pnt;
		for(int i=0; i<n; ++i)
		{
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			pnt.pb(Point(x, y, z));
		}
		build(pnt);
	
		int sol = 0;
		for(int i=0; i<n; ++i)
		{
			vector<Point> ret;
			rangeSearch(Rect(Point(pnt[i].x-k, pnt[i].y-k, pnt[i].z-k), Point(pnt[i].x+k, pnt[i].y+k, pnt[i].z+k)), ret);
			
			--sol;
			for(int j=0; j<(int)ret.size(); ++j)
				if(squaredDist(ret[j], pnt[i]) < 1LL*k*k)	
					++sol;
		}

		printf("%d\n", sol/2);
	}

	return 0;
}
