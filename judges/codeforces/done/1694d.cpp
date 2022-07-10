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

#define MAX 200000

vector<int> g[MAX];
ll l[MAX], r[MAX], deg[MAX];
ll sum[MAX];

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            g[i].clear();
            deg[i] = 0;
            sum[i] = 0;
        }
        for (int i = 0; i < n - 1; ++i) {
            int p;
            cin >> p;
            p--;
            g[i + 1].pb(p);
            deg[p]++;
        }
        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i];
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (!deg[i]) {
                q.push(i);
            }
        }
        int cnt_ops = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (sum[u] < l[u]) {
                cnt_ops++;
                sum[u] = r[u];
            }

            for (int i = 0; i < (int) g[u].size(); ++i) {
                int v = g[u][i];
                sum[v] += min(sum[u], r[u]);
                deg[v]--;
                if (!deg[v]) {
                    q.push(v);
                }
            }
        }
        cout << cnt_ops << endl;
    }

    return 0;
}
