#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

#define NMAX 20
#define MMAX 110

int n, m;
char g[NMAX][MMAX];
int sum[NMAX], last_row;
int right_on[NMAX], left_on[NMAX];

int solve(int i, int j) {
    if (i == last_row) {
        if (sum[i] == 0) return 0;

        if (j == 0) {
            return right_on[i];
        } else {
            return m - 1 - left_on[i];
        }
    }

    if (sum[i] == 0) return 1 + solve(i + 1, j);

    if (j == 0) {
        return 1 + min(m - 1 + solve(i + 1, m - 1),
                      right_on[i] * 2 + solve(i + 1, 0));
    } else {
        return 1 + min(m - 1 + solve(i + 1, 0),
                      (m - 1 - left_on[i]) * 2 + solve(i + 1, m - 1));
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = n - 1; i >= 0; --i) scanf(" %s ", g[i]);
    m += 2;

    last_row = 0;
    for (int i = 0; i < n; ++i) {
        sum[i] = 0;
        for (int j = 0; j < m; ++j) sum[i] += g[i][j] - '0';
        if (sum[i] != 0) last_row = i;

        right_on[i] = -1;
        for (int j = m - 1; j >= 0; --j) {
            if (g[i][j] != '0') {
                right_on[i] = j;
                break;
            }
        }

        left_on[i] = -1;
        for (int j = 0; j < m; ++j) {
            if (g[i][j] != '0') {
                left_on[i] = j;
                break;
            }
        }

        // printf("i=%d, left_on=%d, right_on=%d, g[i]=%s\n", i, left_on[i], right_on[i], g[i]);
    }

    // printf("last_row=%d\n", last_row);

    printf("%d\n", solve(0, 0));

    return 0;
}
