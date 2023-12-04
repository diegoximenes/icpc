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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        read_vector(v, n);

        if (n == 1) {
            if (v[0] % k == 0) {
                cout << 0 << endl;
            } else {
                cout << k - v[0] % k << endl;
            }
        } else {
            int max_ops = INF;
            if (k == 4) {
                int cnt_even = 0;
                for (auto a : v) {
                    if (!(a & 1)) {
                        cnt_even++;
                    }
                }
                if (cnt_even >= 2) {
                    max_ops = 0;
                } else if (cnt_even == 1) {
                    max_ops = 1;
                } else {
                    max_ops = 2;
                }
            }

            for (auto a : v) {
                if (a % k == 0) {
                    max_ops = 0;
                }
                max_ops = min(max_ops, k - a % k);
            }

            cout << max_ops << endl;
        }
    }

    return 0;
}
