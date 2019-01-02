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
    fast_io;
    ll n;
    cin >> n;

    set<ll> out;
    set<ll>::iterator it;
    for (ll i = sqrt(n) + 1; i >= 1; --i) {
        if (n % i == 0) {
            ll div = i;
            out.insert((1LL + (n - (div - 1))) * (n / div) / 2LL);
            div = n / i;
            out.insert((1LL + (n - (div - 1))) * (n / div) / 2LL);
        }
    }

    bool printed = 0;
    for (it = out.begin(); it != out.end(); ++it) {
        if (printed) {
            cout << " ";
        }
        cout << *it;
        printed = 1;
    }
    cout << endl;

    return 0;
}
