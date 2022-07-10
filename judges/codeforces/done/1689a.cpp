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

#define MAX 101

char a[MAX], b[MAX], c[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, k;
        scanf("%d %d %d %s %s", &n, &m, &k, a, b);

        sort(a, a + n);
        sort(b, b + m);
        int ia = 0, ib = 0, ic = 0;
        int ops_in_turn = 0, last_was_a = 0;
        while (ia < n && ib < m) {
            if (ops_in_turn == k) {
                if (last_was_a) {
                    c[ic++] = b[ib++];
                    last_was_a = 0;
                } else {
                    c[ic++] = a[ia++];
                    last_was_a = 1;
                }
                ops_in_turn = 1;
            } else {
                if (a[ia] < b[ib]) {
                    c[ic++] = a[ia++];
                    if (last_was_a) {
                        ops_in_turn++;
                    } else {
                        ops_in_turn = 1;
                    }
                    last_was_a = 1;
                } else {
                    c[ic++] = b[ib++];
                    if (last_was_a) {
                        ops_in_turn = 1;
                    } else {
                        ops_in_turn++;
                    }
                    last_was_a = 0;
                }
            }
        }

        c[ic] = 0;
        printf("%s\n", c);
    }

    return 0;
}
