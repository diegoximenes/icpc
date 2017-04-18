#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

#define MAX 20

ll dp_comb[MAX][MAX];
ll dp[MAX][MAX];
int a[MAX], cnt_digit[MAX];

ll comb(int n, int k) {
    if (k > n || k < 0 || n < 0) return 0;
    if (n == k) return 1;
    ll &ret = dp_comb[n][k];
    if (ret != -1) return ret;

    ret = comb(n - 1, k) + comb(n - 1, k - 1);
    return ret;
}

ll opt(int d, int n) {
    if (n == 0) {
        for (int i = d; i <= 9; ++i)
            if (cnt_digit[i] == a[i])
                return 0;
        return 1;
    }
    if (d > 9) return 0;
    ll &ret = dp[d][n];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i <= n; ++i)
        if (cnt_digit[d] + i != a[d])
            ret += comb(n, i) * opt(d + 1, n - i);
    return ret;
}

vector<int> get_digits(ll x) {
    vector<int> digits;
    while (x) {
        digits.pb(x % 10);
        x /= 10;
    }
    return digits;
}

ll solve(vector<int> &lower, vector<int> &upper, int pos,
         bool greater_than_lower, bool lower_than_upper,
         int cnt_leading_zeros) {
    if (pos == -1) {
        for (int i = 0; i <= 9; ++i)
            if (cnt_digit[i] == a[i])
                return 0;
        return 1;
    }

    if (greater_than_lower && lower_than_upper) {
        memset(dp, -1, sizeof(dp));
        return opt(0, pos + 1);
    }

    int lower_d = 0, upper_d = 9;
    if (!greater_than_lower) lower_d = lower[pos];
    if (!lower_than_upper) upper_d = upper[pos];

    ll sol = 0;
    for (int d = lower_d; d <= upper_d; ++d) {
        if (d != 0 || cnt_leading_zeros == 0) cnt_digit[d]++;

        int new_cnt_leading_zeros = max(0, cnt_leading_zeros - 1);
        if (d > 0) new_cnt_leading_zeros = 0;

        bool new_greater_than_lower = greater_than_lower;
        bool new_lower_than_upper = lower_than_upper;
        if (d > lower[pos]) new_greater_than_lower = 1;
        if (d < upper[pos]) new_lower_than_upper = 1;

        sol += solve(lower, upper, pos - 1, new_greater_than_lower,
                     new_lower_than_upper, new_cnt_leading_zeros);

        if (d != 0 || cnt_leading_zeros == 0) cnt_digit[d]--;
    }
    return sol;
}

int main() {
    memset(dp_comb, -1, sizeof(dp_comb));
    memset(cnt_digit, 0, sizeof(cnt_digit));

    int t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        for (int i = 0; i <= 9; ++i) cin >> a[i];

        vector<int> lower, upper;
        lower = get_digits(l);
        upper = get_digits(r);
        int cnt_leading_zeros = upper.size() - lower.size();
        while (lower.size() < upper.size()) lower.pb(0);

        ll sol = solve(lower, upper, lower.size() - 1, 0, 0, cnt_leading_zeros);
        cout << sol << endl;
    }

    return 0;
}
