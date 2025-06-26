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

#define MAX 200000

ll threat[MAX], a[MAX];
int dad[MAX];
vector<int> g[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        read_array(a, n);
        for (int i = 0; i < n; ++i) {
            g[i].clear();
            dad[i] = -1;
        }
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            g[u].pb(v);
            g[v].pb(u);
        }

        queue<pair<int, int>> q;
        q.push(mp(0, 0));
        dad[0] = 0;
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int u = p.fi, d = p.se;

            if (d == 0 || d == 1) {
                threat[u] = a[u];
            } else {
                threat[u] = max(a[u], a[u] - a[dad[u]] + threat[dad[dad[u]]]);
            }
            for (auto v : g[u]) {
                if (dad[v] == -1) {
                    dad[v] = u;
                    q.push(mp(v, d + 1));
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << threat[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
