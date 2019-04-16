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
    int n;
    scanf("%d", &n);

    int p = 1, d = 0;
    while (p <= n) {
        d++;
        int max_p = p;
        for (; p <= max_p; ++p) {
            int a;
            scanf("%d", &a);
            max_p = max(max_p, a);
        }
    }

    printf("%d\n", d);

    return 0;
}
