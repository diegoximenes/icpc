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
        int x, y, n, r;
        scanf("%d %d %d %d", &x, &y, &n, &r);
        if (r / x < n) {
            printf("-1\n");
        } else {
            /*
             * a * x + b * y <= r
             * a + b = n
             * a >= 0
             * b >= 0
             *
             *
             * (n - b) * x + b * y <= r
             * n * x - b * x + b * y <= r
             * b * (y - x) <= r - n * x
             * b <= (r - n * x) / (y - x)
             */

            int cnt_expensive = (r - n * x) / (y - x);
            int cnt_cheap = n - cnt_expensive;
            if (cnt_cheap < 0) {
                cnt_cheap = 0;
                cnt_expensive = n;
            }

            printf("%d %d\n", cnt_cheap, cnt_expensive);
        }
    }

    return 0;
}
