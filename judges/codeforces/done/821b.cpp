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

int main() {
    ll m, b;
    cin >> m >> b;

    ll sol = 0;
    ll x = 0;
    while (1) {
        if (-x + b * m < 0) break;
        ll y = (-x + b * m) / m;

        ll lsol = (y + 1) * (0 + x) * (x + 1) / 2;
        lsol += (x + 1) * (0 + y) * (y + 1) / 2;

        // cout << "x=" << x << ", y=" << y << ", lsol=" << lsol << endl;

        sol = max(sol, lsol);
        x++;
    }

    cout << sol << endl;

    return 0;
}
