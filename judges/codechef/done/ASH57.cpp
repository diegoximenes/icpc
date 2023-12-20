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

#define MAX 100000

multiset<int> colors[2 * MAX + 1];
int a[MAX], c_a[MAX], b[MAX], c_b[MAX];
bool b_has_color[2 * MAX + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        read_array(a, n);
        read_array(c_a, n);
        read_array(b, n);
        read_array(c_b, n);

        for (int i = 0; i <= 2 * n; ++i) {
            colors[i].clear();
            b_has_color[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            colors[c_b[i]].insert(b[i]);
            colors[c_a[i]].insert(a[i]);
            b_has_color[c_b[i]] = 1;
        }

        int last = -1;
        bool can = 1;
        for (int i = 0; i < n; ++i) {
            int curr = a[i];
            auto it = colors[c_a[i]].lower_bound(last);
            if (it == colors[c_a[i]].end()) {
                can = 0;
                break;
            }
            if (b_has_color[c_a[i]]) {
                curr = *it;
                colors[c_a[i]].erase(it);
            }
            if (curr < last) {
                can = 0;
                break;
            }
            last = curr;
        }

        if (can) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
