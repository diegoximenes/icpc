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

#define MAX 100002

ll sum_l[MAX], sum_r[MAX], a[MAX];

int main() {
    fast_io;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    sum_l[0] = sum_l[1] = 0;
    for (int i = 2; i <= n; ++i) {
        sum_l[i] = sum_l[i - 1] + max(0LL, -(a[i] - a[i - 1]));
    }
    sum_r[n + 1] = sum_r[n] = 0;
    for (int i = n - 1; i >= 1; --i) {
        sum_r[i] = sum_r[i + 1] + max(0LL, -(a[i] - a[i + 1]));
    }

    while (m--) {
        int s, t;
        cin >> s >> t;

        if (s <= t) {
            cout << sum_l[t] - sum_l[s] << endl;
        } else {
            cout << sum_r[t] - sum_r[s] << endl;
        }
    }

    return 0;
}
