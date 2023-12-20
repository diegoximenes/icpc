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

#define MAX 100000

pair<int, int> a[MAX], b[MAX], c[MAX];

int get(pair<int, int> x[MAX], pair<int, int> y[MAX], pair<int, int> z[MAX], int n) {
    int ix = n - 1;

    int iy = n - 1;
    if (y[iy].se == x[ix].se) {
        iy--;
    }

    int iz = n - 1;
    if (z[iz].se == x[ix].se) {
        iz--;
        if (z[iz].se == y[iy].se) {
            iz--;
        }
    } else if (z[iz].se == y[iy].se) {
        iz--;
        if (z[iz].se == x[ix].se) {
            iz--;
        }
    }

    return x[ix].fi + y[iy].fi + z[iz].fi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].fi;
            a[i].se = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].fi;
            b[i].se = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i].fi;
            c[i].se = i;
        }

        sort(a, a + n);
        sort(b, b + n);
        sort(c, c + n);

        int ans = get(a, b, c, n);
        ans = max(ans, get(a, c, b, n));
        ans = max(ans, get(b, a, c, n));
        ans = max(ans, get(b, c, a, n));
        ans = max(ans, get(c, a, b, n));
        ans = max(ans, get(c, b, a, n));

        cout << ans << endl;
    }

    return 0;
}
