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
ll s[MAX], a[MAX];
vector<int> g[MAX];
bool can = 1;

void dfs(int u, int dad, ll s_dad) {
    if (s[u] == -1) {
        ll min_child = INFLL;
        for (int i = 0; i < (int) g[u].size(); ++i) {
            int v = g[u][i];
            if (v != dad) {
                if (s[v] < s_dad) {
                    can = 0;
                    return;
                }
                min_child = min(min_child, s[v]);
            }
            if (min_child < INFLL) {
                a[u] = min_child - s_dad;
            } else {
                a[u] = 0;
            }
        }
    } else {
        if (s[u] < s_dad) {
            can = 0;
            return;
        }
        a[u] = s[u] - s_dad;
    }

    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (v != dad) {
            dfs(v, u, s_dad + a[u]);
        }
    }
}

int main() {
    fast_io;
    cin >> n;
    for (int u = 1; u < n; ++u) {
        int v;
        cin >> v;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int u = 0; u < n; ++u) {
        cin >> s[u];
    }

    dfs(0, -1, 0);

    if (can) {
        ll sol = 0;
        for (int i = 0; i < n; ++i) {
            sol += a[i];
        }
        cout << sol << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
