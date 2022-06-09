#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false)
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

#define MAX 200002

char s[MAX];
int sum[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d %s", &n, &k, s);

        int out = n;
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1];
            if (s[i - 1] == 'W') {
                sum[i]++;
            }
            if (i - k >= 0) {
                out = min(out, sum[i] - sum[i - k]);
            }
        }
        printf("%d\n", out);
    }

    return 0;
}
