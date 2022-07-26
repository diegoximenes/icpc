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

#define MAX 100000

int a[MAX], deg[MAX];
vector<int> g[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            g[i].clear();
            deg[i] = 0;
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            --u;
            --v;
            deg[u]++;
            deg[v]++;
            g[u].pb(v);
            g[v].pb(u);
        }

        if (m & 1) {
            int out = INF;
            for (int i = 0; i < n; ++i) {
                if (deg[i] & 1) {
                    out = min(out, a[i]);
                } else {
                    for (int j = 0; j < (int) g[i].size(); ++j) {
                        if (deg[g[i][j]] % 2 == 0) {
                            out = min(out, a[i] + a[g[i][j]]);
                        }
                    }
                }
            }
            printf("%d\n", out);
        } else {
            printf("0\n");
        }
    }

    return 0;
}
