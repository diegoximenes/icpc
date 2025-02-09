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

#define MAX 301

int v[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        vector<int> one_suffixes;
        for (int i = 0; i < n; ++i) {
            read_array(v, n);
            int suffix = 0;
            for (int j = n - 1; j >= 0; --j) {
                if (v[j] == 1) {
                    suffix++;
                } else {
                    break;
                }
            }
            if (suffix) {
                one_suffixes.pb(suffix);
            }
        }

        if (n == 1) {
            cout << 1 << endl;
            continue;
        }

        sort(one_suffixes.begin(), one_suffixes.end());
        int expected = 1;
        for (int i = 0; i < (int) one_suffixes.size(); ++i) {
            if (one_suffixes[i] >= expected) {
                expected++;
            }
        }
        if (expected == n + 1) {
            expected--;
        }
        cout << expected << endl;
    }

    return 0;
}
