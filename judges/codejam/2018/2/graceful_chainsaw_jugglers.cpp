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

#define MAX1 33
#define MAX2 505

short dp[MAX1][MAX1][MAX2][MAX2];

// int opt(int i, int j, int r, int b) {
//     if (j == MAX1) {
//         j = 0;
//         i++;
//     }
//     if (i == MAX1) {
//         return 0;
//     }
//     int &ret = dp[i][j][r][b];
//     if (ret != -1) {
//         return ret;
//     }
//
//     ret = 0;
//     ret = max(ret, opt(i, j + 1, r, b));
//     if (r - i >= 0 && b - j >= 0) {
//         ret = max(ret, 1 + opt(i, j + 1, r - i, b - j));
//     }
//     return ret;
// }

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        int r, b;
        scanf("%d %d", &r, &b);

        for (int j = 0; j < MAX1; ++j) {
            for (int curr_r = 0; curr_r <= r; ++curr_r) {
                for (int curr_b = 0; curr_b <= b; ++curr_b) {
                    dp[MAX1 - 1][j][curr_r][curr_b] = 0;
                }
            }
        }
        for (int i = MAX1 - 2; i >= 0; --i) {
            for (int j = MAX1 - 2; j >= 0; --j) {
                for (int curr_r = 0; curr_r <= r; ++curr_r) {
                    for (int curr_b = 0; curr_b <= b; ++curr_b) {
                        short &ret = dp[i][j][curr_r][curr_b];

                        int next_r = curr_r - i;
                        int next_b = curr_b - j;
                        int next_j = j + 1;
                        int next_i = i;
                        if (next_j == MAX1 - 1) {
                            next_i = i + 1;
                            next_j = 0;
                        }
                        ret = dp[next_i][next_j][curr_r][curr_b];
                        if (next_r >= 0 && next_b >= 0) {
                            if (1 + dp[next_i][next_j][next_r][next_b] > ret) {
                                ret = 1 + dp[next_i][next_j][next_r][next_b];
                            }
                        }
                    }
                }
            }
        }

        // memset(dp, -1, sizeof(dp));
        // int sol = opt(0, 1, r, b);
        int sol = dp[0][1][r][b];

        printf("Case #%d: %d\n", tc, sol);
    }

    return 0;
}
