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

#define MAXN 200001

int a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a, a + n);
        ll cnt_attacks = 0, x = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            if (a[l] == 0) {
                l++;
            } else if (x + a[l] < a[r]) {
                cnt_attacks += a[l];
                x += a[l];
                a[l] = 0;
                l++;
            } else {
                cnt_attacks += a[r] - x + 1;
                a[l] -= a[r] - x;
                a[r] = 0;
                x = 0;
                r--;
            }
        }
        if (a[l] == 1) {
            cnt_attacks++;
        } else if (a[l] > 1) {
            // x + da >= a[l] - da
            // 2 * da >= a[l] - x
            // da >= (a[l] - x) / 2
            int da = (a[l] - x) / 2 + (a[l] - x) % 2;
            cnt_attacks += da + 1;
        }

        cout << cnt_attacks << endl;
    }

    return 0;
}
