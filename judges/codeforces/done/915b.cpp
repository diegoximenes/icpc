#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
const double PI = acos(-1);
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main() {
    int n, pos, l, r;
    scanf("%d %d %d %d", &n, &pos, &l, &r);

    int sol = 0;
    if (abs(r - pos) < abs(pos - l)) {
        if (r != n) {
            sol += abs(pos - r) + 1;
            pos = r;
        }
        if (l != 1) {
            sol += abs(pos - l) + 1;
        }
    } else {
        if (l != 1) {
            sol += abs(pos - l) + 1;
            pos = l;
        }
        if (r != n) {
            sol += abs(pos - r) + 1;
        }
    }

    printf("%d\n", sol);

    return 0;
}