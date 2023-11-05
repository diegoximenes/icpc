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

int cnt_len_prefixlen_prefix[6][6][9 * 5 + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> s;
    for (int i = 0; i < n; ++i) {
        int si;
        cin >> si;

        vector<int> v;
        while (si) {
            v.pb(si % 10);
            si /= 10;
        }
        s.pb(v);

        // needed prefixes
        // len(1): 1
        // len(2): 2
        // len(3): 1, 3
        // len(4): 1, 4
        // len(5): 1, 2, 5
        switch ((int) v.size()) {
            case 1: {
                // 1
                cnt_len_prefixlen_prefix[1][1][v[0]]++;
                break;
            }
            case 2: {
                // 2
                cnt_len_prefixlen_prefix[2][2][v[0] + v[1]]++;
                break;
            }
            case 3: {
                // 1
                if (v[1] + v[2] > v[0]) {
                    cnt_len_prefixlen_prefix[3][1][v[1] + v[2] - v[0]]++;
                }
                // 3
                cnt_len_prefixlen_prefix[3][3][v[0] + v[1] + v[2]]++;
                break;
            }
            case 4: {
                // 1
                if (v[1] + v[2] + v[3] > v[0]) {
                    cnt_len_prefixlen_prefix[4][1][v[1] + v[2] + v[3] - v[0]]++;
                }
                // 4
                cnt_len_prefixlen_prefix[4][4][v[0] + v[1] + v[2] + v[3]]++;
                break;
            }
            default: {
                // 1
                if (v[1] + v[2] + v[3] + v[4] > v[0]) {
                    cnt_len_prefixlen_prefix[5][1][v[1] + v[2] + v[3] + v[4] - v[0]]++;
                }
                // 2
                if (v[2] + v[3] + v[4] > v[0] + v[1]) {
                    cnt_len_prefixlen_prefix[5][2][v[2] + v[3] + v[4] - v[0] - v[1]]++;
                }
                // 5
                cnt_len_prefixlen_prefix[5][5][v[0] + v[1] + v[2] + v[3] + v[4]]++;
                break;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        switch ((int) s[i].size()) {
            case 1: {
                // 1 + 1
                ans += cnt_len_prefixlen_prefix[1][1][s[i][0]];
                // 1 + 3
                ans += cnt_len_prefixlen_prefix[3][1][s[i][0]];
                // 1 + 3
                // 1 + 5
                ans += cnt_len_prefixlen_prefix[5][2][s[i][0]];
                break;
            }
            case 2: {
                int sum = s[i][0] + s[i][1];
                // 2 + 2
                ans += cnt_len_prefixlen_prefix[2][2][sum];
                // 2 + 4
                ans += cnt_len_prefixlen_prefix[4][1][sum];
                break;
            }
            case 3: {
                int sum = s[i][0] + s[i][1] + s[i][2];
                // 3 + 1
                if (s[i][0] + s[i][1] > s[i][2]) {
                    ans += cnt_len_prefixlen_prefix[1][1][s[i][0] + s[i][1] - s[i][2]];
                }
                // 3 + 3
                ans += cnt_len_prefixlen_prefix[3][3][sum];
                // 3 + 5
                ans += cnt_len_prefixlen_prefix[5][1][sum];

                break;
            }
            case 4: {
                // 4 + 2
                if (s[i][0] + s[i][1] + s[i][2] > s[i][3]) {
                    ans += cnt_len_prefixlen_prefix[2][2][s[i][0] + s[i][1] + s[i][2] - s[i][3]];
                }
                // 4 + 4
                ans += cnt_len_prefixlen_prefix[4][4][s[i][0] + s[i][1] + s[i][2] + s[i][3]];
                break;
            }
            default: { // 5
                // 5 + 1
                if (s[i][0] + s[i][1] + s[i][2] > s[i][3] + s[i][4]) {
                    ans += cnt_len_prefixlen_prefix[1][1][s[i][0] + s[i][1] + s[i][2] - s[i][3] - s[i][4]];
                }
                // 5 + 3
                if (s[i][0] + s[i][1] + s[i][2] + s[i][3] > s[i][4]) {
                    ans += cnt_len_prefixlen_prefix[3][3][s[i][0] + s[i][1] + s[i][2] + s[i][3] - s[i][4]];
                }
                // 5 + 5
                ans += cnt_len_prefixlen_prefix[5][5][s[i][0] + s[i][1] + s[i][2] + s[i][3] + s[i][4]];
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
