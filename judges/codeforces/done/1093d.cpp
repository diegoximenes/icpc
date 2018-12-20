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

#define MAX 300005
#define MOD 998244353LL

int n, m;
vector<int> g[MAX];
int dist[MAX];

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            dist[i] = -1;
            g[i].clear();
        }
        while (m--) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            g[u].pb(v);
            g[v].pb(u);
        }

        ll sol = 1;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (dist[i] == -1) {
                q.push(i);
                dist[i] = 0;
                ll sol1 = 1, sol2 = 2;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int i = 0; i < (int) g[u].size(); ++i) {
                        int v = g[u][i];
                        if (dist[v] == -1) {
                            dist[v] = dist[u] + 1;
                            q.push(v);

                            if (dist[v] & 1) {
                                sol1 = (sol1 * 2LL) % MOD;
                            } else {
                                sol2 = (sol2 * 2LL) % MOD;
                            }
                        }
                    }
                }

                sol = (sol * (sol1 + sol2) % MOD) % MOD;
            }
        }

        bool can = 1;
        for (int u = 0; u < n; ++u) {
            for (int i = 0; i < (int) g[u].size(); ++i) {
                int v = g[u][i];
                if ((dist[u] & 1) == (dist[v] & 1)) {
                    can = 0;
                }
            }
        }
        if (!can) {
            cout << 0 << endl;
        } else {
            cout << sol << endl;
        }
    }

    return 0;
}
