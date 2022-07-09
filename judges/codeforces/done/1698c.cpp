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

int a[MAX];

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int len = 0;
        int cnt_positive = 0, cnt_negative = 0, cnt_zero = 0;
        unordered_set<ll> has;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x > 0) {
                cnt_positive++;
                if (cnt_positive < 3) {
                    has.insert(x);
                    a[len++] = x;
                }
            } else if (x < 0) {
                cnt_negative++;
                if (cnt_negative < 3) {
                    has.insert(x);
                    a[len++] = x;
                }
            } else {
                cnt_zero++;
                if (cnt_zero < 3) {
                    has.insert(x);
                    a[len++] = x;
                }
            }
        }

        if ((cnt_positive >= 3) || (cnt_negative >= 3)) {
            printf("NO\n");
        } else {
            bool solved = 0;
            for (int i = 0; i < len; ++i) {
                for (int j = 0; j < len; ++j) {
                    for (int k = 0; k < len; ++k) {
                        if (i == j || i == k || j == k) {
                            continue;
                        }
                        if (!solved && has.find(a[i] + a[j] + a[k]) == has.end()) {
                            solved = 1;
                            printf("NO\n");
                        }
                    }
                }
            }

            if (!solved) {
                printf("YES\n");
            }
        }
    }

    return 0;
}
