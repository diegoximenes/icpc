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

#define MAX 2005
#define MOD 998244353LL

int n, k;
ll m;
ll dp[MAX][MAX];

ll opt(int i, int diff) {
    if (i == n) {
        return (diff == k);
    }
    ll &ret = dp[i][diff];
    if (ret != -1) {
        return ret;
    }

    ret = opt(i + 1, diff);
    ret = (ret + ((m - 1) * opt(i + 1, diff + 1)) % MOD) % MOD;

    return ret;
}

int main() {
    fast_io;
    cin >> n >> m >> k;

    memset(dp, -1, sizeof(dp));
    cout << (m * opt(1, 0)) % MOD << endl;

    return 0;
}
