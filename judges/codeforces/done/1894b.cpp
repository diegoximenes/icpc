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

#define MAX 101

vector<int> pos[MAX];
int out[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        for (int i = 1; i <= 100; ++i) {
            pos[i].clear();
        }
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            pos[a].pb(i);
        }

        int cnt_equal_case = 0;
        for (int i = 1; i <= 100; ++i) {
            if (pos[i].size() > 1) {
                if (cnt_equal_case == 0) {
                    out[pos[i][0]] = 1;
                } else {
                    out[pos[i][0]] = 2;
                }
                cnt_equal_case++;
                for (int j = 1; j < (int) pos[i].size(); ++j) {
                    out[pos[i][j]] = 3;
                }
            } else if (!pos[i].empty()) {
                out[pos[i][0]] = 1;
            }
        }

        if (cnt_equal_case < 2) {
            cout << -1 << endl;
        } else {
            cout << out[0];
            for (int i = 1; i < n; ++i) {
                cout << " " << out[i];
            }
            cout << endl;
        }
    }

    return 0;
}
