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

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

#define MAX 5001

int a[MAX], n;
int dp[MAX][MAX];

int opt(int i, int g, int target_g) {
    if (g == target_g) {
        return 0;
    }
    if (i == n) {
        return INF;
    }
    int &ret = dp[i][g];
    if (ret != -1) {
        return ret;
    }

    if (g == 0) {
        ret = min(opt(i + 1, g, target_g), opt(i + 1, a[i], target_g));
    } else {
        ret = min(opt(i + 1, g, target_g), 1 + opt(i + 1, gcd(g, a[i]), target_g));
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        read_array(a, n);

        unordered_map<int, int> cnt;
        int g = a[0];
        cnt[a[0]]++;
        for (int i = 1; i < n; ++i) {
            g = gcd(g, a[i]);
            cnt[a[i]]++;
        }

        int sol;
        if (cnt.find(g) == cnt.end()) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j <= MAX; ++j) {
                    dp[i][j] = -1;
                }
            }
            sol = opt(0, 0, g) + n - 1;
        } else {
            sol = n - cnt[g];
        }
        cout << sol << endl;
    }

    return 0;
}
