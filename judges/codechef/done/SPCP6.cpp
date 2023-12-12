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

#define MAX 100001
#define MOD 1000000007LL

ll dp[2][2][MAX];

ll opt(int p, int last_p, int last4, int l) {
    if (l <= 0) {
        return (last_p == 0) && last4;
    }
    ll &ret = dp[p][last_p][l];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    ret = (ret + opt(1 - p, p, 0, l - 1)) % MOD;
    ret = (ret + opt(p, p, 0, l - 2)) % MOD;
    ret = (ret + opt(p, p, 0, l - 3)) % MOD;
    ret = (ret + opt(p, p, 1, l - 4)) % MOD;

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));

    int tc;
    cin >> tc;
    while (tc--) {
        int l;
        cin >> l;

        cout << opt(0, 0, 0, l) << endl;
    }

    return 0;
}
