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
    int n, k;
    scanf("%d %d", &n, &k);
    int sol = INF;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        if (a <= k && k % a == 0) {
            sol = min(sol, k / a);
        }
    }
    printf("%d\n", sol);

    return 0;
}
