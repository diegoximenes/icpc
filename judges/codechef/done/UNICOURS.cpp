#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
    ios::sync_with_stdio(false);

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        int sol = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            sol = max(sol, x);
        }
        sol = n - sol;

        printf("%d\n", sol);
    }

    return 0;
}
