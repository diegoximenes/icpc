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

#define MAX 200001
ll mod = 998244353;

int n;
ll dp[MAX][2];
int a[MAX];

ll opt(int i, int has_two) {
    if (i == n) {
        return 0;
    }
    ll &ret = dp[i][has_two];
    if (ret != -1) {
        return ret;
    }

    if (a[i] == 2) {
        ret = (opt(i + 1, 1) + opt(i + 1, has_two)) % mod;
    } else if (a[i] == 1) {
        ret = opt(i + 1, has_two);
    } else {
        if (has_two) {
            ret = (1 + opt(i + 1, 1)) % mod;
        } else {
            ret = opt(i + 1, 0);
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        read_array(a, n);
        for (int i = 0; i < n; ++i) {
            dp[i][0] = dp[i][1] = -1;
        }

        ll sol = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                sol = (sol + opt(i + 1, 0)) % mod;
            }
        }
        cout << sol << endl;
    }

    return 0;
}
