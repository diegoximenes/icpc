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

int a[MAX], b[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        read_array(a, n);
        read_array(b, m);

        sort(b, b + m);
        bool can = 1;
        if (a[0] > b[0] - a[0]) {
            a[0] = b[0] - a[0];
        }
        for (int i = 1; i < n; ++i) {
            int lo = 0, hi = m - 1;
            int last = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (b[mid] - a[i] < a[i - 1]) {
                    lo = mid + 1;
                } else {
                    last = mid;
                    hi = mid - 1;
                }
            }
            if (last != -1 && ((b[last] - a[i] < a[i] && b[last] - a[i] >= a[i - 1]) || (a[i] < a[i - 1]))) {
                a[i] = b[last] - a[i];
            }
            if (a[i] < a[i - 1]) {
                can = 0;
                break;
            }
        }

        if (can) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
