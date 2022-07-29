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
        int a00, a01, a10, a11;
        scanf("%d %d %d %d", &a00, &a01, &a10, &a11);
        int out = 2;
        if ((a00 == 0) && (a01 == 0) && (a10 == 0) && (a11 == 0)) {
            out = 0;
        } else if ((a00 == 0) || (a01 == 0) || (a10 == 0) || (a11 == 0)) {
            out = 1;
        }
        printf("%d\n", out);
    }

    return 0;
}