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

#define MAX 100

int a[MAX];

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
            int x = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    x ^= a[j];
                }
            }
            if (x == a[i]) {
                printf("%d\n", x);
                break;
            }
        }
    }

    return 0;
}
