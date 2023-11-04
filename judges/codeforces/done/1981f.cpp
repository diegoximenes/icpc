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

#define MAXN 500010

ll tree[4 * MAXN];
int n;
ll query(int v, int vb, int ve, int b, int e) {
    if (vb > e || ve < b) {
        return 0;
    }
    if (vb >= b && ve <= e) {
        return tree[v];
    }
    int mid = vb + (ve - vb) / 2;
    int vl = v << 1;
    int vr = (v << 1) + 1;
    return query(vl, vb, mid, b, e) + query(vr, mid + 1, ve, b, e);
}
ll query(int b, int e) {
    return query(1, 1, n, b, e);
}
void update(int v, int vb, int ve, int p, ll val) {
    if (vb == ve && vb == p) {
        tree[v] += val;
        return;
    }
    int mid = vb + (ve - vb) / 2;
    int vl = v << 1;
    int vr = (v << 1) + 1;
    if (p <= mid) {
        update(vl, vb, mid, p, val);
    } else {
        update(vr, mid + 1, ve, p, val);
    }
    tree[v] = tree[vl] + tree[vr];
}
void update(int p, ll val) {
    update(1, 1, n, p, val);
}

vector<int> g[MAXN];
vector<pair<int, ll>> to_add[MAXN];
ll out[MAXN];

void dfs(int u) {
    for (int i = 0; i < (int) to_add[u].size(); ++i) {
        update(to_add[u][i].fi, to_add[u][i].se);
    }
    out[u] = query(u, n);
    for (int i = 0; i < (int) g[u].size(); ++i) {
        dfs(g[u][i]);
    }
    for (int i = 0; i < (int) to_add[u].size(); ++i) {
        update(to_add[u][i].fi, -to_add[u][i].se);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
            to_add[i].clear();
        }
        for (int i = 1; i <= 4 * n; ++i) {
            tree[i] = 0;
        }
        n = 1;

        int q;
        cin >> q;
        while (q--) {
            int t;
            cin >> t;
            if (t == 1) {
                int v;
                cin >> v;
                g[v].pb(++n);
            } else {
                int v, x;
                cin >> v >> x;
                to_add[v].pb(mp(n, x));
            }
        }

        dfs(1);

        cout << out[1];
        for (int i = 2; i <= n; ++i) {
            cout << " " << out[i];
        }
        cout << endl;
    }

    return 0;
}
