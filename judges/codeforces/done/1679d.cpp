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

int a[MAX], in_deg[MAX], dist[MAX];
vector<int> g[MAX];

int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;

    unordered_set<int> unique_a;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        unique_a.insert(a[i]);
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
    }

    vector<int> unique_a_v;
    unordered_set<int>::iterator it;
    for (it = unique_a.begin(); it != unique_a.end(); ++it) {
        unique_a_v.pb(*it);
    }
    sort(unique_a_v.begin(), unique_a_v.end());

    int out = -1;
    int l = 0, r = unique_a_v.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        int n_valid = 0;
        for (int u = 0; u < n; ++u) {
            if (a[u] <= unique_a_v[mid]) {
                n_valid++;
                in_deg[u] = 0;
            }
        }
        for (int u = 0; u < n; ++u) {
            if (a[u] <= unique_a_v[mid]) {
                for (int i = 0; i < (int) g[u].size(); ++i) {
                    int v = g[u][i];
                    if (a[v] <= unique_a_v[mid]) {
                        in_deg[v]++;
                    }
                }
            }
        }

        queue<int> zero_in_deg;
        for (int u = 0; u < n; ++u) {
            if ((a[u] <= unique_a_v[mid]) && !in_deg[u]) {
                dist[u] = 0;
                zero_in_deg.push(u);
            }
        }

        int cnt_visited = 0, max_dist = -1;
        while (!zero_in_deg.empty()) {
            int u = zero_in_deg.front();
            zero_in_deg.pop();
            max_dist = max(max_dist, dist[u]);
            cnt_visited++;
            for (int i = 0; i < (int) g[u].size(); ++i) {
                int v = g[u][i];
                if (a[v] <= unique_a_v[mid]) {
                    dist[v] = dist[u] + 1;
                    in_deg[v]--;
                    if (!in_deg[v]) {
                        zero_in_deg.push(v);
                    }
                }
            }
        }

        if ((cnt_visited != n_valid) || (max_dist >= k - 1)) {
            r = mid - 1;
            out = unique_a_v[mid];
        } else {
            l = mid + 1;
        }
    }

    cout << out << endl;

    return 0;
}
