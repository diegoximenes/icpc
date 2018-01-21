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

#define MAX 1000000

int main() {
    set<ll> perfect_squares;
    for (ll i = 0; i <= MAX; ++i) {
        perfect_squares.insert(i * i);
    }

    int n;
    ll sol = -INFLL;
    cin >> n;
    while (n--) {
        ll x;
        cin >> x;
        if (perfect_squares.find(x) == perfect_squares.end()) {
            sol = max(sol, x);
        }
    }
    cout << sol << endl;

    return 0;
}
