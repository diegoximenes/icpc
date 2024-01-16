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

int a[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        read_array(a, n);

        multiset<int> max_heap;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                max_heap.insert(a[i] - a[i - 1]);
            }
        }

        while (q--) {
            int i, x;
            cin >> i >> x;
            i--;

            if ((i - 1 >= 0) && (a[i] < a[i - 1])) {
                multiset<int>::iterator it = max_heap.find(a[i] - a[i - 1]);
                max_heap.erase(it);
            }
            if ((i + 1 < n) && (a[i + 1] < a[i])) {
                multiset<int>::iterator it = max_heap.find(a[i + 1] - a[i]);
                max_heap.erase(it);
            }

            a[i] = x;
            if ((i - 1 >= 0) && (a[i] < a[i - 1])) {
                max_heap.insert(a[i] - a[i - 1]);
            }
            if ((i + 1 < n) && (a[i + 1] < a[i])) {
                max_heap.insert(a[i + 1] - a[i]);
            }

            int min_ops = 0;
            if (!max_heap.empty()) {
                min_ops = -*max_heap.begin();
            }
            cout << min_ops << endl;
        }
    }

    return 0;
}
