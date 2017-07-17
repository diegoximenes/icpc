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
    int t;
    cin >> t;
    while (t--) {
        int n, b;
        cin >> n >> b;

        ll sol;
        if (b >= n) {
            sol = 0;
        } else if (n / b == 1) {
            sol = n % b;
        } else {
            ll x = n / 2;
            sol = (x + ((n - x) % b)) * ((n - x) / b);

            if (b >= (n - x) % b) {
                x -= b - (n - x) % b;
                sol = max(sol, x * (n - x) / b);
            }
        }

        cout << sol << endl;
    }

    return 0;
}
