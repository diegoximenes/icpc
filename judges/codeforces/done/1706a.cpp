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

#define MAX 51

char out[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i) {
            out[i] = 'B';
        }
        out[m] = '\0';
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            int min_a = min(a, m + 1 - a) - 1;
            int max_a = max(a, m + 1 - a) - 1;
            if (out[min_a] == 'A') {
                out[max_a] = 'A';
            }
            out[min_a] = 'A';
        }
        printf("%s\n", out);
    }

    return 0;
}
