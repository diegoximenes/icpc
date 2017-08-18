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

#define MAX 100005

set<int> g[MAX];
int out[MAX], in_deg[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n + 1; ++i) g[i].clear();
        memset(in_deg, 0, sizeof(in_deg));
        memset(out, 0, sizeof(out));

        bool can = 1;
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (g[u].find(v) != g[u].end()) can = 0;
            g[u].insert(v);
            in_deg[v]++;
        }

        if (g[0].find(1) == g[0].end()) can = 0;

        int curr = 1;
        for (set<int>::iterator it = g[0].begin(); it != g[0].end(); ++it)
            out[*it] = curr++;

        for (int u = 1; can && u <= n; ++u) {
            if (in_deg[u] == 0) can = 0;

            set<int>::iterator it = g[0].upper_bound(u);
            if (it != g[0].end()) {
                for (; it != g[0].end(); ++it) {
                    if (g[u].find(*it) == g[u].end()) {
                        can = 0;
                        break;
                    }
                }
            }

            int cnt = 0, next = 0;
            for (it = g[u].begin(); it != g[u].end(); ++it) {
                if (out[*it] == 0) {
                    ++cnt;
                    next = *it;
                }
            }
            if (cnt > 1) {
                can = 0;
            } else if (next != 0) {
                out[next] = out[u];
            }
        }

        if (!can) {
            puts("-1");
        } else {
            printf("%d", out[1]);
            for (int u = 2; u <= n; ++u) printf(" %d", out[u]);
            puts("");
        }
    }

    return 0;
}
