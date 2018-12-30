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

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}
ll lcm(ll a, ll b) {
    return a * (b / gcd(a, b));
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        ll a;
        cin >> a;

        ll l = lcm(180, a);
        for (ll i = 1; ; ++i) {
            ll x = i * l / 180LL;
            ll n = 180LL * x / a;

            // cout << "l= " << l << endl;
            // cout << "x= " << x << endl;
            // cout << "n= " << n << endl;
            if (x <= n - 2) {
                cout << n << endl;
                break;
            } else if (n > 998244353LL) {
                cout << "-1" << endl;
                break;
            }
        }
    }

    return 0;
}
