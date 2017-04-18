/*
O(n*m + f*m*log(n)), f = maximum flow
Work with multigraph and initial negative edges.
Tested with: live archive 3562
*/

#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define INF 0x3f3f3f3f
#define MAXN (55+55)
#define MAXM 2*(55*55 + 110) //must also counts reverse edges

typedef double cost_type;

struct Edge
{
    int u, v, cap, flow;
    cost_type cost;
    int next;
    Edge() {}
    Edge(int u, int v, int cap, int flow, cost_type cost, int next) :
        u(u), v(v), cap(cap), flow(flow), cost(cost), next(next) {}
};

int n_, m_, head_[MAXN], src_, snk_;
Edge e_[MAXM];
int path_[MAXN], mincap_[MAXN], vis_[MAXN];
cost_type pi_[MAXN], dist_[MAXN];

int bellman_ford() {
    for (int i = 0; i <= n_; ++i) pi_[i] = INF;
    pi_[src_] = 0;
    int flag = 1;
    for (int i = 0; flag && i < n_; i++) {
        flag = 0;
        for(int j = 0; j < m_; j++) {
            if (e_[j].cap == e_[j].flow) continue;
            if (pi_[e_[j].u] + e_[j].cost < pi_[e_[j].v]) {
                pi_[e_[j].v] = pi_[e_[j].u] + e_[j].cost;
                flag = 1;
            }
        }
    }
    return flag;
}

int dijkstra() {
    priority_queue< pair<cost_type, int>, vector< pair<cost_type, int> >,
        greater< pair<cost_type, int> > > heap;
    for (int i = 0; i <= n_; ++i) dist_[i] = INF;
    memset(vis_, 0, sizeof(vis_));
    dist_[src_] = 0;
    mincap_[src_] = INF;
    heap.push(mp(0, src_));
    while (!heap.empty()) {
        int u = heap.top().second;
        heap.pop();
        if (vis_[u]) continue;
        vis_[u] = 1;
        for (int i = head_[u]; i != -1; i = e_[i].next) {
            int v = e_[i].v;
            if (vis_[v] || e_[i].flow == e_[i].cap) continue;
            cost_type w = dist_[u] + e_[i].cost + pi_[u] - pi_[v];
            if (w < dist_[v]) {
                dist_[v] = w;
                path_[v] = i;
                mincap_[v] = min(mincap_[u], e_[i].cap - e_[i].flow);
                heap.push(mp(dist_[v], v));
            }
        }
    }

    // update potencials
    for (int i = 0; i < n_; i++) pi_[i] += dist_[i];

        return dist_[snk_] < INF;
}

pair<cost_type, int> mcmf() {
    // set potencials
    if (bellman_ford()) return mp(-1, -1);

    cost_type cost = 0;
    int flow = 0;
    while(dijkstra()) {
        // augment path and update cost
        int f = mincap_[snk_];
        for (int v = snk_; v != src_; ) {
            int idx = path_[v];
            e_[idx].flow += f;
            e_[idx ^ 1].flow -= f;
            cost += e_[idx].cost * f;
            v = e_[idx].u;
        }
        flow += f;
    }

    return mp(cost, flow);
}

void init(int n, int src, int snk) {
    n_ = n;
    m_ = 0;
    src_ = src;
    snk_ = snk;
    memset(head_, -1, sizeof(head_));
}

// not bidirectional: check dinic.cpp to transform bidirectional or add
// manually the reverse edge and adapt MAXM factor to 4
void add_edge(int u, int v, int cap, cost_type cost) {
    e_[m_] = Edge(u, v, cap, 0, cost, head_[u]);
    head_[u] = m_++;
    e_[m_] = Edge(v, u, 0, 0, -cost, head_[v]);
    head_[v] = m_++;
}

// problem variables
#define MAXLEFT 55
double cost[MAXLEFT][MAXLEFT];
int cap_left[MAXLEFT], cap_right[MAXLEFT];

int main() {
    int n_left, n_right;
    int source = 0, sink = 1;

    for (int tc = 1; scanf("%d %d", &n_left, &n_right) && n_left; ++tc) {
        for (int i = 0; i < n_left; ++i) scanf("%d", &cap_left[i]);
        for (int i = 0; i < n_right; ++i) scanf("%d", &cap_right[i]);
        for (int i = 0; i < n_left; ++i)
            for (int j = 0; j < n_right; ++j)
                scanf("%lf", &cost[i][j]);

        // minimum cost
        init(2 + n_left + n_right, source, sink);
        for (int i = 0; i < n_left; ++i)
            add_edge(source, 2 + i, cap_left[i], 0);
        for (int i = 0; i < n_right; ++i)
            add_edge(2 + n_left + i, sink, cap_right[i], 0);

        for (int i = 0; i < n_left; ++i)
            for (int j = 0; j < n_right; ++j)
                if (cost[i][j] > -1)
                    add_edge(2 + i, 2 + n_left + j, INF, cost[i][j]);

        double min_cost = mcmf().first;

        // maximum cost
        init(2 + n_left + n_right, source, sink);
        for (int i = 0; i < n_left; ++i)
            add_edge(source, 2 + i, cap_left[i], 0);
        for (int i = 0; i < n_right; ++i)
            add_edge(2 + n_left + i, sink, cap_right[i], 0);

        for (int i = 0; i < n_left; ++i)
            for (int j = 0; j < n_right; ++j)
                if (cost[i][j] > -1)
                    add_edge(2 + i, 2 + n_left + j, INF, -cost[i][j]);

        double max_cost = -mcmf().first;

        printf("Problem %d: %.2lf to %.2lf\n", tc, min_cost, max_cost);
    }

    return 0;
}
