/*
Maximum matching in general graph
O(n**3) // can be O(m*n**2)
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 105

vector<int> g_[MAX];
int n_, match_[MAX], base_[MAX], p_[MAX], q_[MAX];
bool blossom_[MAX];
bool used_lca_[MAX], used_find_path_[MAX];

int lca(int a, int b) {
    memset(used_lca_, 0, sizeof(used_lca_));
    while (1) {
        a = base_[a];
        used_lca_[a] = 1;
        if (match_[a] == -1) break;
        a = p_[match_[a]];
    }
    while (1) {
        b = base_[b];
        if (used_lca_[b]) return b;
        b = p_[match_[b]];
    }
}

void mark_path(int v, int b, int children) {
    for (; base_[v] != b; v = p_[match_[v]]) {
        blossom_[base_[v]] = blossom_[base_[match_[v]]] = 1;
        p_[v] = children;
        children = match_[v];
    }
}

int find_path(int root) {
    memset(used_find_path_, 0, sizeof(used_find_path_));
    memset(p_, -1, sizeof(p_));
    memset(q_, 0, sizeof(q_));
    for (int i = 0; i < n_; ++i) base_[i] = i;

    used_find_path_[root] = 1;
    int qh = 0, qt = 0;
    q_[qt++] = root;
    while (qh < qt) {
        int v = q_[qh++];
        for (int j = 0; j < (int) g_[v].size(); ++j) {
            int to = g_[v][j];

            if (base_[v] == base_[to] || match_[v] == to) continue;
            if (to == root || match_[to] != -1 && p_[match_[to]] != -1) {
                int curbase = lca(v, to);
                memset(blossom_, 0, sizeof(blossom_));
                mark_path(v, curbase, to);
                mark_path(to, curbase, v);
                for (int i = 0; i < n_; ++i)
                    if (blossom_[base_[i]]) {
                        base_[i] = curbase;
                        if (!used_find_path_[i]) {
                            used_find_path_[i] = 1;
                            q_[qt++] = i;
                        }
                    }
            } else if(p_[to] == -1) {
                p_[to] = v;
                if (match_[to] == -1) return to;
                to = match_[to];
                used_find_path_[to] = 1;
                q_[qt++] = to;
            }
        }
    }
    return -1;
}

int max_matching() {
    memset(match_, -1, sizeof(match_));
    memset(p_, 0, sizeof(p_));
    for (int i = 0; i < n_; ++i)
        if (match_[i] == -1) {
            int v = find_path(i);
            while (v != -1) {
                int pv = p_[v], ppv = match_[pv];
                match_[v] = pv;
                match_[pv] = v;
                v = ppv;
            }
        }

    int matches = 0;
    for (int i = 0; i < n_; ++i)
        if (match_[i] != -1)
            ++matches;
    return matches / 2;
}

void init(int n) {
    n_ = n;
    for (int i = 0; i < n_; ++i) g_[i].clear();
}

void add_edge(int u, int v) {
    g_[u].pb(v); g_[v].pb(u);
}

int main() {
    int t, u, v, m, n;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        init(n);
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            u--; v--;
            add_edge(u, v);
        }

        int match = max_matching();
        if (match * 2 == n && m > match)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}
