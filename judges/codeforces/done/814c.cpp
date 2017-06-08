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

#define MAX 1505

char s[MAX];
int n;
int dp['z' - 'a' + 1][MAX], cnt['z' - 'a' + 1][MAX];

int main() {
    scanf("%d %s", &n, s);

    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            cnt[c - 'a'][i] = cnt[c - 'a'][i - 1];
        }
        cnt[s[i - 1] - 'a'][i]++;
    }

    for (char c = 'a'; c <= 'z'; ++c) {
        for (int m = 1; m <= n; ++m) {
            int lsol = 0;
            for (int i = 1; i <= n; ++i) {
                int lo = i, hi = n;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    int cnt_c = cnt[c - 'a'][mid] - cnt[c - 'a'][i - 1];
                    if (m + cnt_c >= mid - i + 1) {
                        lsol = max(lsol, mid - i + 1);
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
            }
            dp[c - 'a'][m] = lsol;
        }
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        char c;
        int m;
        scanf("%d %c", &m, &c);
        printf("%d\n", dp[c - 'a'][m]);
    }

    return 0;
}
