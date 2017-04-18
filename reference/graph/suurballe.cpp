/*
Description: Find two disjoint paths in a nonnegatively-weighted directed graph,
so that connect the same pair of verticves and have minimum total length.

Version: EDGE disjoint, so can use same vertice multiple times

Complexity: complexity of dijkstra

Algorithm:
1. Find the shortest path tree T rooted at node s by running Dijkstra's
algorithm. This tree contains for every vertex u, a shortest path from s to u.
Let P1 be the shortest cost path from s to t. The Edges in T are called tree
Edges and the remaining Edges are called non tree Edges.
2. Modify the cost of each Edge in the graph by replacing the cost w(u,v) of
every Edge (u,v) by w'(u,v) = w(u,v) − d(s,v) + d(s,u). According to the
resulting modified cost function, all tree Edges have a cost of 0, and non
tree Edges have a non negative cost.
3. Create a residual graph Gt formed from G by removing the Edges of G that are
directed into s and by reversing the direction of the zero length Edges along
path P1.
4. Find the shortest path P2 in the residual graph Gt by running Dijkstra's
algorithm.
5. Discard the reversed Edges of P2 from both paths. The remaining Edges of P1
and P2 form a subgraph with two outgoing Edges at s, two incoming Edges at t,
and one incoming and one outgoing Edge at each remaining vertex. Therefore,
this subgraph consists of two Edge-disjoint paths from s to t and possibly some
additional (zero-length) cycles. Return the two disjoint paths from the
subgraph.

Variation: vertex disjoint paths
The version of Suurballe's algorithm as described above finds paths that have
disjoint Edges, but that may share vertices. It is possible to use the same
algorithm to find vertex-disjoint paths, by replacing each vertex by a pair of
adjacent vertices, one with all of the incoming adjacencies of the original
vertex, and one with all of the outgoing adjacencies. Two Edge-disjoint paths
in this modified graph necessarily correspond to two vertex-disjoint paths in
the original graph, and vice versa, so applying Suurballe's algorithm to the
modified graph results in the construction of two vertex-disjoint paths in the
original graph.
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 110
#define INF (int) 1e9
#define mp make_pair
#define pb push_back

struct Edge {
    int v, w;
    bool rev;
    Edge(int v = 0, int w = 0, bool rev = 0) : v(v), w(w), rev(rev) {}
};

list<Edge> g_[MAX];
list<Edge>::iterator it_;
bool mark_[MAX];
int dist1_[MAX], dist2_[MAX], n_;
Edge dad1_[MAX], dad2_[MAX];

void dijkstra(int s, int t, int *dist, Edge *dad) {
    set< pair<int, int> > heap;
    for (int i = 0; i < n_; ++i) dist[i] = INF;
    memset(mark_, 0, sizeof(mark_));
    dad[s].v = -1;
    dist[s] = 0;
    heap.insert(mp(dist[s], s));

    while (!heap.empty()) {
        int v = heap.begin()->second;
        heap.erase(heap.begin());
        mark_[v] = 1;

        for (it_ = g_[v].begin(); it_ != g_[v].end(); ++it_) {
            int u = it_->v, w = it_->w;
            bool rev = it_->rev;
            if (!mark_[u] && dist[u] > dist[v] + w) {
                heap.erase(mp(dist[u], u));
                dist[u] = dist[v] + w;
                dad[u] = Edge(v, w, rev);
                heap.insert(mp(dist[u], u));
            }
        }
    }
}

void modify_cost(int s, int *dist) {
    for (int v = 0; v < n_; ++v)
        for (it_ = g_[v].begin(); it_ != g_[v].end(); ++it_)
            it_->w = it_->w - dist[it_->v] + dist[v];
}

// update graph g
void generate_residual_graph(int s, int t, Edge *dad) {
    vector< pair<int, list<Edge>::iterator> > erase;
    vector< pair<int, Edge> > insert;
    set< pair<int, int> > tree;

    for (int v = t; dad[v].v != -1; v = dad[v].v) tree.insert(mp(v, dad[v].v));

    for (int v = 0; v < n_; ++v)
        for (it_ = g_[v].begin(); it_ != g_[v].end(); ++it_) {
            int u = it_->v;
            if (u == s) {
                erase.pb(mp(v, it_));
                continue;
            }
            if (tree.find(mp(u, v)) != tree.end()) {
                erase.pb(mp(v, it_));
                insert.pb(mp(u, Edge(v, 0, 1)));
            }
        }

    for (int i = 0; i < (int) erase.size(); ++i)
        g_[erase[i].first].erase(erase[i].second);
    for (int i = 0; i < (int) insert.size(); ++i)
        g_[insert[i].first].pb(insert[i].second);
}

int remove_common_Edges(int t, Edge *p1, Edge *p2, int *dist) {
    // keep Edges of the graph which contains only the Edges of the two paths
    set< pair<int, int> > e;
    set< pair<int, int> >::iterator ite;
    map< pair<int, int>, int > w;

    // insert Edges from path 1
    for (int v = t; p1[v].v != -1; v = p1[v].v) {
        e.insert(mp(p1[v].v, v));
        w[mp(p1[v].v, v)] = p1[v].w;
    }
    // insert Edges from path 2 - before adding an Edge verify if this Edge or
    // this Edge reversed was already inserted. If yes the previous Edge is
    // removed e the new Edge is discarted.
    for (int v = t; p2[v].v != -1; v = p2[v].v) {
        if(e.find(mp(v, p2[v].v)) != e.end()) {
            e.erase(mp(v, p2[v].v));
        } else if(e.find(mp(p2[v].v, v)) != e.end()) {
            e.erase(mp(p2[v].v, v));
        } else {
            e.insert(mp(p2[v].v, v));
            // adjust weights
            if(!p2[v].rev)
                w[mp(p2[v].v, v)] = p2[v].w + dist[v] - dist[p2[v].v];
            else
                w[mp(p2[v].v, v)] = p2[v].w - dist[v] + dist[p2[v].v];
        }
    }

    // calculate weight from both paths
    int d = 0;
    for (ite = e.begin(); ite != e.end(); ++ite) d += w[*ite];
    return d;
}

int suurballe(int s, int t) {
    dijkstra(s, t, dist1_, dad1_);
    modify_cost(s, dist1_);
    generate_residual_graph(s, t, dad1_);
    dijkstra(s, t, dist2_, dad2_);

    // there aren't two paths
    if (dist1_[t] == INF || dist2_[t] == INF) return -1;
    int dist = remove_common_Edges(t, dad1_, dad2_, dist1_);
    return dist;
}

void init(int n) {
    n_ = n;
    for (int i = 0; i < n_; ++i) g_[i].clear();
}

void add_edge(int u, int v, int w) {
    g_[u].pb(Edge(v, w, 0));
    g_[v].pb(Edge(u, w, 0));
}

int main() {
    int u, v, w, n, m;

    while (scanf("%d", &n) && n) {
        init(n);
        scanf("%d", &m);
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            --u; --v;
            add_edge(u, v, w);
        }

        int d = suurballe(0, n - 1);
        if (d < 0)
            puts("Back to jail");
        else
            printf("%d\n", d);
    }

    return 0;
}
