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

#define MAX 50001

int a[MAX], b[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
        }

        int min_delta = INF, max_delta = -INF;
        for (int i = 0; i < n; ++i) {
            max_delta = max(max_delta, a[i] - b[i]);
            if (b[i] != 0) {
                min_delta = min(min_delta, a[i] - b[i]);
            }
        }

        if ((min_delta >= 0) && ((max_delta == min_delta) || (min_delta == INF))) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
