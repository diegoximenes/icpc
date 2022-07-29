#include <bits/stdc++.h>
#include <cmath>
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

#define MAX 100000

int n;
ll h[MAX];
ll dp[MAX][2];

ll opt(int i, int used_gap_2) {
    if (i >= n - 1) {
        return 0;
    }
    ll &ret = dp[i][used_gap_2];
    if (ret != -1) {
        return ret;
    }

    ll ret1 = INFLL, ret2;
    if (!used_gap_2) {
        ret1 = opt(i + 1, 1);
    }

    ret2 = 0;
    if (h[i] <= h[i - 1] || h[i] <= h[i + 1]) {
        ret2 = max(h[i - 1], h[i + 1]) - h[i] + 1;
    }
    ret2 += opt(i + 2, used_gap_2);

    return ret = min(ret1, ret2);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }

        ll out = 0;
        if (n & 1) {
            for (int i = 1; i < n - 1; i += 2) {
                if (h[i] > h[i - 1] && h[i] > h[i + 1]) {
                    continue;
                }
                out += max(h[i - 1], h[i + 1]) - h[i] + 1;
            }
        } else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 2; ++j) {
                    dp[i][j] = -1;
                }
            }
            out = opt(1, 0);
        }
        cout << out << endl;
    }

    return 0;
}
