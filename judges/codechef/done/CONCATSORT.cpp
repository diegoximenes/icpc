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

int a[MAX], sorted[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            sorted[i] = a[i];
        }

        vector<int> p, q;
        sort(sorted, sorted + n);
        int i;
        for (i = 0; i < n && a[i] == sorted[i]; ++i) {
            p.pb(a[i]);
        }
        if (i != n) {
            int i_smallest, smallest = INF;
            for (int j = i; j < n; ++j) {
                if (a[j] < smallest) {
                    smallest = a[j];
                    i_smallest = j;
                }
            }
            for (int j = i; j < i_smallest; ++j) {
                q.pb(a[j]);
            }
            p.pb(a[i_smallest]);
            for (int j = i_smallest + 1; j < n; ++j) {
                if (a[j] > q[0] || a[j] == q.back()) {
                    q.pb(a[j]);
                } else {
                    p.pb(a[j]);
                }
            }
        }

        vector<int> concat;
        for (int i = 0; i < (int) p.size(); ++i) {
            concat.pb(p[i]);
        }
        for (int i = 0; i < (int) q.size(); ++i) {
            concat.pb(q[i]);
        }

        bool can = 1;
        for (int i = 0; i < n; ++i) {
            if (concat[i] != sorted[i]) {
                can = 0;
            }
        }

        printf("%s\n", can ? "YES" : "NO");
    }

    return 0;
}
