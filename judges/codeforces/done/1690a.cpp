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
 * n % 3 == 0:
 * n / 3, n / 3 + 1, n / 3 - 1
 *
 * n % 3 == 1:
 * n / 3, n / 3 + 2, n / 3 - 1
 *
 * n % 3 == 2:
 * n / 3 + 1, n / 3 + 2, n / 3 - 1
 */

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int h1 = n / 3, h2 = n / 3, h3 = n / 3;

        if (n % 3 == 0) {
            h1++;
            h3--;
        } else if (n % 3 == 1) {
            h1 += 2;
            h3--;
        } else {
            h2++;
            h1 += 2;
            h3--;
        }

        printf("%d %d %d\n", h2, h1, h3);
    }

    return 0;
}
