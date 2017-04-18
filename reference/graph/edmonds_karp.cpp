/*
O(m * f), f = maximum flow
O(n * m * m)
*/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define MAX 200
#define INF 0x3f3f3f3f

vector<int> g_[MAX];
int flow_[MAX][MAX], cap_[MAX][MAX];
int n_, dad_[MAX];
bool mark_[MAX];

bool bfs(int s, int t) {
    queue<int> q;
    memset(mark_, 0, sizeof(mark_));
    mark_[s] = 1;
    dad_[s] = -1;
    q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (v == t) return 1;
        for (int i = 0; i < (int) g_[v].size(); ++i) {
            int u = g_[v][i];
            if (!mark_[u] && cap_[v][u] - flow_[v][u] > 0) {
                mark_[u] = 1;
                dad_[u] = v;
                q.push(u);
            }
        }
    }
    return 0;
}

int edmonds_karp(int s, int t) {
    int bottleneck, f = 0;
    memset(flow_, 0, sizeof(flow_));
    while (bfs(s, t)) {
        bottleneck = INF;
        for (int v = t; dad_[v] != -1; v = dad_[v])
            bottleneck = min(bottleneck, cap_[dad_[v]][v] - flow_[dad_[v]][v]);

        for (int v = t; dad_[v] != -1; v = dad_[v]) {
            flow_[dad_[v]][v] += bottleneck;
            flow_[v][dad_[v]] -= bottleneck;
        }
        f += bottleneck;
    }
    return f;
}

inline void add_edge(int u, int v, int w, bool bidirectional, int s, int t) {
    if ((v != s) && (u != t)) {
        g_[u].push_back(v);
        cap_[u][v] += w;
    }
    if ((u != s) && (v != t)) {
        g_[v].push_back(u);
        if (bidirectional) cap_[v][u] += w;
    }
}

void init(int n) {
    n_ = n;
    for (int i = 0; i < n_; ++i) g_[i].clear();
    memset(cap_, 0, sizeof(cap_));
}

int main() {
    int n, s, t, w, m, u, v;
    for(int k = 1; scanf("%d", &n) && n; ++k) {
        init(n);

        scanf("%d %d %d", &s, &t, &m);
        --s; --t;
        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            --u; --v;
            add_edge(u, v, w, 1, s, t);
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", k, edmonds_karp(s, t));
    }

    return 0;
}
