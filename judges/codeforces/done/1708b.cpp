#include <bits/stdc++.h>
#include <cmath>
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

#define MAX 100000

int out[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, l, r;
        scanf("%d %d %d", &n, &l, &r);

        bool can = 1;
        for (int i = 1; i <= n; ++i) {
            out[i] = ((l / i) + (l % i != 0)) * i ;
            if (out[i] > r) {
                can = 0;
            }
        }

        if (can) {
            printf("YES\n%d", out[1]);
            for (int i = 2; i <= n; ++i) {
                printf(" %d", out[i]);
            }
            printf("\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
