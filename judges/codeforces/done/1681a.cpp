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
        int n, m;
        int a_max = -1, b_max = -1;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            a_max = max(a, a_max);
        }
        scanf("%d", &m);
        for (int i = 0; i < m; ++i) {
            int b;
            scanf("%d", &b);
            b_max = max(b, b_max);
        }

        if (a_max >= b_max) {
            printf("Alice\n");
        } else {
            printf("Bob\n");
        }

        if (b_max >= a_max) {
            printf("Bob\n");
        } else {
            printf("Alice\n");
        }
    }

    return 0;
}
