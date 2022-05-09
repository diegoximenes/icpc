#include <algorithm>
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

#define MAX 100005

int a[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        int l = 0, r = n - 1;
        while (l < r) {
            if ((a[l] > 0) && (a[r] < 0)) {
                a[l] = -a[l];
                a[r] = -a[r];
                l++;
                r--;
            } else {
                if (a[l] < 0) {
                    l++;
                }
                if (a[r] > 0) {
                    r--;
                }
            }
        }

        bool is_sorted = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                is_sorted = 0;
                break;
            }
        }

        printf(is_sorted ? "YES\n" : "NO\n");
    }

    return 0;
}
