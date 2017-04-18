#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

#define MAX 1000
typedef int point_type;
typedef int dist_type;

struct Point {
    point_type x, y;
    Point(point_type _x=0, point_type _y=0) : x(_x), y(_y) {}
};

bool cmpx(Point a, Point b) { return (a.x < b.x); }
bool cmpy(Point a, Point b) { return (a.y < b.y); }

// squared euclidean distances
inline dist_type dist1d(point_type a, point_type b) {
    return (a - b) * (a - b);
}
inline dist_type dist(Point a, Point b) {
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// kd-tree
Point tree_[4 * MAX];
bool is_leaf_[4 * MAX];
const int root = 1; // 1 based tree

// O(nlogn)
void build(int node, int left, int right, int depth, vector<Point> &pnt) {
    if (left == right) {
        tree_[node] = pnt[left];
        is_leaf_[node] = 1;
    } else {
        int mid = (left + right)/2;
        int node_left = 2 * node, node_right = 2 * node + 1;

        nth_element(pnt.begin() + left,
                    pnt.begin() + mid,
                    pnt.begin() + right + 1,
                    (depth & 1) ? cmpy : cmpx);
        tree_[node] = pnt[mid];

        build(node_left, left, mid, depth + 1, pnt);
        build(node_right, mid + 1, right, depth + 1, pnt);
    }
}

void build(vector<Point> &pnt) {
    memset(is_leaf_, 0, sizeof(is_leaf_));
    build(root, 0, pnt.size() - 1, 0, pnt);
}

/*
Tested with: spoj(GANNHAT)
Find nearest neighbors procedures

to adapt to find the k-nearest neighbors instead of maintaining a unique point
maintain a set with k points
O(nlogn + k)
*/

Point nearest_neighbor_;
bool first_nearest_neighbor_;

void find_nearest_neighbor(int node, int depth, Point p) {
    int node_left = 2 * node, node_right = 2 * node + 1;

    if (first_nearest_neighbor_ ||
        (dist(tree_[node], p) < dist(nearest_neighbor_, p))) {
        nearest_neighbor_ = tree_[node];
        first_nearest_neighbor_ = 0;
    }

    if (is_leaf_[node]) return;

    point_type a = (depth & 1) ? p.y : p.x;
    point_type split = (depth & 1) ? tree_[node].y : tree_[node].x;

    if (a < split)
        find_nearest_neighbor(node_left, depth + 1, p);
    else
        find_nearest_neighbor(node_right, depth + 1, p);

    if (dist1d(a, split) < dist(nearest_neighbor_, p))
        find_nearest_neighbor((a < split) ? node_right : node_left,
                              depth + 1,
                              p);
}

Point find_nearest_neighbor(Point p) {
    first_nearest_neighbor_ = 1;
    find_nearest_neighbor(root, 0, p);
    return nearest_neighbor_;
}

/*
Tested with: 6487(was expanded to word with 3d points)
Range search procedures
O(sqrt(n) + k)
*/
struct Rect {
    Point p1, p2; //p1 is the left down point and p2 the right upper point
    Rect(){}
    Rect(Point _p1, Point _p2) : p1(_p1), p2(_p2) {}
};

inline bool in(Point p, Rect r) {
    return (p.x >= r.p1.x && p.x <= r.p2.x && p.y >= r.p1.y && p.y <= r.p2.y);
}

// return 1 if r1 is in r2
inline bool in(Rect r1, Rect r2) {
    return ((r1.p1.x >= r2.p1.x) && (r1.p2.x <= r2.p2.x) &&
            (r1.p1.y >= r2.p1.y) && (r1.p2.y <= r2.p2.y));
}

inline bool intersect(Rect r1, Rect r2) {
    if((r1.p2.x < r2.p1.x) || (r2.p2.x < r1.p1.x) ||
       (r1.p2.y < r2.p1.y) || (r2.p2.y < r1.p1.y)) {
        return 0;
    }
    return 1;
}

// get all points in subtree defined by node
void report(int node, vector<Point> &ret)  {
    if (is_leaf_[node]) {
        ret.pb(tree_[node]);
    } else {
        int node_left = 2 * node, node_right = 2 * node + 1;
        report(node_left, ret);
        report(node_right, ret);
    }
}

void range_search(int node, int depth, Rect actualr, Rect searchr,
                  vector<Point> &ret) {
    if (is_leaf_[node]) {
        if (in(tree_[node], searchr)) ret.pb(tree_[node]);
        return;
    }

    int node_left = 2 * node, node_right = 2 * node + 1;
    Rect leftr = actualr, rightr = actualr;
    point_type split = (depth & 1) ? tree_[node].y : tree_[node].x;
    if (depth & 1 == 0) {
        leftr.p2.x = split;
        rightr.p1.x = split;
    } else {
        leftr.p2.y = split;
        rightr.p1.y = split;
    }

    if (in(leftr, searchr))
        report(node_left, ret);
    else if (intersect(leftr, searchr))
        range_search(node_left, depth + 1, leftr, searchr, ret);

    if (in(rightr, searchr))
        report(node_right, ret);
    else if (intersect(rightr, searchr))
        range_search(node_right, depth + 1, rightr, searchr, ret);
}

void range_search(Rect r, vector<Point> &ret) {
    range_search(root, 0, Rect(Point(-INF, -INF), Point(INF, INF)), r, ret);
}
