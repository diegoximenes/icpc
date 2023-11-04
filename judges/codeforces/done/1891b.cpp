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

#define MAXN 100001

ll out[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;

        vector<pair<int, ll>> exps[31];
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            int la = a, exp = 0;
            while (a % 2 == 0) {
                a /= 2;
                exp++;
            }
            exps[exp].pb(mp(i, la));
        }

        while (q--) {
            int x;
            cin >> x;
            for (int i = x; i < 31; ++i) {
                for (int j = 0; j < (int) exps[i].size(); ++j) {
                    exps[x - 1].pb(
                        mp(exps[i][j].fi, exps[i][j].se + (1LL << (x - 1)))
                    );
                }
                exps[i].clear();
            }
        }

        for (int i = 0; i < 31; ++i) {
            for (int j = 0; j < (int) exps[i].size(); ++j) {
                out[exps[i][j].fi] = exps[i][j].se;
            }
        }
        cout << out[0];
        for (int i = 1; i < n; ++i) {
            cout << " " << out[i];
        }
        cout << endl;
    }

    return 0;
}
