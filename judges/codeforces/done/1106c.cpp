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

#define MAX 300005

int n;
ll a[MAX];

int main() {
    fast_io;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll sol = 0;
    sort(a, a + n);
    for (int i = 0; i < n / 2; ++i) {
        ll x = a[i] + a[n - i - 1];
        sol += x * x;
    }

    cout << sol << endl;

    return 0;
}
