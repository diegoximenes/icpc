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

ll a[MAX], prefix[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    int s;
    cin >> s;
    while (tc--) {
        int n;
        cin >> n;
        read_array(a, n);

        sort(a, a + n);
        prefix[0] = a[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = a[i] + prefix[i - 1];
        }

        if (s == 0) {
            if (n & 1) {
                cout << prefix[n >> 1] << endl;
            } else {
                cout << prefix[n >> 1] - prefix[0] << endl;
            }
        } else {
            ll ans = 0;
            for (int i = 0; i < n; ++i) {
                int len = n - i;
                if (len & 1) {
                    ans = max(ans, prefix[i + (len >> 1)] - prefix[i - 1]);
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}
