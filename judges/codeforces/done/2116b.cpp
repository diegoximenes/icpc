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

#define MAX 100000
#define MOD 998244353LL

int p[MAX], q[MAX];
ll pow2[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    pow2[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        read_array(p, n);
        read_array(q, n);

        int id_p_max = 0, id_q_max = 0;
        for (int i = 0; i < n; ++i) {
            if (p[id_p_max] < p[i]) {
                id_p_max = i;
            }
            if (q[id_q_max] < q[i]) {
                id_q_max = i;
            }

            int a = max(p[i - id_q_max], q[id_q_max]);
            int b = min(p[i - id_q_max], q[id_q_max]);
            int c = max(p[id_p_max], q[i - id_p_max]);
            int d = min(p[id_p_max], q[i - id_p_max]);

            ll sol;
            if (a > c) {
                sol = (pow2[a] + pow2[b]) % MOD;
            } else if (a < c) {
                sol = (pow2[c] + pow2[d]) % MOD;
            } else {
                if (b > d) {
                    sol = (pow2[a] + pow2[b]) % MOD;
                } else {
                    sol = (pow2[c] + pow2[d]) % MOD;
                }
            }
            // cout << "i=" << i << ", id_p_max=" << id_p_max << ", id_q_max=" << id_q_max << ", sol=" << sol << endl;
            cout << sol << " ";
        }
        cout << endl;
    }

    return 0;
}
