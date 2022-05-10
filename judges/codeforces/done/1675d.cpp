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

#define MAX 200005

vector< vector<int> > paths;
vector<int> g[MAX];
int root;
bool is_leaf[MAX], mark[MAX];

void dfs(int u, vector<int> &path) {
    mark[u] = 1;
    path.pb(u);
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (!mark[v]) {
            dfs(v, path);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; ++tc) {
        int n;
        scanf("%d", &n);

        paths.clear();
        for (int u = 0; u < n; ++u) {
            g[u].clear();
            is_leaf[u] = 1;
            mark[u] = 0;
        }

        for (int u = 0; u < n; ++u) {
            int p;
            scanf("%d", &p);
            p--;
            if (u == p) {
                root = u;
            } else {
                g[u].pb(p);
                is_leaf[p] = 0;
            }
        }

        for (int u = 0; u < n; ++u) {
            if (is_leaf[u]) {
                vector<int> path;
                dfs(u, path);
                paths.pb(path);
            }
        }

        printf("%d\n", (int) paths.size());
        for (int i = 0; i < (int) paths.size(); ++i) {
            printf("%d\n", (int) paths[i].size());
            for (int j = paths[i].size() - 1; j >= 0; --j) {
                printf("%d ", paths[i][j] + 1);
            }
            printf("\n");
        }
        if (tc < t - 1) {
            printf("\n");
        }
    }

    return 0;
}
