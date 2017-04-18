/*
O(f*m*log(n)), f = maximum flow
Use modified dijkstra.
Work with non-negative initial edges.
Doesn't work with multigraph: see min_cost_max_flow.cpp.
tested with: 10594 (uva)
*/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define MAX 110
#define INFLL 0x3f3f3f3f3f3f3f3fLL

typedef long long ll;
typedef ll cost_type;
typedef ll flow_type;

vector< pair<int, ll> > g_[MAX];
int n_, dad_[MAX];
flow_type flow_[MAX][MAX], cap_[MAX][MAX];
cost_type dist_[MAX], pot_[MAX];

void dijkstra(int s, int t) {
    for (int i = 0; i < n_; ++i) dist_[i] = INFLL;
    dist_[s] = 0;
    priority_queue< pair<cost_type, int> > pq;
    pq.push(mp(0, s));
    dad_[s] = -1;

    while (!pq.empty()) {
        int v = pq.top().second;
        cost_type d = -pq.top().first;
        pq.pop();

        if (d == dist_[v]) {
            for (int j = 0; j < (int) g_[v].size(); ++j) {
                int u = g_[v][j].first;
                cost_type w = g_[v][j].second;
                cost_type newdist = dist_[v] + w + pot_[v] - pot_[u];
                if(dist_[u] > newdist && cap_[v][u] - flow_[v][u] > 0) {
                    dist_[u] = newdist;
                    dad_[u] = v;
                    pq.push(mp(-dist_[u], u));
                }
                newdist = dist_[v] + pot_[v] - w - pot_[u];
                if(flow_[u][v] > 0 && dist_[u] > newdist) {
                    dist_[u] = newdist;
                    dad_[u] = v;
                    pq.push(mp(-dist_[u], u));
                }
            }
        }
    }
}

pair<flow_type, cost_type> mcmf(int s, int t) {
    flow_type bottleneck, f = 0;
    cost_type cost = 0;

    memset(flow_, 0, sizeof(flow_));
    for (int i=0; i <= n_; ++i) pot_[i] = 0;

    while (1) {
        dijkstra(s, t);
        if (dist_[t] == INFLL) break;

        bottleneck = INFLL;
        for (int v = t; dad_[v] != -1; v = dad_[v])
            bottleneck = min(bottleneck, cap_[dad_[v]][v] - flow_[dad_[v]][v]);

        cost += bottleneck * (dist_[t] - pot_[s] + pot_[t]);

        for (int i = 0; i < n_; ++i)
            if (dist_[i] != INFLL)
                pot_[i] += dist_[i];

        for (int v = t; dad_[v] != -1; v = dad_[v]) {
            flow_[dad_[v]][v] += bottleneck;
            flow_[v][dad_[v]] -= bottleneck;
        }
        f += bottleneck;
    }

    return mp(f, cost);
}

void add_edge(int u, int v, cost_type w, int cap, bool bidirectional,
              int s, int t) {
    if((v != s) && (u != t)) {
        g_[u].push_back(mp(v, w));
        cap_[u][v] = cap;
    }
    if(bidirectional && (u != s) && (v != t)) {
        g_[v].push_back(mp(u, w));
        cap_[v][u] = cap;
    }
}

void init(int n) {
    n_ = n;
    memset(cap_, 0, sizeof(cap_));
    for (int i = 0; i < n_; ++i) g_[i].clear();
}

int main() {
    int s, t, n, m, u, v;
    cost_type w;
    flow_type d, k;

    while (scanf("%d %d", &n, &m) == 2) {
        init(n + 1);

        s = n;
        t = n-1;
        n++;
        vector< pair< pair<int, int>, ll > > edges;
        while (m--) {
            scanf("%d %d %lld", &u, &v, &w);
            --u; --v;
            edges.push_back(mp(mp(u, v), w));
        }
        scanf("%lld %lld", &d, &k);

        for (int i = 0; i < (int) edges.size(); ++i)
            add_edge(edges[i].first.first, edges[i].first.second,
                     edges[i].second, k, 1, s, t);
        add_edge(s, 0, 0, d, 0, s, t);

        pair<flow_type, cost_type> p = mcmf(s, t);
        if (d == p.first)
            printf("%lld\n", p.second);
        else
            puts("Impossible.");
    }

    return 0;
}
