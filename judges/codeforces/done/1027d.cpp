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

#define MAX 200005

int dfs_num[MAX], dfs_low[MAX], visited[MAX];
vector<int> s;
vector<int> g[MAX];
int c[MAX], scc[MAX], out_deg[MAX];
int cost_scc[MAX];
int dfs_cnt, num_scc;

void tarjan(int u) {
    dfs_low[u] = dfs_num[u] = dfs_cnt++;
    s.pb(u);
    visited[u] = 1;
    for (int j = 0; j < (int) g[u].size(); ++j) {
        int v = g[u][j];
        if (dfs_num[v] == -1) {
            tarjan(v);
        }
        if (visited[v]) {
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
    }
    if (dfs_low[u] == dfs_num[u]) {
        cost_scc[num_scc] = INF;
        while (1) {
            int v = s.back();
            scc[v] = num_scc;
            cost_scc[num_scc] = min(cost_scc[num_scc], c[v]);
            s.pop_back();
            visited[v] = 0;
            if (u == v) {
                break;
            }
        }
        num_scc++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n; ++i) {
        int v;
        scanf("%d", &v);
        g[i].pb(v - 1);
    }

    memset(dfs_num, -1, sizeof(dfs_num));
    memset(dfs_low, 0, sizeof(dfs_low));
    memset(visited, 0, sizeof(visited));
    dfs_cnt = num_scc = 0;
    for (int i = 0; i < n; ++i) {
        if (dfs_num[i] == -1) {
            tarjan(i);
        }
    }

    memset(out_deg, 0, sizeof(out_deg));
    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < (int) g[u].size(); ++i) {
            int v = g[u][i];
            if (scc[u] != scc[v]) {
                out_deg[scc[u]]++;
            }
        }
    }

    ll sol = 0;
    for (int i = 0; i < num_scc; ++i) {
        if (out_deg[i] == 0) {
            sol += (ll) cost_scc[i];
        }
    }
    cout << sol << endl;

    return 0;
}
