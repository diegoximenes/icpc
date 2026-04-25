#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

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

int n;
ll dp[2][MAX], b[MAX], a[MAX];

ll opt(bool added_b, int i) {
    if (i == n) {
        if (added_b) {
            return 0;
        }
        return -INFLL;
    }
    ll &ret = dp[added_b][i];
    if (ret != -INFLL) {
        return ret;
    }

    ret = 0;
    if (!added_b) {
        ret = max(ret, a[i] + b[i] + opt(1, i + 1));
    }
    ret = max(ret, a[i] + opt(added_b, i + 1));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int k;
        cin >> n >> k;
        read_array(a, n);
        read_array(b, n);

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = -INFLL;
            }
        }

        bool added_b = 1;
        if (k & 1) {
            added_b = 0;
        }

        ll sol = -INFLL;
        for (int i = 0; i < n; ++i) {
            sol = max(sol, a[i] + opt(added_b, i + 1));
            if (!added_b) {
                sol = max(sol, a[i] + b[i] + opt(1, i + 1));
            }
        }
        cout << sol << endl;
    }

    return 0;
}
