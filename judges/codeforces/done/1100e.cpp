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

#define MAX 100005

struct Edge {
    int id, u, v, w;
    Edge(int id = 0, int u = 0, int v = 0, int w = 0): id(id), u(u), v(v), w(w) {}
    bool operator<(Edge other) const {
        return (w < other.w);
    }
};

int n, m;
Edge edges[MAX];
vector<int> g[MAX];
int deg[MAX], order[MAX];

bool is_dag(int pos) {
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        deg[i] = 0;
    }

    for (int i = pos; i < m; ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        g[u].pb(v);
        deg[v]++;
    }

    int cnt_vertices = 0;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order[u] = cnt_vertices++;
        for (int i = 0; i < (int) g[u].size(); ++i) {
            int v = g[u][i];
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }

    return (cnt_vertices == n);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        --u; --v;
        edges[i] = Edge(i + 1, u, v, w);
    }

    sort(edges, edges + m);
    int l = 0, r = m - 1;
    int sol = INF;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (is_dag(mid)) {
            sol = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (sol == 0) {
        printf("0 0\n");
    } else {
        is_dag(sol);
        vector<int> to_reverse;
        for (int i = 0; i < sol; ++i) {
            int u = edges[i].u;
            int v = edges[i].v;
            if (order[u] > order[v]) {
                to_reverse.pb(edges[i].id);
            }
        }

        printf("%d %d\n", edges[sol - 1].w, (int) to_reverse.size());
        printf("%d", to_reverse[0]);
        for (int i = 1; i < (int) to_reverse.size(); ++i) {
            printf(" %d", to_reverse[i]);
        }
        puts("");
    }

    return 0;
}
