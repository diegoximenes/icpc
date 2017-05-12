/*
 * Tested with: http://www.spoj.com/problems/QTREE/
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

#define MAX 10005

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

/*
 * the code below is related to QTREE
 */

class SegTree {
public:
    vector<int> tree_;
    int size_;

    SegTree() {}
    SegTree(int size) {
        size_ = size;
        tree_.assign(4 * size + 1, -INF);
    }

    inline int node_left(int u) {
        return 2 * u;
    }
    inline int node_right(int u) {
        return 2 * u + 1;
    }

    int query(int node, int node_l, int node_r, int q_l, int q_r) {
        if (q_l > node_r || q_r < node_l) return -INF;
        if (node_l >= q_l && node_r <= q_r) return tree_[node];
        int mid = (node_l + node_r) / 2;
        return max(query(node_left(node), node_l, mid, q_l, q_r),
                   query(node_right(node), mid + 1, node_r, q_l, q_r));
    }
    int query(int q_l, int q_r) {
        return query(1, 1, size_, q_l, q_r);
    }

    void update(int node, int val, int node_l, int node_r, int pos) {
        if (node_l == node_r) {
            tree_[node] = val;
            return;
        }
        int mid = (node_l + node_r) / 2;
        if (pos <= mid) update(node_left(node), val, node_l, mid, pos);
        else update(node_right(node), val, mid + 1, node_r, pos);
        tree_[node] = max(tree_[node_left(node)], tree_[node_right(node)]);
    }
    void update(int pos, int val) {
        update(1, val, 1, size_, pos);
    }
};


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

SegTree segtree[MAX];
map< pair<int, int>, int> edge_w;
map< int, pair<int, int> > id_edge;

void build_segtrees() {
    for (int i = 0; i < cnt_chains_; ++i) {
        segtree[i] = SegTree(chain_vertices_[i].size() - 1);
        for (int j = 0; j < (int) chain_vertices_[i].size() - 1; ++j) {
            int u = chain_vertices_[i][j];
            int v = chain_vertices_[i][j + 1];
            segtree[i].update(j + 1, edge_w[mp(min(u, v), max(u, v))]);
        }
    }
}

int query(int u, int ancestor) {
    if (vertex_to_chain_[u] == vertex_to_chain_[ancestor]) {
        int l = vertex_pos_in_chain_[ancestor] + 1;
        int r = vertex_pos_in_chain_[u] - 1 + 1;
        if (r >= l)
            return segtree[vertex_to_chain_[u]].query(l, r);
        else
            return -INF;
    }
    int ret = -INF;
    int l = 1;
    int r = vertex_pos_in_chain_[u] - 1 + 1;
    if (r >= l) ret = max(ret, segtree[vertex_to_chain_[u]].query(l, r));
    int v = dad_[chain_head_[vertex_to_chain_[u]]];
    u = chain_head_[vertex_to_chain_[u]];
    ret = max(ret, edge_w[mp(min(u, v), max(u, v))]);
    ret = max(ret, query(v, ancestor));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        edge_w.clear();
        id_edge.clear();
        for (int i = 0; i < n; ++i) g[i].clear();

        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            --u; --v;
            g[u].pb(v); g[v].pb(u);
            edge_w[mp(min(u, v), max(u, v))] = w;
            id_edge[i] = mp(min(u, v), max(u, v));
        }

        init(0);
        build_segtrees();
        build_lca(n);

        char op[10];
        while (scanf(" %s ", op) && strcmp(op, "DONE")) {
            if (!strcmp(op, "QUERY")) {
                int u, v;
                scanf("%d %d", &u, &v);
                --u; --v;

                int ancestor = lca(u, v);
                printf("%d\n", max(query(u, ancestor), query(v, ancestor)));
            } else {
                int e, w;
                scanf("%d %d", &e, &w);
                --e;

                int u = id_edge[e].fi, v = id_edge[e].se;
                if (vertex_to_chain_[u] == vertex_to_chain_[v]) {
                    if (depth_[u] > depth_[v]) swap(u, v);
                    segtree[vertex_to_chain_[u]].
                        update(vertex_pos_in_chain_[u] + 1, w);
                } else {
                    edge_w[mp(min(u, v), max(u, v))] = w;
                }
            }
        }
    }

    return 0;
}
