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

#define MAX 105
#define MOD 1000000007
#define OFFSET 50

int n;
int v[MAX], dp[MAX][MAX][MAX][MAX];

int opt(int i, int c1, int c2, int c3) {
    if (i == MAX - 1) return 1;
    int &ret = dp[i][c1 + OFFSET][c2 + OFFSET][c3 + OFFSET];
    if (ret != -1) return ret;

    ret = opt(i + 1, c2, c3, 0);
    if (v[i] + c1 > 0 && v[i + 1] + c2 > 0)
        ret = (ret + opt(i, c1 - 1, c2 - 1, c3 + 1)) % MOD;

    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(v, 0, sizeof(v));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &v[i]);

        memset(dp, -1, sizeof(dp));
        printf("%d\n", opt(0, 0, 0, 0));
    }

    return 0;
}
