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

#define MAX 100005
#define MAX2 100005
#define MAX3 41

int v[MAX];
int prod[MAX3], dp[MAX3][MAX2];
int a, b, h, w, n;

bool cmp(int a, int b) {
    return a > b;
}

int opt(int i, ll x, ll y) {
    x = min(x, (ll) MAX2 - 1);
    y = min(y, (ll) MAX2 - 1);
    if ((x >= a && y >= b) || (x >= b && y >= a)) return 0;
    if (i >= MAX3) return INF;

    int &ret = dp[i][x];
    if (ret != -1) return ret;

    ret = 1;
    if (x >= a && x >= b)
        ret += opt(i + 1, x, y * v[i]);
    else if (y >= a && y >= b)
        ret += opt(i + 1, x * v[i], y);
    else
        ret += min(opt(i + 1, x * v[i], y), opt(i + 1, x, y * v[i]));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    scanf("%d %d %d %d %d", &a, &b, &h, &w, &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);

    sort(v + 1, v + n + 1, cmp);
    memset(dp, -1, sizeof(dp));
    int sol = opt(1, h, w);
    printf("%d\n", (sol >= INF) ? -1 : sol);

    return 0;
}
