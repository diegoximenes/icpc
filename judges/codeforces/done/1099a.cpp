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
    int w, h, u1, d1, u2, d2;
    scanf("%d %d %d %d %d %d", &w, &h, &u1, &d1, &u2, &d2);

    for (int i = h; i >=0; --i) {
        w += i;
        if (i == d1) {
            w -= u1;
        } else if (i == d2) {
            w -= u2;
        }
        w = max(w, 0);
    }
    printf("%d\n", w);

    return 0;
}
