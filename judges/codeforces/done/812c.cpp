#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

#define MAX 100005

ll a[MAX], v[MAX];

int main() {
    ios::sync_with_stdio(false);

    int n;
    ll s;

    cin >> n >> s;
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll l = 0, r = n, k_sol = 0, cost_sol = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;

        for (int i = 0; i < n; ++i) v[i] = a[i] + (i + 1) * mid;
        sort(v, v + n);

        ll cost = 0;
        for (int i = 0; i < mid; ++i) cost += v[i];

        if (cost <= s) {
            k_sol = mid;
            cost_sol = cost;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << k_sol << " " << cost_sol << endl;

    return 0;
}
