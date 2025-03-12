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

int a[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, l, r;
        cin >> n >> l >> r;
        read_array(a, n);

        --l;
        --r;

        vector<int> left;
        for (int i = 0; i < l; ++i) {
            left.pb(a[i]);
        }
        sort(left.begin(), left.end());

        vector<int> mid;
        for (int i = l; i <= r; ++i) {
            mid.pb(a[i]);
        }
        sort(mid.begin(), mid.end());
        reverse(mid.begin(), mid.end());

        vector<int> right;
        for (int i = r + 1; i < n; ++i) {
            right.pb(a[i]);
        }
        sort(right.begin(), right.end());

        ll sol = 0;
        for (int i = 0; i < (int) mid.size(); ++i) {
            sol += mid[i];
        }

        int i;

        ll sol_left = 0;
        for (i = 0; i < (int) mid.size() && i < (int) left.size() && left[i] < mid[i]; i++) {
            sol_left += left[i];
        }
        for(; i < (int) mid.size(); ++i) {
            sol_left += mid[i];
        }

        ll sol_right = 0;
        for (i = 0; i < (int) mid.size() && i < (int) right.size() && right[i] < mid[i]; i++) {
            sol_right += right[i];
        }
        for(; i < (int) mid.size(); ++i) {
            sol_right += mid[i];
        }

        sol = min(sol, min(sol_left, sol_right));
        cout << sol << endl;
    }

    return 0;
}
