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

#define MAX 5005
#define MOD 1000000007

int n;
char s[MAX];
int dp[MAX][MAX];

int opt(int i, int cnt_for) {
    if (cnt_for < 0) return 0;
    if (i == n) return 1;
    int &ret = dp[i][cnt_for];
    if (ret != -1) return ret;

    ret = opt(i + 1, cnt_for + (s[i] == 'f'));
    if (i > 0 && s[i - 1] != 'f') {
        ret = (ret + opt(i, cnt_for - 1)) % MOD;
    }
    return ret;
}

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%c\n", &s[i]);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", opt(0, 0));

    return 0;
}
