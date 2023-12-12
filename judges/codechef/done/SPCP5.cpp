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

#define MAX 1000001

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bitset<MAX> is_prime;
    is_prime.set();
    for (ll i = 2; i < MAX; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j < MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    int tc;
    cin >> tc;
    while (tc--) {
        int h;
        cin >> h;

        int p = 1, ans = 0;
        while (h) {
            ans++;

            if (is_prime[h]) {
                h = 0;
                break;
            }
            h -= p;
            if (h < 0) {
                ans = -1;
                break;
            }
            p *= 2;
        }
        cout << ans << endl;
    }

    return 0;
}
