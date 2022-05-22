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

#define MAX 10

char g[MAX][MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%s", g[i]);
        }

        bool can = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 'R') {
                    bool can_i_j = 1;
                    for (int i2 = 0; i2 < n; ++i2) {
                        for (int j2 = 0; j2 < m; ++j2) {
                            if (i == i2 && j == j2) {
                                continue;
                            }
                            if (g[i2][j2] == 'R' && (i2 - (i - 1) <= 0 || j2 - (j - 1) <= 0)) {
                                can_i_j = 0;
                            }
                        }
                    }
                    if (can_i_j) {
                        can = 1;
                    }
                }
            }
        }
        printf("%s\n", can ? "YES" : "NO");
    }

    return 0;
}
