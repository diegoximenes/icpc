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

ll dp[3][3][5][25];
int l[25], r[25];

ll opt(int largerThanL, int smallerThanR, int cntNonZero, int i) {
    if (cntNonZero > 3) return 0;
    if (i == -1) return 1;
    ll &ret = dp[largerThanL][smallerThanR][cntNonZero][i];
    if (ret != -1) return ret;

    ret = 0;
    int lo = 0, hi = 9;
    if (!largerThanL) {
        lo = l[i];
    }
    if (!smallerThanR) {
        hi = r[i];
    }
    for (int d = lo; d <= hi; ++d) {
        int newLargertThanL = largerThanL || (d > l[i]);
        int newSmallerThanR = smallerThanR || (d < r[i]);
        int newCntNonZero = cntNonZero + (d > 0);
        ret += opt(newLargertThanL, newSmallerThanR, newCntNonZero, i - 1);
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll sl, sr;
        cin >> sl >> sr;
        for (int i = 0; i < 20; ++i) {
            l[i] = sl % 10;
            r[i] = sr % 10;
            sl /= 10;
            sr /= 10;
        }
        memset(dp, -1, sizeof(dp));
        cout << opt(0, 0, 0, 19) << endl;
    }

    return 0;
}
