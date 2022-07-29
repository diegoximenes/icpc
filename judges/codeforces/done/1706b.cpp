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

#define MAX 100000

int cnt_odd[MAX], cnt_even[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            cnt_odd[i] = cnt_even[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            int c;
            scanf("%d", &c);
            --c;
            if (i & 1) {
                cnt_odd[c] = cnt_even[c] + 1;
            } else {
                cnt_even[c] = cnt_odd[c] + 1;
            }
        }

        printf("%d", max(cnt_odd[0], cnt_even[0]));
        for (int i = 1; i < n; ++i) {
            printf(" %d", max(cnt_odd[i], cnt_even[i]));
        }
        printf("\n");
    }

    return 0;
}
