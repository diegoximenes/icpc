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

ll a[MAX];

int main() {
    fast_io;

    int n, m;
    ll l;

    cin >> n >> m >> l;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int cnt_segs = 0;
    if (a[0] > l) {
        cnt_segs = 1;
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] > l) {
            if (a[i - 1] <= l) {
                cnt_segs++;
            }
        }
    }

    while (m--) {
        int op;
        cin >> op;
        if (op) {
            int p;
            ll d;
            cin >> p >> d;
            p--;

            if (a[p] > l) {
                a[p] += d;
            } else {
                a[p] += d;
                if (a[p] > l) {
                    bool joined = 0;
                    if (p > 0) {
                        if (a[p - 1] > l) {
                            joined = 1;
                        }
                    }
                    if (p < n - 1) {
                        if (a[p + 1] > l) {
                            if (joined) {
                                cnt_segs--;
                            }
                            joined = 1;
                        }
                    }
                    if (!joined) {
                        cnt_segs++;
                    }
                }
            }
        } else {
            cout << cnt_segs << endl;
        }
    }

    return 0;
}
