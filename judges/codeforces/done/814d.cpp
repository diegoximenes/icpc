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

#define MAX 1005

class Circle {
public:
    ll x, y, r;
    Circle(ll _x = 0, ll _y = 0, ll _r = 0) : x(_x), y(_y), r(_r) {}
    bool operator<(Circle &o) {
        if (r != o.r) return (r < o.r);
        if (x != o.x) return (x < o.x);
        return (x < o.y);
    }
};

bool in(Circle c1, Circle c2) {
    // for sure c2 is bigger
    ll d = (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
    if (d < c2.r * c2.r) return 1;
    return 0;
}

int n;
Circle v[MAX];
int dad[MAX];
vector<int> g[MAX];
ll dp[MAX][MAX];

ll opt(int u, int cnt_left, int cnt_right) {
    ll &ret = dp[u][cnt_left];
    if (ret != -1) return ret;
    ret = -INFLL;

    int new_cnt_left = cnt_left + 1;
    int new_cnt_right = cnt_right;
    ll lret = 0;
    if (new_cnt_left & 1)
        lret = v[u].r * v[u].r;
    else
        lret = - v[u].r * v[u].r;
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        lret += opt(v, new_cnt_left, new_cnt_right);
    }
    ret = max(ret, lret);

    new_cnt_left = cnt_left;
    new_cnt_right = cnt_right + 1;
    lret = 0;
    if (new_cnt_right & 1)
        lret = v[u].r * v[u].r;
    else
        lret = - v[u].r * v[u].r;
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        lret += opt(v, new_cnt_left, new_cnt_right);
    }
    ret = max(ret, lret);

    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x, y, r;
        scanf("%d %d %d", &x, &y, &r);
        v[i] = Circle(x, y, r);
    }

    sort(v, v + n);
    memset(dad, -1, sizeof(dad));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (in(v[i], v[j])) {
                dad[i] = j;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        if (dad[i] != -1)
            g[dad[i]].pb(i);

    memset(dp, -1, sizeof(dp));
    ll sol = 0;
    for (int i = 0; i < n; ++i)
        if (dad[i] == -1)
            sol += opt(i, 0, 0);

    printf("%.8lf\n", PI * sol);

    return 0;
}
