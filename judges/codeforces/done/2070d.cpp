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
inline void print_vector(const vector<T> &v) {
    if (!v.empty()) {
        cout << v[0];
    }
    for (int i = 1; i < (int) v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

template <class T>
inline void read_vector(vector<T> &v, int n, int start = 0) {
    for (int i = start; i < start + n; ++i) {
        cin >> v[i];
    }
}

#define MAX 300001
#define MOD 998244353LL

int max_h;
ll dp[MAX], dp_h[MAX];
vector<int> g[MAX], h[MAX];

void dfs(int u, int curr_h) {
    max_h = max(max_h, curr_h);
    h[curr_h].pb(u);
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        dfs(v, curr_h + 1);
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

        max_h = 0;
        for (int i = 0; i < n; ++i) {
            h[i].clear();
            g[i].clear();
        }

        for (int i = 1; i <= n - 1; ++i) {
            int p;
            cin >> p;
            g[--p].pb(i);
        }
        dfs(0, 0);

        for (int curr_h = max_h; curr_h > 0; curr_h--) {
            dp_h[curr_h] = 0;
            for (int i = 0; i < (int) h[curr_h].size(); ++i) {
                int u = h[curr_h][i];
                dp[u] = 1;
                if (curr_h + 1 <= max_h) {
                    dp[u] = (dp[u] + dp_h[curr_h + 1]) % MOD;
                }

                for (int j = 0; j < (int) g[u].size(); ++j) {
                    int v = g[u][j];
                    dp[u] = (dp[u] - dp[v]) % MOD;
                    if (dp[u] < 0) {
                        dp[u] += MOD;
                    }
                }

                dp_h[curr_h] = (dp_h[curr_h] + dp[u]) % MOD;
            }
        }

        int sol = 1;
        for (int i = 0; i < (int) h[1].size(); ++i) {
            int u = h[1][i];
            sol = (sol + dp[u]) % MOD;
        }
        cout << sol << endl;
    }

    return 0;
}
