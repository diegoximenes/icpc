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

#define MAX 300000

int a[MAX], cnt[32];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        read_array(a, n);

        memset(cnt, 0, sizeof(cnt));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 32; ++j) {
                if (a[i] & (1 << j)) {
                    cnt[j]++;
                }
            }
            ans ^= a[i];
        }

        for (int i = 0; i < n; ++i) {
            int l_ans = 0;
            for (int j = 0; j < 32; ++j) {
                int l_cnt = cnt[j];
                if (a[i] & (1 << j)) {
                    l_cnt--;
                }
                if (l_cnt & 1) {
                    l_ans |= (1 << j);
                }
            }
            ans = min(ans, l_ans);
        }
        cout << ans << endl;
    }

    return 0;
}
