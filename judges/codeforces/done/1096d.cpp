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

#define MAX 100005

int n;
ll dp[2][5], a[MAX];
string s;
string hard = "hard";

int main() {
    fast_io;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i <= 2; ++i) {
        dp[i & 1][4] = INFLL;
    }
    for (int j = 0; j <= 3; ++j) {
        dp[n & 1][j] = 0;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < 4; ++j) {
            ll &ret = dp[i & 1][j];
            if (s[i] == hard[j]) {
                ret = min(dp[(i + 1) & 1][j + 1], a[i] + dp[(i + 1) & 1][j]);
            } else {
                ret = dp[(i + 1) & 1][j];
            }
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}
