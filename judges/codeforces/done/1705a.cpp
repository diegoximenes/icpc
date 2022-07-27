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

#define MAX 200

int h[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        scanf("%d %d", &n, &x);
        for (int i = 0; i < 2 * n; ++i) {
            scanf("%d", &h[i]);
        }
        sort(h, h + 2 * n);

        bool can = 1;
        for (int i = 0; i < n; ++i) {
            if (h[i + n] - h[i] < x) {
                can = 0;
            }
        }
        printf("%s\n", can ? "YES" : "NO");
    }

    return 0;
}
