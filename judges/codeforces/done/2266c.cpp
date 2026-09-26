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

#define MAX 200005

int n;
int dp[2][MAX];

int opt(int started_1, int i, string &s) {
    if (i == n) {
        return 0;
    }
    int &ret = dp[started_1][i];
    if (ret != -1) {
        return ret;
    }

    if (s[i] == '0') {
        if (started_1) {
            return ret = 1 + opt(1, i + 1, s);
        }
        return ret = opt(0, i + 1, s);
    }

    ret = opt(1, i + 1, s);
    if (!started_1 && i > 0) {
        ret = min(ret, 1 + opt(0, i + 1, s));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> n >> s;

        for (int i = 0; i < n; ++i) {
            dp[0][i] = dp[1][i] = -1;
        }
        cout << opt(0, 0, s) << endl;
    }

    return 0;
}
