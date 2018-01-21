#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
const double PI = acos(-1);
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

#define MAX 1005
#define MAXMASK (1 << 12)
const int MOD = 1000000007;

int dp_mask[MAXMASK];
int dp[MAX][MAX][2];
int k;
string s;

int opt_mask(int mask) {
    if (mask == 1) return 0;
    int &ret = dp_mask[mask];
    if (ret != -1) return ret;
    ret = 1 + opt_mask(__builtin_popcount(mask));
    return ret;
}

int opt(int i, int cnt_one, int is_lower) {
    if (cnt_one < 0) return 0;
    if (i == (int) s.size()) return (cnt_one == 0);
    int &ret = dp[i][cnt_one][is_lower];
    if (ret != -1) return ret;

    ret = 0;
    if (is_lower) {
        // add 1
        ret = (ret + opt(i + 1, cnt_one - 1, 1)) % MOD;
        // add 0
        ret = (ret + opt(i + 1, cnt_one, 1)) % MOD;
    } else {
        if (s[i] == '0') {
            // add 0
            ret = (ret + opt(i + 1, cnt_one, 0)) % MOD;
        } else {
            // add 0
            ret = (ret + opt(i + 1, cnt_one, 1)) % MOD;
            // add 1
            ret = (ret + opt(i + 1, cnt_one - 1, 0)) % MOD;
        }
    }

    return ret;
}

int main() {
    cin >> s >> k;

    if (k == 0) {
        cout << 1 << endl;
    } else if (k == 1) {
        cout << s.size() - 1 << endl;
    } else {
        memset(dp, -1, sizeof(dp));
        memset(dp_mask, -1, sizeof(dp_mask));

        int sol = 0;
        for (int cnt_one = 2; cnt_one <= (int) s.size(); ++cnt_one) {
            if (opt_mask(cnt_one) == k - 1) {
                sol = (sol + opt(0, cnt_one, 0)) % MOD;
            }
        }

        cout << sol << endl;
    }

    return 0;
}
