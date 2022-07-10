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

#define MAX 200000

ll a[MAX], curr[MAX];

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            curr[i] = 0;
        }

        while (a[n - 1] == 0 && n > 1) {
            n--;
        }

        string out = "Yes";

        if (n == 1) {
            if (a[0] != 0) {
                out = "No";
            }
        } else if (a[0] <= 0) {
            out = "No";
        } else {
            curr[1] = -(a[0] - 1);
            for (int i = 1; i < n - 1; ++i) {
                if (curr[i] > a[i]) {
                    out = "No";
                    break;
                }
                if (i + 1 < n) {
                    curr[i + 1] -= a[i] - curr[i];
                }
            }
            if (curr[n - 1] != a[n - 1] + 1) {
                out = "No";
            }
        }

        cout << out << endl;
    }

    return 0;
}
