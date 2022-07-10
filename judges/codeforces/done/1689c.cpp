#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

#define MAX 300000

int cnt_vertices[MAX];
vector<int> g[MAX];

int opt(int u, int dadu);

int dfs(int u, int dadu) {
    cnt_vertices[u] = 1;
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (v != dadu) {
            cnt_vertices[u] += dfs(v, u);
        }
    }
    return cnt_vertices[u];
}

int opt_1child(int u, int dadu) {
    int child = g[u][0];
    if (g[u][0] == dadu) {
        child = g[u][1];
    }
    return cnt_vertices[child] - 1;
}

int opt_2childs(int u, int dadu) {
    vector<int> childs;
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (v != dadu) {
            childs.pb(v);
        }
    }
    int opt1 = cnt_vertices[childs[0]] - 1 + opt(childs[1], u);
    int opt2 = cnt_vertices[childs[1]] - 1 + opt(childs[0], u);
    return max(opt1, opt2);
}

int opt(int u, int dadu) {
    if ((int) g[u].size() == 1) {
        if (dadu == -1) {
            return opt_1child(u, -1);
        }
        return 0;
    } else if ((int) g[u].size() == 2) {
        if (dadu == -1) {
            return opt_2childs(u, -1);
        }
        return opt_1child(u, dadu);
    } else {
        return opt_2childs(u, dadu);
    }
    return 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            g[i].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            --u;
            --v;
            g[u].pb(v);
            g[v].pb(u);
        }
        dfs(0, -1);
        printf("%d\n", opt(0, -1));
    }

    return 0;
}
