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

ll r[MAX], q[MAX], q_upper[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        // (q * y + r) / y, r < y < x <= k
        //
        // y = r + 1
        //
        // y <= k => r + 1 <= k
        //
        // x <= k => (q * (r + 1) + r) <= k
        // q * (r + 1) <= k - r
        // q <= (k - r) / (r + 1)

        ll n, k;
        cin >> n >> k;
        read_array(q, n);
        read_array(r, n);
        sort(r, r + n);
        sort(q, q + n);
        int len_q_upper = 0;
        for (int i = n - 1; i >= 0; --i) {
            ll y = r[i] + 1;
            if (y > k) {
                continue;
            }
            ll l_q_upper = (k - r[i]) / y;
            if (l_q_upper > k) {
                continue;
            }
            q_upper[len_q_upper++] = l_q_upper;
        }
        sort(q_upper, q_upper + len_q_upper);
        int sol = 0, i_q_upper = len_q_upper - 1;
        for (int i = n - 1; i >= 0 && i_q_upper >= 0; --i) {
            if (q[i] <= q_upper[i_q_upper]) {
                sol++;
                i_q_upper--;
            }
        }

        cout << sol << endl;
    }

    return 0;
}
