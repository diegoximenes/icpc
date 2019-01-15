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

#define MAX 200005

int n, m;
pair<int, int> a[MAX], b[MAX];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i].fi);
        a[i].se = i;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i].fi);
        b[i].se = i;
    }

    sort(a, a + n);
    sort(b, b + m);

    for (int i = 0; i < m; ++i) {
        printf("%d %d\n", a[0].se, b[i].se);
    }
    for (int i = 1; i < n; ++i) {
        printf("%d %d\n", a[i].se, b[m - 1].se);
    }

    return 0;
}
