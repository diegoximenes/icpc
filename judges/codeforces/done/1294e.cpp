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

#define MAX 200005

int g[MAX];
int count_shift[MAX];

inline int ind(int i, int j, int m) {
    return (i - 1) * m + j;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &g[ind(i, j, m)]);
        }
    }

    int sol = 0;
    for (int j = 1; j <= m; ++j) {
        for (int i = 0; i <= n; ++i) {
            count_shift[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            if ((g[ind(i, j, m)] <= n * m) && ((g[ind(i, j, m)] % m == j) || (g[ind(i, j, m)] % m == 0 && j == m))) {
                int correct_i = (g[ind(i, j, m)] - j) / m + 1;
                int shift = 0;
                if (correct_i <= i) {
                    shift = i - correct_i;
                } else {
                    shift = i + n - correct_i;
                }
                count_shift[shift]++;
            }
        }

        int col_sol = INF;
        for (int shift = 0; shift <= n - 1; ++shift) {
            col_sol = min(col_sol, shift + (n - count_shift[shift]));
        }
        sol += col_sol;
    }
    printf("%d\n", sol);

    return 0;
}
