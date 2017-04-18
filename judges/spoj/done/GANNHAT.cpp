#include<bits/stdc++.h>
using namespace std;

typedef int point_type;
typedef int dist_type;
#define pb push_back
#define MAX 200005

struct Point
{
	point_type x, y;
	int id;
	Point(point_type _x=0, point_type _y=0, int _id=0) : x(_x), y(_y), id(_id){}
};

bool cmpx(Point a, Point b) { return (a.x < b.x); }
bool cmpy(Point a, Point b) { return (a.y < b.y); }
inline dist_type dist1d(point_type a, point_type b) { return abs(a-b); }
inline dist_type dist(Point a, Point b) { return (abs(a.x-b.x) + abs(a.y-b.y)); }

const int root = 1; //1 based tree
Point tree[4*MAX];
bool isLeaf[4*MAX];

//O(nlogn)
void build(int node, int left, int right, int depth, vector<Point> &pnt)
{
	if(left == right) tree[node] = pnt[left], isLeaf[node] = 1;	
	else
	{
		int mid = (left + right)/2, nodeLeft = 2*node, nodeRight = 2*node+1;

		nth_element(pnt.begin() + left, pnt.begin() + mid, pnt.begin() + right + 1, depth&1 ? cmpy : cmpx);
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

//O(nlogn)
Point nearestNeighbor;
bool firstNearestNeighbor;
void findNearestNeighbor(int node, int depth, Point p)
{
	int nodeLeft = 2*node, nodeRight = 2*node+1;

	if(tree[node].id != p.id && (firstNearestNeighbor || dist(tree[node], p) < dist(nearestNeighbor, p)))
		nearestNeighbor = tree[node], firstNearestNeighbor = 0;
	
	if(isLeaf[node]) return;
		
	point_type a = depth&1 ? p.y : p.x;
	point_type split = depth&1 ? tree[node].y : tree[node].x;
	
	if(a < split) findNearestNeighbor(nodeLeft, depth+1, p);
	else findNearestNeighbor(nodeRight, depth+1, p);

	if(dist1d(a, split) < dist(nearestNeighbor, p)) 
		findNearestNeighbor((a < split) ? nodeRight : nodeLeft, depth+1, p);
}	
Point findNearestNeighbor(Point p)
{
	firstNearestNeighbor = 1;
	findNearestNeighbor(root, 0, p);
	return nearestNeighbor;
}

void init() { memset(isLeaf, 0, sizeof(isLeaf)); }

int main()
{
	int n;
	vector<Point> pnt, aux;

	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		pnt.pb(Point(x, y, i));
	}
	aux = pnt;
	build(pnt);
	
	for(int i=0; i<(int)aux.size(); ++i)
	{
		Point p = findNearestNeighbor(aux[i]);
		printf("%d\n", dist(p, aux[i]));
	}
	return 0;
}
