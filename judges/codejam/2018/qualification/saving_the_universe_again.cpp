#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false)
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

#define MAX 35

char p[MAX];
ll d, strength[MAX];

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        scanf("%lld %s", &d, p);

        int n = strlen(p);
        ll curr_strength = 1, damage = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i] == 'C') {
                curr_strength *= 2;
            } else {
                damage += curr_strength;
            }
            strength[i] = curr_strength;
        }

        int sol = 0;
        for (int i = n - 2; (damage > d) && (i >= 0); --i) {
            for (int j = i; (damage > d) && (j <= n - 2) && (p[j] == 'C') &&
                 (p[j + 1] == 'S'); ++j) {
                sol++;
                swap(p[j], p[j + 1]);
                damage -= strength[j] / 2;
                strength[j + 1] = strength[j];
                strength[j] /= 2;
            }
        }

        printf("Case #%d: ", tc);
        if (damage > d) {
            puts("IMPOSSIBLE");
        } else {
            printf("%d\n", sol);
        }
    }

    return 0;
}
