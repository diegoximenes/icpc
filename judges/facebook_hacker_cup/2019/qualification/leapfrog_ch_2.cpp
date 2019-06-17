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

#define MAX 5005

char s[MAX];

int main() {
    int t;
    scanf("%d", &t);
    for (int tc=1; tc <= t; ++tc) {
        scanf("%s", s);
        int n = strlen(s);
        int cnt_b = 0;
        for (int i = 0; i < n; ++i) {
            cnt_b += (s[i] == 'B');
        }

        int minb = (n - 1) / 2 + ((n - 1) & 1);

        printf("Case #%d: ", tc);
        if (((cnt_b >= minb) || (cnt_b >= 2)) && (cnt_b < n - 1)) {
            puts("Y");
        } else {
            puts("N");
        }
    }

    return 0;
}
