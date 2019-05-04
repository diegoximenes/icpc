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

int g1[MAX][MAX], g2[MAX][MAX];

void read_mat(int g[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &g[i][j]);
        }
    }
}

bool check(int g[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i < n - 1 && g[i][j] >= g[i + 1][j]) {
                return 0;
            }
            if (j < m - 1 && g[i][j] >= g[i][j + 1]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    read_mat(g1, n, m);
    read_mat(g2, n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x1 = g1[i][j];
            int x2 = g2[i][j];
            g1[i][j] = min(x1, x2);
            g2[i][j] = max(x1, x2);
        }
    }

    bool possible = check(g1, n, m) && check(g2, n, m);
    puts(possible ? "Possible" : "Impossible");

    return 0;
}
