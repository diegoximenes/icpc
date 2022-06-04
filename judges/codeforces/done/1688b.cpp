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
        int n;
        scanf("%d", &n);
        int cnt_odd = 0, min_div_ops = INF;
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            if (a & 1) {
                cnt_odd++;
            } else {
                int div_ops = 0;
                while (a % 2 == 0) {
                    div_ops++;
                    a /= 2;
                }
                min_div_ops = min(div_ops, min_div_ops);
            }
        }

        int out = 0;
        if (cnt_odd == 0) {
            out = min_div_ops + n - 1;
        } else {
            out = n - cnt_odd;
        }

        printf("%d\n", out);
    }

    return 0;
}
