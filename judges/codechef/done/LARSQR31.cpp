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
#define LOGMAX 22

int s[MAX], e[MAX];
int log2n[MAX];
int min_sparse_table[MAX][LOGMAX];
int max_sparse_table[MAX][LOGMAX];

void build_min_sparse_table(int *v, int table[MAX][LOGMAX], int n) {
    for (int i = 0; i < n; ++i) {
        table[i][0] = v[i];
    }
    for (int j = 1; j <= log2n[n]; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            table[i][j] =
                min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

void build_max_sparse_table(int *v, int table[MAX][LOGMAX], int n) {
    for (int i = 0; i < n; ++i) {
        table[i][0] = v[i];
    }
    for (int j = 1; j <= log2n[n]; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            table[i][j] =
                max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
        }
    }
}

inline int get_min_sparse_table(int table[MAX][LOGMAX], int l, int r) {
    int j = log2n[r - l];
    return min(table[l][j], table[r - (1 << j) + 1][j]);
}

inline int get_max_sparse_table(int table[MAX][LOGMAX], int l, int r) {
    int j = log2n[r - l];
    return max(table[l][j], table[r - (1 << j) + 1][j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> e[i];
    }

    log2n[1] = 0;
    for (int i = 2; i <= n; ++i) {
        log2n[i] = log2n[i / 2] + 1;
    }

    build_min_sparse_table(e, min_sparse_table, n);
    build_max_sparse_table(s, max_sparse_table, n);

    int l = 1, r = n, opt = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        bool can = 0;
        for (int i = mid - 1; i < n; ++i) {
            int q_l = i - mid + 1;
            int q_r = i;
            if (get_min_sparse_table(min_sparse_table, q_l, q_r) -
                    get_max_sparse_table(max_sparse_table, q_l, q_r) + 1 >=
                mid) {
                can = 1;
                break;
            }
        }

        if (can) {
            opt = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << opt << endl;

    return 0;
}
