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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (min(b, d) <= min(a, c)) {
            cout << "Gellyfish" << endl;
        } else {
            cout << "Flower" << endl;
        }
    }

    return 0;
}
