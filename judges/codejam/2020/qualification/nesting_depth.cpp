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

#define MAX 100005

char s[MAX], out[MAX];

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        scanf("%s", s);
        int len_s = strlen(s);

        int open = 0, len_out = 0;
        for (int i = 0; i < len_s; ++i) {
            int d = s[i] - '0' - open;
            if (d > 0) {
                while (d--) {
                    out[len_out++] = '(';
                }
            } else if (d < 0) {
                d *= -1;
                while (d--) {
                    out[len_out++] = ')';
                }
            }
            out[len_out++] = s[i];
            open = s[i] - '0';
        }
        while (open--) {
            out[len_out++] = ')';
        }
        out[len_out] = 0;

        printf("Case #%d: %s\n", tc, out);
    }

    return 0;
}
