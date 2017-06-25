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

#define MAX 55

int g[MAX][MAX];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &g[i][j]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] != 1) {
                bool can = 0;
                for (int i2 = 0; i2 < n; ++i2) {
                    for (int j2 = 0; j2 < n; ++j2) {
                        if (g[i][j2] + g[i2][j] == g[i][j])
                            can = 1;
                    }
                }
                if (!can) {
                    puts("No");
                    return 0;
                }
            }
        }
    }

    puts("Yes");

    return 0;
}
