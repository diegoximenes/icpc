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

#define MAX 300005
#define MAX2 205

int n, m;
ll a[MAX], b[MAX2];
ll dp[2][MAX], best_k[2][MAX], sum[MAX];

inline ll get_cost(int turn, int new_end_pos) {
    if (new_end_pos - b[turn] + 1 <= 0) {
        if (turn & 1)
            return -INFLL;
        return INFLL;
    }
    return sum[new_end_pos] - sum[new_end_pos - b[turn]];
}

void compute(int turn, int left, int right, int best_k_left, int best_k_right) {
    if (right < left)
        return;
    int end_pos = (left + right) / 2;

    ll &ret = dp[turn & 1][end_pos];
    if (turn & 1)
        ret = -INFLL;
    else
        ret = INFLL;

    if (end_pos - b[turn - 1] + 1 <= 0) {
        // compute(turn, left, end_pos - 1, best_k_left, best_k_right);
        compute(turn, end_pos + 1, right, best_k_left, best_k_right);
        return;
    }

    int l, r;
    if (turn == 1) {
        r = end_pos;
        l = end_pos - b[turn - 1] + 1;
    } else {
        r = end_pos - 1;
        l = end_pos - b[turn - 1] + 1 + b[turn] - 1 + 1;
    }
    l = max(l, best_k_left);
    r = min(r, best_k_right);

    if (turn & 1) {
        for (int new_end_pos = l; new_end_pos <= r; ++new_end_pos) {
            ll cost = get_cost(turn, new_end_pos);
            if (cost + dp[(turn + 1) & 1][new_end_pos] > ret) {
                ret = dp[(turn + 1) & 1][new_end_pos] + cost;
                best_k[turn & 1][end_pos] = new_end_pos;
            }
        }
    } else {
        for (int new_end_pos = l; new_end_pos <= r; ++new_end_pos) {
            ll cost = get_cost(turn, new_end_pos);
            if (dp[(turn + 1) & 1][new_end_pos] - cost < ret) {
                ret = dp[(turn + 1) & 1][new_end_pos] - cost;
                best_k[turn & 1][end_pos] = new_end_pos;
            }
        }
    }

    if (left != right) {
        compute(turn, left, end_pos - 1, best_k_left, best_k[turn & 1][end_pos]);
        compute(turn, end_pos + 1, right, best_k[turn & 1][end_pos], best_k_right);
    }
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 1; i <= m; ++i)
            cin >> b[i];

        sum[0] = 0;
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i - 1] + a[i];

        b[0] = n;

        for (int i = 1; i <= n; ++i)
            dp[(m + 1) & 1][i] = 0;
        for (int turn = m; turn >= 1; --turn)
            compute(turn, 1, n, 1, n);

        cout << dp[1][n] << endl;
    }

    return 0;
}
