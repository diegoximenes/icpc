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

#define MOD 1000000007LL
#define MAX 100005

bool mark[MAX];
vector<int> g[MAX];

int dfs(int u) {
    mark[u] = 1;
    int tree_size = 1;
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (!mark[v]) {
            tree_size += dfs(v);
        }
    }
    return tree_size;
}

ll power(ll b, ll e) {
    ll ret = 1;
    for (int i = 0; i < e; ++i) {
        ret = (ret * b) % MOD;
    }
    return ret;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        --u; --v;
        if (!w) {
            g[u].pb(v);
            g[v].pb(u);
        }
    }

    ll sol = power(n, k);
    memset(mark, 0, sizeof(mark));
    for (int i = 0; i < n; ++i) {
        if (!mark[i]) {
            ll cc_size = dfs(i);
            sol -= power(cc_size, k);
            if (sol < 0) {
                sol += MOD;
            }
        }
    }

    cout << sol << endl;

    return 0;
}
