#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

#define MAX 2 * 50005

int v[MAX], out[MAX];

int main() {
    ios::sync_with_stdio(false);

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 2 * n; ++i)
            scanf("%d", &v[i]);

        sort(v, v + 2 * n);
        int l = 0, r = 2 * n - 1;
        while (l < n) {
            out[2 * l] = v[l];
            out[2 * l + 1] = v[r];
            l++; r--;
       }

        printf("%d\n", v[n + n / 2]);
        printf("%d", out[0]);
        for (int i = 1; i < 2 * n; ++i)
            printf(" %d", out[i]);
        puts("");
    }

    return 0;
}
