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

#define MAX 1005

pair<int, int> v[MAX];
char out[MAX * 2];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &v[i].fi, &v[i].se);
        }

        sort(v, v + n);
        pair<int, int> p = mp(0, 0);
        bool has_solution = 1;
        int len_out = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i].se < p.se) {
                has_solution = 0;
                break;
            }

            while (v[i].fi > p.fi) {
               out[len_out++] = 'R';
               p.fi++;
            }

            while (v[i].se > p.se) {
                out[len_out++] = 'U';
                p.se++;
            }
        }
        out[len_out] = '\0';

        if (has_solution) {
            printf("YES\n%s\n", out);
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
