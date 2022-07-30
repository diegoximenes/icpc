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
    scanf("%d", &t);
    while (t--) {
        ll n, m;
        scanf("%lld %lld", &n, &m);

        ll maxi = -1, best_a, best_b;
        for (ll a = n; a <= min(m, 2 * n - 1); ++a) {
            ll b = m / a * a;
            if (b - a > maxi) {
                maxi = b - a;
                best_a = a;
                best_b = b;
            }
        }
        printf("%lld %lld\n", best_a, best_b);
    }

    return 0;
}
