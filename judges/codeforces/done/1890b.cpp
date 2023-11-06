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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        string s, t;
        cin >> n >> m >> s >> t;

        bool s_is_good = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                s_is_good = 0;
            }
        }
        if (s_is_good) {
            cout << "YES" << endl;
            continue;
        }

        bool t_is_good = 1;
        for (int i = 0; i < m - 1; ++i) {
            if (t[i] == t[i + 1]) {
                t_is_good = 0;
            }
        }
        if (!t_is_good) {
            cout << "NO" << endl;
            continue;
        }

        s_is_good = 1;
        for (int i = 0; i < n - 1; ++i) {
            if ((s[i] == s[i + 1]) && (s[i] == t[0] || s[i + 1] == t[m - 1])) {
                s_is_good = 0;
            }
        }
        if (s_is_good) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
