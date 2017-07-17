#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
const double PI = acos(-1);
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int next_int() {
    int n = 0;
    char c = getchar_unlocked();
    while (!('0' <= c && c <= '9')) c = getchar_unlocked();
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    return n;
}

#define MAX 100005

vector<int> g[MAX];
int cnt_chains_, chain_head_[MAX];
int vertex_to_chain_[MAX], vertex_pos_in_chain_[MAX];
vector<int> chain_vertices_[MAX];
int subtree_size_[MAX], depth_[MAX], dad_[MAX];
bool mark_[MAX];

int dfs(int u, int dad, int depth) {
    mark_[u] = 1;
    depth_[u] = depth;
    dad_[u] = dad;
    subtree_size_[u] = 1;
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (!mark_[v]) subtree_size_[u] += dfs(v, u, depth + 1);
    }
    return subtree_size_[u];
}

void hld(int u) {
    if (chain_head_[cnt_chains_] == -1) chain_head_[cnt_chains_] = u;
    vertex_to_chain_[u] = cnt_chains_;
    vertex_pos_in_chain_[u] = chain_vertices_[cnt_chains_].size();
    chain_vertices_[cnt_chains_].pb(u);

    int u_largest_subtree = -1, size_largest_subtree = -1;
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (v != dad_[u] && subtree_size_[v] > size_largest_subtree) {
            size_largest_subtree = subtree_size_[v];
            u_largest_subtree = v;
        }
    }

    if (u_largest_subtree != -1) hld(u_largest_subtree);

    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (v != dad_[u] && v != u_largest_subtree) {
            cnt_chains_++;
            hld(v);
        }
    }
}

void init(int root) {
    cnt_chains_ = 0;
    memset(chain_head_, -1, sizeof(chain_head_));
    memset(mark_, 0, sizeof(mark_));
    for (int i = 0; i < MAX; ++i) chain_vertices_[i].clear();
    dfs(root, -1, 0);
    hld(root);
    cnt_chains_++;
}

#define LOGNMAX 20
int ancestor_[MAX][LOGNMAX];

void build_lca(int n) {
    memset(ancestor_, -1, sizeof(ancestor_));
    for (int i = 0; i < n; ++i) ancestor_[i][0] = dad_[i];
    for (int j = 1; (1 << j) < n; ++j)
        for (int i = 0; i < n; ++i)
            if (ancestor_[i][j - 1] != -1)
                ancestor_[i][j] = ancestor_[ancestor_[i][j - 1]][j - 1];
}

int lca(int p, int q) {
    int log;

    // if q is situated on a higher depth than p then swap them
    if (depth_[p] < depth_[q]) swap(p, q);

    // compute log(depth[p])
    for (log = 1; (1 << log) <= depth_[p]; ++log);
    --log;

    // find the ancestor of p situated on the same depth of q
    for (int i = log; i >= 0; --i)
        if (depth_[p] - (1 << i) >= depth_[q])
            p = ancestor_[p][i];

    if (p == q) return p;

    for (int i = log; i >= 0; --i)
        if (ancestor_[p][i] != -1 && ancestor_[p][i] != ancestor_[q][i]) {
            p = ancestor_[p][i];
            q = ancestor_[q][i];
        }

    return dad_[p];
}

class BIT {
public:
    vector<int> tree_;
    int size_;

    BIT() {}
    BIT(int size) {
        size_ = size;
        tree_.assign(size + 1, 0);
    }

    int query(int idx) {
        int ret = 0;
        while (idx > 0) {
            ret ^= tree_[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }
    int query(int a, int b) {
        return query(b) ^ query(a - 1);
    }

    void update(int idx, int val) {
        while (idx <= size_) {
            tree_[idx] ^= val;
            idx += (idx & -idx);
        }
    }
};

class Edge {
public:
    int u, v, w;
    Edge () {}
    Edge (int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator<(const Edge &o) const {
        return w < o.w;
    }
};

map< pair<int, int>, int> edge_w;
BIT bit[MAX];
pair<Edge, int> request[MAX];
Edge edge[MAX];
int out[MAX];

int query(int u, int ancestor, int k) {
    if (vertex_to_chain_[u] == vertex_to_chain_[ancestor]) {
        int l = vertex_pos_in_chain_[ancestor] + 1;
        int r = vertex_pos_in_chain_[u] - 1 + 1;
        if (r >= l) return bit[vertex_to_chain_[u]].query(l, r);
        return 0;
    }
    int ret = 0;
    int l = 1;
    int r = vertex_pos_in_chain_[u] - 1 + 1;
    if (r >= l) ret ^= bit[vertex_to_chain_[u]].query(l, r);
    int v = dad_[chain_head_[vertex_to_chain_[u]]];
    u = chain_head_[vertex_to_chain_[u]];
    int w = edge_w[mp(min(u, v), max(u, v))];
    if (w <= k) ret ^= w;
    ret ^= query(v, ancestor, k);
    return ret;
}

int main() {
    int t = next_int();
    while (t--) {
        int n = next_int();

        for (int i = 0; i < n; ++i) g[i].clear();
        edge_w.clear();

        for (int i = 0; i < n - 1; ++i) {
            int u = next_int(), v = next_int(), c = next_int();
            --u; --v;
            g[u].pb(v); g[v].pb(u);
            edge[i] = Edge(u, v, c);
            edge_w[mp(min(u, v), max(u, v))] = c;
        }

        init(0);
        build_lca(n);

        for (int i = 0; i < cnt_chains_; ++i)
            bit[i] = BIT(chain_vertices_[i].size());

        int q = next_int();
        for (int i = 0; i < q; ++i) {
            int u = next_int(), v = next_int(), k = next_int();
            --u; --v;
            request[i] = mp(Edge(u, v, k), i);
        }
        sort(request, request + q);

        sort(edge, edge + n - 1);
        int i_edge = 0;
        for (int i = 0; i < q; ++i) {
            Edge rq = request[i].fi;
            for (; i_edge < n - 1 && edge[i_edge].w <= rq.w; ++i_edge) {
                int u = edge[i_edge].u, v = edge[i_edge].v;
                if (vertex_to_chain_[u] == vertex_to_chain_[v]) {
                    if (dad_[v] != u) swap(u, v);
                    bit[vertex_to_chain_[u]]
                        .update(vertex_pos_in_chain_[u] + 1, edge[i_edge].w);
                }
            }

            int u = rq.u, v = rq.v;
            int ancestor = lca(u, v);
            if (depth_[u] < depth_[v]) swap(u, v);
            int ret = 0;
            if (ancestor == v)
                ret = query(u, v, rq.w);
            else
                ret = query(u, ancestor, rq.w) ^ query(v, ancestor, rq.w);
            out[request[i].se] = ret;
        }

        for (int i = 0; i < q; ++i) printf("%d\n", out[i]);
    }
    return 0;
}
