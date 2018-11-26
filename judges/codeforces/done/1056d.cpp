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

int n;
vector<int> g[MAX];
int cnt_leafs[MAX];

void dfs(int u, int dad) {
    cnt_leafs[u] = 0;
    bool is_leaf = 1;
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (v != dad) {
            dfs(v, u);
            cnt_leafs[u] += cnt_leafs[v];
            is_leaf = 0;
        }
    }
    if (is_leaf) {
        cnt_leafs[u] = 1;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        int p;
        scanf("%d", &p);
        --p;
        g[p].pb(i);
        g[i].pb(p);
    }

    dfs(0, -1);
    sort(cnt_leafs, cnt_leafs + n);

    printf("%d", cnt_leafs[0]);
    for (int i = 1; i < n; ++i) {
        printf(" %d", cnt_leafs[i]);
    }
    puts("");

    return 0;
}
