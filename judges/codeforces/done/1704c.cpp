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
inline void print_vector(vector<T> &v) {
    if (!v.empty()) {
        cout << v[0];
    }
    for (int i = 1; i < (int) v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

template <class T>
inline vector<T> read_vector(int n) {
    vector<T> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<int> a = read_vector<int>(m);

        sort(a.begin(), a.end());
        priority_queue<int> segs;
        int len_round = a.front() - 1 + n - a.back();
        if (len_round) {
            segs.push(len_round);
        }
        for (int i = 1; i < m; ++i) {
            int len = a[i] - a[i - 1] - 1;
            if (len > 0) {
                segs.push(len);
            }
        }

        int saved_houses = 0;
        int t = 0;
        while (!segs.empty()) {
            int start_len = segs.top();
            segs.pop();
            int len = start_len - t * 2;
            if (len > 0) {
                saved_houses++;
                len--;
                if (len > 0) {
                    len--;
                    t++;
                    saved_houses += len;
                }
            }
            t++;
        }

        cout << n - saved_houses << endl;
    }

    return 0;
}
