#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

#ifdef LOCAL
    #define debug(...) { fprintf(stderr, __VA_ARGS__); fflush(stderr); }
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

template<class T> inline void print_array(T *v, int n) {
    if (n > 0) {
        cout << v[0];
    }
    for (int i = 1; i < n; ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

template<class T> inline void read_array(T *v, int n, int start = 0) {
    for (int i = start; i < start + n; ++i) {
        cin >> v[i];
    }
}

int x2, y2;
int dp[8][8][100];
int moves[8][2] = {{-2, 1}, {-2, -1}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {1, 2}, {1, -2}};

bool in(int i, int j) {
    return (i >= 0 && i < 8 && j >= 0 && j < 8);
}

int opt(int i, int j, int cnt_moves) {
    if (cnt_moves == 100 && i == x2 && j == y2) {
        return 1;
    }
    if (cnt_moves >= 100) {
        return 0;
    }
    int &ret = dp[i][j][cnt_moves];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    for (int k = 0; k < 8; ++k) {
        int ni = i + moves[k][0];
        int nj = j + moves[k][1];
        if (in(ni, nj)) {
            ret = ret || opt(ni, nj, cnt_moves + 1);
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int x1, y1;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1; --y1; --x2; --y2;
        memset(dp, -1, sizeof(dp));
        cout << (opt(x1, y1, 0) ? "YES" : "NO") << endl;
    }

    return 0;
}
