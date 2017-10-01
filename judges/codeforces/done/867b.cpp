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

#define MMAX 10
#define NMAX 1000000
#define AMAX 100000

int dp_n[AMAX + 5], dp_m[AMAX + 5];
int dp[NMAX + 5][MMAX + 5];
bool can[NMAX + 5][MMAX + 5];
int d[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
    memset(dp, 0, sizeof(dp));
    memset(can, 0, sizeof(can));
    for (int j = 0; j < MMAX; ++j) {
        dp[0][j] = 1;
        can[0][j] = 1;
    }

    for (int i = 1; i <= NMAX; ++i) {
        for (int j = 0; j < MMAX; ++j) {
            dp[i][j] = 0;
            can[i][j] = 1;

            if (j > 0) {
                if (can[i][j - 1]) {
                    dp[i][j] += dp[i][j - 1];
                } else {
                    can[i][j] = 0;
                }
            }

            if (i - d[j] >= 0) {
                if (can[i - d[j]][j]) {
                    dp[i][j] += dp[i - d[j]][j];
                } else {
                    can[i][j] = 0;
                }
            }

            if (dp[i][j] > AMAX) can[i][j] = 0;

            if (can[i][j]) {
                dp_m[dp[i][j]] = j + 1;
                dp_n[dp[i][j]] = i;
            }
        }
    }

    int a;
    scanf("%d", &a);
    printf("%d %d\n", dp_n[a], dp_m[a]);
    printf("%d", d[0]);
    for (int i = 1; i < dp_m[a]; ++i) printf(" %d", d[i]);
    puts("");

    return 0;
}
