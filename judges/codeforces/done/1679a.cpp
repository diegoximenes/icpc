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

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        if (n & 1) {
            cout << -1 << endl;
            continue;
        }

        n /= 2LL;
        if (n == 1) {
            cout << -1 << endl;
            continue;
        }

        ll x;
        if (n % 3 == 0) {
            x = n / 3;
        } else if (n % 3 == 1) {
            x = 2 + (n - 4) / 3;
        } else {
            // n % 3 == 2
            x = (n - 2) / 3 + 1;
        }

        ll y;
        if (n % 2 == 0) {
            y = n / 2;
        } else {
            y = 1 + (n - 3) / 2;
        }

        cout << x << " " << y << endl;
    }

    return 0;
}
