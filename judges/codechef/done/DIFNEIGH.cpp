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

#define MAX 55

int g[MAX][MAX];

int main() {
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);

        int maxk = 0;

        if (n == 1) {
            for (int j = 0; j < m; ++j) {
                if ((j / 2) & 1) {
                    g[0][j] = 2;
                } else {
                    g[0][j] = 1;
                }
                maxk = max(maxk, g[0][j]);
            }
        } else if (m == 1) {
            for (int i = 0; i < n; ++i) {
                if ((i / 2) & 1) {
                    g[i][0] = 2;
                } else {
                    g[i][0] = 1;
                }
                maxk = max(maxk, g[i][0]);
            }
        } else if (n == 2) {
            for (int j = 0; j < m; ++j) {
                g[0][j] = g[1][j] = j % 3 + 1;
                maxk = max(maxk, g[0][j]);
            }
        } else if (m == 2) {
            for (int i = 0; i < n; ++i) {
                g[i][0] = g[i][1] = i % 3 + 1;
                maxk = max(maxk, g[i][0]);
            }
        } else {
            int curr_odd = 1, next_odd = 2;
            int curr_even = 3, next_even = 4;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (i & 1) {
                        if ((j / 2) & 1) {
                            g[i][j] = curr_odd;
                        } else {
                            g[i][j] = next_odd;
                        }
                    } else {
                        if ((j / 2) & 1) {
                            g[i][j] = curr_even;
                        } else {
                            g[i][j] = next_even;
                        }
                    }
                    maxk = max(maxk, g[i][j]);
                }
                if (i & 1) {
                    swap(curr_odd, next_odd);
                } else {
                    swap(curr_even, next_even);
                }
            }
        }

        printf("%d\n", maxk);
        for (int i = 0; i < n; ++i) {
            printf("%d", g[i][0]);
            for (int j = 1; j < m; ++j) {
                printf(" %d", g[i][j]);
            }
            puts("");
        }
    }

    return 0;
}
