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
#define MOD 1000000007
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

char g[4][MAX];
int dp[5][4][MAX];
int n;

int opt(int dir, int i, int j) {
    // printf("dir=%d, i=%d, j=%d\n", dir, i, j);
    if (i < 0 || i >= 3 || j < 0 || j >= n || g[i][j] == '#') {
        return 0;
    }
    if ((j == n - 1) && (i == 2)) {
        return (dir == DOWN);
    }
    int &ret = dp[dir][i][j];
    if (ret != -1) return ret;

    ret = 0;
    if (dir == DOWN || dir == UP) {
        ret = (ret + opt(RIGHT, i, j + 1)) % MOD;
        // ret = (ret + opt(LEFT, i, j - 1)) % MOD;
    } else if (dir == LEFT || dir == RIGHT) {
        ret = (ret + opt(UP, i - 1, j)) % MOD;
        ret = (ret + opt(DOWN, i + 1, j)) % MOD;
    }

    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);
        for (int i = 0; i < 3; ++i) {
            scanf("%s", g[i]);
        }

        memset(dp, -1, sizeof(dp));
        int sol = opt(RIGHT, 0, 0);

        printf("Case #%d: %d\n", tc, sol);
    }

    return 0;
}
