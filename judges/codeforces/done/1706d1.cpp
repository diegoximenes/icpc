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

#define MAX 3000

int a[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        int cost = INF;
        for (int mini = 0; mini <= a[0]; ++mini) {
            int l_maxi = 0;
            int l_mini = INF;
            bool can = 1;
            for (int i = 0; i < n; ++i) {
                /*
                 * a / x >= mini
                 * a / mini >= x
                 */
                int x;
                if (mini == 0) {
                    x = a[i] + 1;
                } else {
                    x = a[i] / mini;
                }
                x = min(x, k);

                l_mini = min(l_mini, a[i] / x);
                l_maxi = max(l_maxi, a[i] / x);
            }
            if (can) {
                cost = min(cost, l_maxi - l_mini);
            }
        }
        printf("%d\n", cost);
    }

    return 0;
}
