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

/*
 * min (x + y)
 * s.t.:
 * 2*x + y >= a
 * x + 2*y >= b
 *
 * x + y = k -> y = k - x -> x = k - y
 *
 * 2*x + k - x >= a -> x >= a - k
 * 2*k - 2*y + y >= a -> y <= 2*k - a
 *
 * x + 2*k - 2*x >= b -> x <= 2*k - b
 * y >= b - k
 */

#define MAX 200005

int a[MAX];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int sol = INF;
    for (int i = 1; i < n; ++i) {
        int l = 1, r = 1000000;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            bool can = 0;
            if (i <= n - 2) {
                int min_a = min(a[i - 1], a[i + 1]);
                int max_a = max(a[i - 1], a[i + 1]);
                if (min_a + (max_a - min_a) / 2 + (max_a - min_a) % 2 <= mid) {
                    can = 1;
                }
            }
            int x = max(a[i - 1] - mid, 0);
            int y = max(mid - x, 0);
            if ((x + y <= mid) && (2 * x + y >= a[i - 1]) && (x + 2 * y >= a[i])) {
                can = 1;
            }

            if (can) {
                r = mid - 1;
                sol = min(sol, mid);
            } else {
                l = mid + 1;
            }
        }
    }

    sort(a, a + n);
    sol = min(sol, a[0] / 2 + a[0] % 2 + a[1] / 2 + a[1] % 2);

    printf("%d\n", sol);

    return 0;
}
