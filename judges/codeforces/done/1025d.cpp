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

#define MAX 705

int gcd (int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int n, a[MAX];
int dp[2][MAX][MAX];

int opt(int root, int l, int r) {
    if (l > r) return 1;
    int dad;
    if (root) {
        dad = r + 1;
    } else {
        dad = l - 1;
    }

    int &ret = dp[root][l][r];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = l; i <= r; ++i) {
        if (l == 0 && r == n - 1) {
            dad = i;
        }
        if (gcd(a[i], a[dad]) > 1) {
            ret = ret || (opt(1, l, i - 1) && opt(0, i + 1, r));
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    memset(dp, -1, sizeof(dp));
    puts(opt(0, 0, n - 1) == 0 ? "No" : "Yes");

    return 0;
}
