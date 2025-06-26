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

ll compute(set<pair<ll, ll>> &xtree_l, set<pair<ll, ll>> &xtree_r, set<pair<ll, ll>> &ytree_d, set<pair<ll, ll>> &ytree_u, ll x, ll y, ll n) {
    xtree_l.erase(mp(x, y));
    xtree_r.erase(mp(-x, y));
    ytree_d.erase(mp(y, x));
    ytree_u.erase(mp(-y, x));
    ll minx = xtree_l.begin()->fi;
    ll maxx = -xtree_r.begin()->fi;
    ll miny = ytree_d.begin()->fi;
    ll maxy = -ytree_u.begin()->fi;
    ll sol = (maxx - minx + 1) * (maxy - miny + 1);
    if (sol < n) {
        sol = min((maxx - minx + 1 + 1) * (maxy - miny + 1), (maxx - minx + 1) * (maxy - miny + 1 + 1));
    }
    xtree_l.insert(mp(x, y));
    xtree_r.insert(mp(-x, y));
    ytree_d.insert(mp(y, x));
    ytree_u.insert(mp(-y, x));
    return sol;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        set<pair<ll, ll>> xtree_l, xtree_r, ytree_d, ytree_u;
        for (int i = 0; i < n; ++i) {
            ll x, y;
            cin >> x >> y;

            xtree_l.insert(mp(x, y));
            xtree_r.insert(mp(-x, y));
            ytree_d.insert(mp(y, x));
            ytree_u.insert(mp(-y, x));
        }

        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        ll sol = INFLL;

        auto it = xtree_l.begin();
        ll x = it->fi, y = it->se;
        ll lsol = compute(xtree_l, xtree_r, ytree_d, ytree_u, x, y, n);
        sol = min(sol, lsol);

        it = xtree_r.begin();
        x = -it->fi, y = it->se;
        lsol = compute(xtree_l, xtree_r, ytree_d, ytree_u, x, y, n);
        sol = min(sol, lsol);

        it = ytree_d.begin();
        x = it->se, y = it->fi;
        lsol = compute(xtree_l, xtree_r, ytree_d, ytree_u, x, y, n);
        sol = min(sol, lsol);

        it = ytree_u.begin();
        x = it->se, y = -it->fi;
        lsol = compute(xtree_l, xtree_r, ytree_d, ytree_u, x, y, n);
        sol = min(sol, lsol);

        cout << sol << endl;
    }

    return 0;
}
