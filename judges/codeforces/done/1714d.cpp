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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        string t;
        cin >> t;
        int n;
        cin >> n;
        vector<string> s = read_vector<string>(n);

        vector<pair<int, int>> out;
        int len = 0;
        bool can = 1;
        while ((len < (int) t.size()) && can) {
            int best_new_len = len;
            int best_s = -1;
            int best_start;

            for (int i = 0; i < n; ++i) {
                for (int j = min(len, (int) t.size() - (int) s[i].size());
                     j >= max(0, len - (int) s[i].size() + 1); --j) {
                    bool s_can = 1;
                    for (int k = 0; k < (int) s[i].size(); ++k) {
                        if (s[i][k] != t[j + k]) {
                            s_can = 0;
                        }
                    }
                    if (s_can && (j + (int) s[i].size() > best_new_len)) {
                        best_new_len = j + s[i].size();
                        best_s = i;
                        best_start = j;
                    }
                }
            }

            if (best_s != -1) {
                out.pb(mp(best_s + 1, best_start + 1));
                len = best_new_len;
            } else {
                can = 0;
            }
        }

        if (!can) {
            cout << "-1" << endl;
        } else {
            cout << out.size() << endl;
            for (int i = 0; i < (int) out.size(); ++i) {
                cout << out[i].fi << " " << out[i].se << endl;
            }
        }
    }

    return 0;
}
