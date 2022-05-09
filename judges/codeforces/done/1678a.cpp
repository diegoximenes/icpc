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

#define MAX 105

int a[MAX];
bool has[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        memset(has, 0, sizeof(has));
        bool has_equal = 0;
        int cnt0 = 0;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] == 0) {
               cnt0++;
            }
            if (has[a[i]]) {
                has_equal = 1;
            }
            has[a[i]] = 1;
        }

        int sol;
        if (cnt0 || has_equal) {
            sol = n - cnt0;
        } else {
            sol = n + 1;
        }
        printf("%d\n", sol);
    }

    return 0;
}
