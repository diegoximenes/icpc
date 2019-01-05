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

#define MAX 16
#define MAXANG 365

int n;
int dp[MAX][MAXANG], a[MAX];

int opt(int i, int ang) {
    if (i == n) {
        return (ang == 0);
    }
    int &ret = dp[i][ang];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    int ang1 = (ang + a[i]) % 360;
    ret = max(ret, opt(i + 1, ang1));
    int ang2 = (ang - a[i]) % 360;
    if (ang2 < 0) {
        ang2 += 360;
    }
    ret = max(ret, opt(i + 1, ang2));
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    memset(dp, -1, sizeof(dp));
    if (opt(0, 0)) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}
