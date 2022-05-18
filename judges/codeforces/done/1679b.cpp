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

#define MAX 200005

int main() {
    ll n, q, sum = 0;
    unordered_map<int, ll> a;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        a[i] = x;
        sum += a[i];
    }

    ll last;
    while (q--) {
        ll t, i, x;
        cin >> t;
        if (t == 1) {
            cin >> i >> x;

            if (a.find(i) == a.end()) {
                sum -= last;
            } else {
                sum -= a[i];
            }
            a[i] = x;
            sum += x;
        } else {
            cin >> x;
            sum = n * x;
            last = x;
            a = unordered_map<int, ll>();
        }

        cout << sum << endl;
    }

    return 0;
}
