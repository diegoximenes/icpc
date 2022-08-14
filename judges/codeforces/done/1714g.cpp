#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

#ifdef LOCAL
#define debug(...)                    \
    {                                 \
        fprintf(stderr, __VA_ARGS__); \
        fflush(stderr);               \
    }
#else
#define debug(...)
#endif

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template <class T>
inline void print_array(T *v, int n) {
    if (n > 0) {
        cout << v[0];
    }
    for (int i = 1; i < n; ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

template <class T>
inline void read_array(T *v, int n, int start = 0) {
    for (int i = start; i < start + n; ++i) {
        cin >> v[i];
    }
}

template <class T>
inline void print_vector(vector<T> &v) {
    if (!v.empty()) {
        cout << v[0];
    }
    for (int i = 1; i < (int) v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

template <class T>
inline vector<T> read_vector(int n) {
    vector<T> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    return v;
}

void dfs(
    vector<vector<pair<int, pair<int, int>>>> &g,
    vector<int> &height,
    vector<ll> &sum_a_down,
    vector<ll> &sum_b_down,
    int u,
    int dad,
    ll sum_a,
    ll sum_b
) {
    sum_a_down[u] = sum_a;
    sum_b_down[u] = sum_b;
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i].fi;
        int a = g[u][i].se.fi;
        int b = g[u][i].se.se;
        if (v != dad) {
            height[v] = height[u] + 1;
            dfs(g, height, sum_a_down, sum_b_down, v, u, sum_a + a, sum_b + b);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        int logn;
        for (logn = 0; (1 << logn) < n; ++logn) {
        }
        logn--;

        vector<vector<int>> ancestor(n, vector<int>(logn + 1, -1));
        vector<ll> sum_a_down(n, 0);
        vector<ll> sum_b_down(n, 0);
        vector<int> height(n, 0);
        vector<vector<pair<int, pair<int, int>>>> g(n);
        for (int i = 1; i < n; ++i) {
            int p, a, b;
            cin >> p >> a >> b;
            --p;
            g[p].pb(mp(i, mp(a, b)));
            g[i].pb(mp(p, mp(a, b)));
            ancestor[i][0] = p;
        }
        ancestor[0][0] = -1;

        dfs(g, height, sum_a_down, sum_b_down, 0, 0, 0, 0);

        for (int i = 1; i <= logn; ++i) {
            for (int u = 0; u < n; ++u) {
                if (ancestor[u][i - 1] != -1) {
                    ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
                }
            }
        }

        for (int u = 1; u < n; ++u) {
            if (sum_b_down[u] <= sum_a_down[u]) {
                cout << height[u];
            } else {
                int v = u;
                int last_v = -1;
                for (int l = logn; l >= 0; --l) {
                    if (ancestor[v][l] == -1) {
                        continue;
                    }
                    if (sum_b_down[ancestor[v][l]] <= sum_a_down[u]) {
                        last_v = ancestor[v][l];
                    } else {
                        v = ancestor[v][l];
                    }
                }

                if (last_v == -1) {
                    cout << 0;
                } else {
                    cout << height[last_v];
                }
            }
            if (u < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
