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

int a[MAX], out[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        bool can = 1;
        int l = 0;
        while (l < n) {
            int r;
            for (r = l; (r < n) && (a[r] == a[l]); r++);

            if (r - l == 1) {
                can = 0;
            }

            for (int i = l; i < r - 1; ++i) {
                out[i] = i + 1;
            }
            out[r - 1] = l;

            l = r;
        }

        if (can) {
            printf("%d", out[0] + 1);
            for (int i = 1; i < n; ++i) {
                printf(" %d", out[i] + 1);
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
    }

    return 0;
}
