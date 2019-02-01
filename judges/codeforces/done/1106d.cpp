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

#define MAX 100005

int n, m;
vector<int> g[MAX], out;
set<int> min_neigh;
bool mark[MAX];

void dfs(int u) {
    out.pb(u + 1);
    mark[u] = 1;
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (!mark[v]) {
            min_neigh.insert(v);
        }
    }
    if (!min_neigh.empty()) {
        int v = *min_neigh.begin();
        min_neigh.erase(min_neigh.begin());
        dfs(v);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    memset(mark, 0, sizeof(mark));
    dfs(0);
    printf("%d", out[0]);
    for (int i = 1; i < n; ++i) {
        printf(" %d", out[i]);
    }
    puts("");

    return 0;
}
