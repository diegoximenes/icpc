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

#define MAX 2 * 200005

int n, k, q;
int sum[MAX], ok[MAX];
pair<int, bool> v[MAX];

int main() {
    scanf("%d %d %d", &n, &k, &q);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        v[cnt].fi = l; v[cnt].se = 0;
        cnt++;
        v[cnt].fi = r; v[cnt].se = 1;
        cnt++;
    }

    memset(ok, 0, sizeof(ok));
    sort(v, v + cnt);
    int cnt_open = 0, l, r;
    for (int i = 0; i < cnt; ++i) {
        if (v[i].se == 0) {
            cnt_open++;
            if (cnt_open == k) {
                l = v[i].fi;
            }
        } else {
            cnt_open--;
            if (cnt_open == k - 1) {
                for (int j = l; j <= v[i].fi; ++j) {
                    ok[j] = 1;
                }
            }
        }
        // printf("i=%d, cnt_open=%d, v[i]=(%d, %d)\n", i, cnt_open, v[i].fi, v[i].se);
    }

    sum[0] = 0;
    for (int i = 1; i < MAX; ++i)
        sum[i] = sum[i - 1] + ok[i];

    while (q--) {
        scanf("%d %d", &l, &r);
        printf("%d\n", sum[r] - sum[l - 1]);
    }

    return 0;
}
