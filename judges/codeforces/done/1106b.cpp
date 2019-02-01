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

#define MAX 100005

int n, m;
pair<ll, int> v[MAX];
ll a[MAX], c[MAX];

int main() {
    fast_io;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        v[i].fi = c[i];
        v[i].se = i;
    }

    sort(v, v + n);
    int l = 0;
    for (int i = 0; i < m; ++i) {
        int t;
        ll d;
        cin >> t >> d;
        --t;

        ll cost = 0;
        if (d <= a[t]) {
            a[t] -= d;
            cost = c[t] * d;
        } else {
            cost = c[t] * a[t];
            d -= a[t];
            a[t] = 0;
            while (d && l < n) {
                ll mind = min(d, a[v[l].se]);
                cost += c[v[l].se] * mind;
                d -= mind;
                a[v[l].se] -= mind;
                if (a[v[l].se] == 0) {
                    l++;
                }
            }

            if (d) {
                cost = 0;
            }
        }

        cout << cost << endl;
    }

    return 0;
}
