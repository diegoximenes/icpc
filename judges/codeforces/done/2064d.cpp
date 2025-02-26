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

#define MAX 200002

int w[MAX], cum_xor[MAX];

int most_significative_bit(int x) {
    for (int i = 31; i >= 0; --i) {
        if ((1 << i) & x) {
            return i;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        read_array(w, n);

        set<int> pos[32];
        cum_xor[0] = w[0];
        for (int i = 0; i < n; ++i) {
            pos[most_significative_bit(w[i])].insert(-i);
            if (i > 0) {
                cum_xor[i] = cum_xor[i - 1] ^ w[i];
            }
        }

        while (q--) {
            int x;
            cin >> x;

            int curr_pos = n;
            cum_xor[n] = cum_xor[n - 1] ^ x;
            while (1) {
                if (x == 0) {
                    break;
                }

                int next_pos = -1;
                int msb = most_significative_bit(x);
                for (int k = msb; k < 32; ++k) {
                    auto it = pos[k].upper_bound(-curr_pos);
                    if (it != pos[k].end()) {
                        next_pos = max(next_pos, -*it);
                    }
                }

                if (next_pos != -1) {
                    x = cum_xor[n] ^ cum_xor[next_pos];
                    if (w[next_pos] > x) {
                        curr_pos = next_pos + 1;
                        break;
                    }
                    x ^= w[next_pos];
                    curr_pos = next_pos;
                } else {
                    curr_pos = 0;
                    break;
                }
            }

            cout << n - curr_pos << endl;
        }
    }

    return 0;
}
