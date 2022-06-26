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

#define MAX 200001

int n;
int a[MAX];
bool is_up_eq_to_the_right[MAX];

ll solve() {
    for (int i = 0; i < n; ++i) {
        is_up_eq_to_the_right[i] = 0;
    }
    is_up_eq_to_the_right[n] = is_up_eq_to_the_right[n - 1] = 1;
    for (int i = n - 2; i >= 0; ++i) {
        if (a[i] <= a[i + 1]) {
            is_up_eq_to_the_right[i] = 1;
            break;
        }
    }
    ll out1 = 0, decreased = 0;
    for (int i = 1; i <= n - 1; ++i) {
        if (a[i] > a[i - 1]) {
            decreased += a[i] - a[i - 1];
        } else {
            out1 += a[i - 1] - a[i];
        }
        if (i == n - 1) {
            if (a[n - 1] - decreased < 0) {
                out1 += -(a[n - 1] - decreased);
            } else {
                out1 += a[n - 1] - decreased;
            }
        } else if (is_up_eq_to_the_right[i]) {
            for (int j = n - 2; j >= i; --j) {
                out1 += a[j + 1] - a[j];
            }
            if (a[i] - decreased < 0) {
                out1 += -(a[i] - decreased);
            } else {
                out1 += a[i] - decreased;
            }
            break;
        }
    }
    if (n == 1) {
        out1 = INFLL;
    }
    out1 += decreased;


    ll out2 = 0;
    decreased = 0;
    for (int i = 1; i <= n - 1; ++i) {
        if (a[i] > a[i - 1]) {
            decreased += a[i] - a[i - 1];
        } else {
            out2 += a[i - 1] - a[i];
        }
    }
    out2 += decreased;
    if (a[n - 1] - decreased < 0)  {
        out2 += -(a[n - 1] - decreased);
    } else {
        out2 += a[n - 1] - decreased;
    }

    return min(out1, out2);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll out1 = solve();
        reverse(a, a + n);
        ll out2 = solve();
        cout << min(out1, out2) << endl;
    }

    return 0;
}
