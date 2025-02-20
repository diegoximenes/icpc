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

#define MAX 701

int a[MAX][MAX];

pair<int, int> neigh[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline bool in(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            read_array(a[i], m);
        }

        unordered_map<int, bool> can_one;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                can_one[a[i][j]] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int ni = i + neigh[k].fi;
                    int nj = j + neigh[k].se;
                    if (in(ni, nj, n, m) && a[i][j] == a[ni][nj]) {
                        can_one[a[i][j]] = 0;
                    }
                }
            }
        }

        int sol = -1;
        bool found_two = 0;
        for (auto &p : can_one) {
            if (p.se) {
                sol++;
            } else if (!found_two) {
                found_two = 1;
                sol++;
            } else {
                sol += 2;
            }
        }
        if (can_one.size() == 1) {
            sol = 0;
        }
        cout << sol << endl;
    }

    return 0;
}
