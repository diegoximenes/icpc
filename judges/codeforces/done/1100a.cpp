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

int v[MAX];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    int sol = -INF;
    for (int b = 0; b < n; ++b) {
        int cnt_test = 0, cnt_social = 0;
        for (int c = 0; c < n; ++c) {
            if ((c - b) % k != 0) {
                if (v[c] == 1) {
                    cnt_test++;
                } else {
                    cnt_social++;
                }
            }
        }
        sol = max(sol, abs(cnt_test - cnt_social));
    }

    printf("%d\n", sol);

    return 0;
}
