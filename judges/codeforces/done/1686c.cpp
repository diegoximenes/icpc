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

#define MAX 100001

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

        if (n & 1) {
            printf("NO\n");
        } else {
            sort(a, a + n);
            int r = n - 1;
            for (int i = 0; i < n; i += 2) {
                b[i] = a[r--];
            }
            for (int i = 1; i < n; i += 2) {
                b[i] = a[r--];
            }

            bool can = 1;
            for (int i = 0; i < n; ++i) {
                if (((b[i] >= b[(i + 1) % n]) && (b[i] <= b[(i - 1) % n])) ||
                    ((b[i] <= b[(i + 1) % n]) && (b[i] >= b[(i - 1) % n]))) {
                    can = 0;
                }
            }

            if (can) {
                printf("YES\n%d", b[0]);
                for (int i = 1; i < n; ++i) {
                    printf(" %d", b[i]);
                }
                printf("\n");
            } else {
                printf("NO\n");
            }
        }

    }

    return 0;
}
