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

#define MAX 55

int max_h[MAX];

int main() {
    ll n, h, m;
    cin >> n >> h >> m;
    for (int i = 1; i <= n; ++i) {
        max_h[i] = h;
    }
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        for (int i = l; i <= r; ++i) {
            max_h[i] = min(max_h[i], x);
        }
    }

    ll sol = 0;
    for (int i = 1; i <= n; ++i) {
        sol += max_h[i] * max_h[i];
    }
    cout << sol << endl;

    return 0;
}
