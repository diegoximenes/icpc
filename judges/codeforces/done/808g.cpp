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

#define MAX 100005
#define MAX2 20000005

char p[MAX], t[MAX];
int dp[MAX2], n, m;
int dp_next_len_match[MAX]['z' - 'a' + 1];

int pi_[MAX];

void kmp_prefix() {
    pi_[0] = -1;
    for (int i = 1, k = -1; i < m; ++i) {
        while (k >= 0 && p[k + 1] != p[i]) k = pi_[k];
        if (p[k + 1] == p[i]) ++k;
        pi_[i] = k;
    }
}

inline int id(int i, int j) {
    return i * (m + 1) + j;
}

int opt(int i, int curr_len_match) {
    if (i == n) return (curr_len_match == m);
    int &ret = dp[id(i, curr_len_match)];
    if (ret != -1) return ret;

    if (curr_len_match == m)
        return ret = 1 + opt(i, pi_[curr_len_match - 1] + 1);

    if (t[i] != '?') {
        int next_len_match = dp_next_len_match[curr_len_match][t[i] - 'a'];
        ret = opt(i + 1, next_len_match);
    } else {
        ret = 0;
        for (char c = 'a'; c <= 'z'; ++c) {
            int next_len_match = dp_next_len_match[curr_len_match][c - 'a'];
            ret = max(ret, opt(i + 1, next_len_match));
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    scanf(" %s %s ", t, p);
    n = strlen(t);
    m = strlen(p);

    if (m > n) {
        puts("0");
        return 0;
    }

    kmp_prefix();
    // for (int i = 0; i < m; ++i) printf("i=%d, p_[i]=%d\n", i, pi_[i]);

    for (char c = 'a'; c <= 'z'; ++c) {
        dp_next_len_match[0][c - 'a'] = (p[0] == c);
        for (int len_match = 1; len_match < m; ++len_match) {
            if (p[len_match] == c) {
                dp_next_len_match[len_match][c - 'a'] = len_match + 1;
            } else {
                dp_next_len_match[len_match][c - 'a'] =
                    dp_next_len_match[pi_[len_match - 1] + 1][c - 'a'];
            }
            // printf("len_match=%d, c=%c, dp_next_len_match=%d\n", len_match, c, dp_next_len_match[len_match][c - 'a']);
        }
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", opt(0, 0));

    return 0;
}
