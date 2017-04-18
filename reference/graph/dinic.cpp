/*
O(n*n*m)
Tested with: http://www.spoj.com/problems/FASTFLOW/
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f3f3f3f3fLL
typedef long long ll;

#define MAXN 5005
#define MAXM 2*30005
typedef ll flow_type;

struct Edge {
    int v;
    flow_type c, f;
    int next;
    Edge() {}
    Edge(int v, flow_type c, flow_type f, int next) :
        v(v), c(c), f(f), next(next) {}
};

int n_, m_, head_[MAXN], lvl_[MAXN], src_, snk_, work_[MAXN];
Edge e_[MAXM];

bool bfs() {
    queue<int> q;
    memset(lvl_, -1, n_ * sizeof(int));
    lvl_[src_] = 0;
    q.push(src_);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head_[u]; i != -1; i = e_[i].next) {
            if (e_[i].f < e_[i].c && lvl_[e_[i].v] == -1) {
                lvl_[e_[i].v] = lvl_[u] + 1;
                q.push(e_[i].v);
                if (e_[i].v == snk_) return 1;
            }
        }
    }
    return 0;
}

flow_type dfs(int u, flow_type f) {
    if (u == snk_) return f;
    for (int &i = work_[u]; i != -1; i = e_[i].next) {
        if (e_[i].f < e_[i].c && lvl_[u] + 1 == lvl_[e_[i].v]) {
            flow_type minf = dfs(e_[i].v, min(f, e_[i].c - e_[i].f));
            if (minf > 0) {
                e_[i].f += minf;
                e_[i ^ 1].f -= minf;
                return minf;
            }
        }
    }
    return 0;
}

flow_type dinic() {
    flow_type f, ret = 0;
    while (bfs()) {
        memcpy(work_, head_, n_ * sizeof(int));
        while ((f = dfs(src_, INF))) ret += f;
    }
    return ret;
}

void init(int n, int src, int snk) {
    n_ = n;
    m_ = 0;
    src_ = src;
    snk_ = snk;
    memset(head_, -1, sizeof(head_));
}

void add_edge(int u, int v, flow_type c, bool bidirectional) {
    e_[m_] = Edge(v, c, 0, head_[u]);
    head_[u] = m_++;
    e_[m_] = Edge(u, bidirectional ? c : 0, 0, head_[v]);
    head_[v] = m_++;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    init(n, 0, n - 1);
    while (m--) {
        int u, v;
        ll w;
        scanf("%d %d %lld", &u, &v, &w);
        --u; --v;
        add_edge(u, v, w, 1);
    }

    printf("%lld\n", dinic());

    return 0;
}
