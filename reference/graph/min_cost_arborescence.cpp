#include <bits/stdc++.h>
using namespace std;

#define MAX 1010
#define INF (int) 1e9
#define pb push_back

int n_, root_, cost_, prev_[MAX], g_[MAX][MAX];
bool gb_[MAX][MAX], cycle_[MAX], mark_[MAX];
vector<int> ga_[MAX];

void add_edge(int u, int v, int w) {
    if (gb_[u][v]) {
        g_[u][v] = min(g_[u][v], w);
    } else {
        ga_[u].pb(v);
        g_[u][v] = w;
    }
    gb_[u][v] = 1;
}

void dfs(int v) {
    mark_[v] = 1;
    for (int i = 0; i < (int) ga_[v].size(); ++i) {
        int u = ga_[v][i];
        if (!mark_[u] && gb_[v][u]) dfs(u);
    }
}

bool check() {
    memset(mark_, 0, sizeof(mark_));
    dfs(root_);
    for (int i = 0; i < n_; ++i)
        if (!mark_[i])
            return 0;
    return 1;
}

int exist_cycle() {
    prev_[root_] = root_;
    for (int i = 0; i < n_; ++i)
        if (!cycle_[i] && (i != root_)) {
            prev_[i] = i;
            g_[i][i] = INF;
            for (int j = 0; j < n_; ++j)
                if (!cycle_[j] && gb_[j][i] && g_[j][i] < g_[prev_[i]][i])
                    prev_[i] = j;
        }
    for (int i = 0, j; i < n_; ++i) {
        if (cycle_[i]) continue;
        memset(mark_, 0, sizeof(mark_));
        j = i;
        while (!mark_[j]) {
            mark_[j] = 1;
            j = prev_[j];
        }
        if (j == root_) continue;
        return j;
    }
    return -1;
}

void update(int v) {
    cost_ += g_[prev_[v]][v];
    for(int i = prev_[v]; i != v; i = prev_[i]) {
        cost_ += g_[prev_[i]][i];
        cycle_[i] = 1;
    }

    for (int i = 0; i < n_; ++i)
        if (!cycle_[i] && gb_[i][v])
            g_[i][v] -= g_[prev_[v]][v];

    for (int j = prev_[v]; j != v; j = prev_[j])
        for (int i = 0; i < n_; ++i) {
            if (cycle_[i]) continue;
            if (gb_[i][j]) {
                if (gb_[i][v])
                    g_[i][v] = min(g_[i][v], g_[i][j] - g_[prev_[j]][j]);
                else
                    g_[i][v] = g_[i][j] - g_[prev_[j]][j];
                gb_[i][v] = 1;
            }

            if (gb_[j][i]) {
                if (gb_[v][i])
                    g_[v][i] = min(g_[v][i], g_[j][i]);
                else
                    g_[v][i] = g_[j][i];
                gb_[v][i] = 1;
            }
        }
}

bool min_cost_arborescense(int root) {
    root_ = root;
    if (!check()) return 0;

    memset(cycle_, 0, sizeof(cycle_));
    cost_ = 0;

    int v;
    while ((v = exist_cycle()) != -1) update(v);

    for (int i = 0; i < n_; ++i)
        if (i != root_ && !cycle_[i])
            cost_ += g_[prev_[i]][i];

    return 1;
}

void init(int n) {
    n_ = n;
    for (int i = 0; i < n_; ++i) ga_[i].clear();
    memset(g_, 0, sizeof(g_));
    memset(gb_, 0, sizeof(gb_));
    cost_ = 0;
}

int main() {
    int t, n, m, u, v, w;

    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        scanf("%d %d", &n, &m);
        init(n);

        while (m--) {
            scanf("%d %d %d", &u, &v, &w);
            add_edge(u, v, w);
        }
        printf("Case #%d: ", tc);
        if (min_cost_arborescense(0))
            printf("%d\n", cost_);
        else
            puts("Possums!");
    }

    return 0;
}
