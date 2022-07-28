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

int a[MAX];
char out[MAX + 1];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, q;
        scanf("%d %d", &n, &q);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        int curr_q = 0;
        out[n] = '\0';
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] > curr_q) {
                if (curr_q < q) {
                    curr_q++;
                    out[i] = '1';
                } else {
                    out[i] = '0';
                }
            } else {
                out[i] = '1';
            }
        }
        printf("%s\n", out);
    }

    return 0;
}
