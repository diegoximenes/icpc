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

#define MAXDIG 20

int dp[2][10][MAXDIG], len_n;
vector<int> digits, out;

int opt(int is_smaller, int last_digit, int pos) {
    if (pos == -1) return 1;
    int &ret = dp[is_smaller][last_digit][pos];
    if (ret != -1) return ret;

    ret = 0;
    int upper_digit = digits[pos];
    if (is_smaller) upper_digit = 9;
    for (int curr_digit = upper_digit; curr_digit >= last_digit; --curr_digit) {
        int next_is_smaller = 0;
        if (is_smaller || (curr_digit < digits[pos])) next_is_smaller = 1;
        if (opt(next_is_smaller, curr_digit, pos - 1)) {
            out.pb(curr_digit);
            return (ret = 1);
        }
    }

    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        ll n;
        scanf("%lld", &n);

        memset(dp, -1, sizeof(dp));
        digits.clear();
        out.clear();
        while (n) {
            digits.pb(n % 10);
            n /= 10;
        }
        opt(0, 0, digits.size() - 1);

        printf("Case #%d: ", tc);
        for (int i = out.size() - 1; i >= 0; --i)
            if (out[i] > 0)
                printf("%d", out[i]);
        puts("");
    }

    return 0;
}
