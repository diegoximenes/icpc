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

#define MAX 100005
#define MOD 1000000007LL

ll fib[MAX];

int main() {
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i < MAX; ++i) {
        fib[i] = (fib[i - 2] + fib[i - 1]) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        ll m, n, sum_a = 0, sum_b = 0;
        cin >> m >> n;
        for (int i = 1; i <= m; ++i) {
            ll a;
            cin >> a;
            sum_a = (sum_a + a) % MOD;
        }
        for (int i = 1; i <= m; ++i) {
            ll b;
            cin >> b;
            sum_b = (sum_b + b) % MOD;
        }

        ll sol = 0;
        if (n == 1LL) {
            sol = (m * sum_a) % MOD;
        } else if (n == 2LL) {
            sol = (m * sum_b) % MOD;
        } else {
            ll x = (fib[n - 2] * sum_a) % MOD;
            ll y = (fib[n - 1] * sum_b) % MOD;
            sol = (x + y) % MOD;
            sol = (sol * m) % MOD;
        }
        cout << sol << endl;
    }

    return 0;
}
