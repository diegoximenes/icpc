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

const int MOD = 998244353LL;

#define MAX 505

int n, k;
int dp1[2][MAX][MAX], dp2[2][MAX][MAX];

int main() {
    scanf("%d %d", &n, &k);

    for (int curr_same_rows = 1; curr_same_rows < MAX; ++curr_same_rows) {
        for (int max_same_cols = 1; max_same_cols < MAX; ++max_same_cols) {
            int &ret = dp2[n & 1][curr_same_rows][max_same_cols];
            if (curr_same_rows * max_same_cols >= k) {
                ret = 0;
            } else {
                ret = 1;
            }
        }
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int curr_same_rows = 1; curr_same_rows < MAX - 1; ++curr_same_rows) {
            for (int max_same_cols = 1; max_same_cols < MAX - 1; ++max_same_cols) {
                int &ret = dp2[i & 1][curr_same_rows][max_same_cols];
                if (curr_same_rows * max_same_cols >= k) {
                    ret = 0;
                } else {
                    ret = (dp2[(i + 1) & 1][curr_same_rows + 1][max_same_cols] +
                           dp2[(i + 1) & 1][1][max_same_cols]) % MOD;
                }
            }
        }
    }

    for (int curr_same = 0; curr_same < MAX; ++curr_same) {
        for (int max_same = 0; max_same < MAX; ++max_same) {
            int &ret = dp1[n & 1][curr_same][max_same];
            if (max_same >= k) {
                ret = 0;
            } else {
                ret = dp2[1][1][max_same];
            }
        }
    }
    for (int j = n - 1; j >= 0; --j) {
        for (int curr_same = 0; curr_same < MAX -1; ++curr_same) {
            for (int max_same = 0; max_same < MAX - 1; ++max_same) {
                int &ret = dp1[j & 1][curr_same][max_same];
                if (max_same >= k) {
                    ret = 0;
                } else {
                    ret = (dp1[(j + 1) & 1][curr_same + 1][max(max_same, curr_same + 1)] +
                           dp1[(j + 1) & 1][1][max(max_same, 1)]) % MOD;
                }
            }
        }
    }

    cout << dp1[0][0][0] << endl;

    return 0;
}
