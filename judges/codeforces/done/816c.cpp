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

#define MAX 105

int g[MAX][MAX];
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%d", &g[i][j]);

    vector< pair<string, int> > out;

    if (n < m) {
        for (int i = 0; i < n; ++i) {
            int minr = INF;
            for (int j = 0; j < m; ++j) minr = min(minr, g[i][j]);
            for (int k = 0; k < minr; ++k) out.pb(mp("row", i + 1));
            for (int j = 0; j < m; ++j) g[i][j] -= minr;
        }
        for (int j = 0; j < m; ++j) {
            if (g[0][j]) {
                int sub = g[0][j];
                for (int k = 0; k < sub; ++k) {
                    out.pb(mp("col", j + 1));
                }
                for (int i = 0; i < n; ++i) {
                    g[i][j] -= sub;
                }
            }
        }
    } else {
        for (int j = 0; j < m; ++j) {
            int minc = INF;
            for (int i = 0; i < n; ++i) minc = min(minc, g[i][j]);
            for (int k = 0; k < minc; ++k) out.pb(mp("col", j + 1));
            for (int i = 0; i < n; ++i) g[i][j] -= minc;
        }
        for (int i = 0; i < n; ++i) {
            if (g[i][0]) {
                int sub = g[i][0];
                for (int k = 0; k < sub; ++k) {
                    out.pb(mp("row", i + 1));
                }
                for (int j = 0; j < m; ++j) {
                    g[i][j] -= sub;
                }
            }
        }
    }

    bool can = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (g[i][j] != 0)
                can = 0;

    if (!can) {
        puts("-1");
    } else {
        printf("%d\n", (int) out.size());
        for (int i = 0; i < (int) out.size(); ++i)
            printf("%s %d\n", out[i].fi.c_str(), out[i].se);
    }

    return 0;
}
