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

ll a[MAX], b[MAX];

int main() {
    fast_io;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int i = 1, j = 1, sol = 0;
    ll acuma = a[0], acumb = b[0];
    while (i < n || j < m) {
        // cout << "i=" << i << ", j=" << j << ", acuma="  << acuma << ", acumb=" << acumb << endl;
        if (acuma > acumb) {
            if (j == m) {
                cout << -1 << endl;
                return 0;
            }
            acumb += b[j++];
        } else if (acuma < acumb) {
            if (i == n) {
                cout << -1 << endl;
                return 0;
            }
            acuma += a[i++];
        } else {
            acuma = a[i++];
            acumb = b[j++];
            sol++;
        }
    }

    if (i != n || j != m || acuma != acumb) {
        cout << -1 << endl;
    } else {
        cout << sol + 1 << endl;
    }

    return 0;
}
