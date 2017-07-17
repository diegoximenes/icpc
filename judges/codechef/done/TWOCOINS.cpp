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

#define MAX 100005

int n;
int brother[MAX], child[MAX];
vector<int> g[MAX];
int dp[MAX][2][2][3][2];

void dfs(int u, int dad) {
    if (dad != -1) {
        brother[u] = child[dad];
        child[dad] = u;
    }
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (v != dad) dfs(v, u);
    }
}

int opt(int u, int h1, int h2, int cnt_gen, int cnt_next_gen) {
    cnt_gen = max(cnt_gen, 0);
    cnt_next_gen = max(cnt_next_gen, 0);
    cnt_gen = min(2, cnt_gen);
    cnt_next_gen = min(1, cnt_next_gen);

    if (u == -1) {
        if (cnt_gen > 0 || cnt_next_gen > 0) return INF;
        return 0;
    }

    int &ret = dp[u][h1][h2][cnt_gen][cnt_next_gen];
    if (ret != -1) return ret;

    int paint_at_least_two_children =
        opt(child[u], 0, h1, 2, 0) +
        opt(brother[u], h1, h2, cnt_gen, 0);

    int paint_u_and_at_least_one_child =
        1 +
        opt(child[u], 1, h1, 1, 0) +
        opt(brother[u], h1, h2, cnt_gen - 1, 0);

    int paint_u_and_at_least_one_grand_child;
    if (!cnt_next_gen) {
        paint_u_and_at_least_one_grand_child =
            1 +
            opt(child[u], 1, h1, 0, 1) +
            opt(brother[u], h1, h2, cnt_gen - 1, 0);
    } else {
        int op1 =
            1 +
            opt(child[u], 1, h1, 1, 1) +
            opt(brother[u], h1, h2, cnt_gen - 1, 0);
        int op2 =
            1 +
            opt(child[u], 1, h1, 0, 1) +
            opt(brother[u], h1, h2, cnt_gen - 1, 1);
        paint_u_and_at_least_one_grand_child = min(op1, op2);
    }

    int paint_u;
    if (!cnt_next_gen) {
        paint_u =
            1 +
            opt(child[u], 1, h1, 0, 0) +
            opt(brother[u], h1, h2, cnt_gen - 1, 0);
    } else {
        int op1 =
            1 +
            opt(child[u], 1, h1, 1, 0) +
            opt(brother[u], h1, h2, cnt_gen - 1, 0);
        int op2 =
            1 +
            opt(child[u], 1, h1, 0, 0) +
            opt(brother[u], h1, h2, cnt_gen - 1, 1);
        paint_u = min(op1, op2);
    }

    int paint_at_least_one_child =
        opt(child[u], 0, h1, 1, 0) +
        opt(brother[u], h1, h2, cnt_gen, 0);

    ret = INF;
    ret = min(ret, paint_at_least_two_children);
    ret = min(ret, paint_u_and_at_least_one_child);
    ret = min(ret, paint_u_and_at_least_one_grand_child);

    if (h1 || h2) ret = min(ret, paint_u);
    if (h1) ret = min(ret, paint_at_least_one_child);

    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
            g[i].clear();
            brother[i] = child[i] = -1;
        }

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            --u; --v;
            g[u].pb(v); g[v].pb(u);
        }

        dfs(0, -1);

        memset(dp, -1, sizeof(dp));

        if (n == 1)
            puts("-1");
        else
            printf("%d\n", opt(0, 0, 0, 0, 0));
    }

    return 0;
}
