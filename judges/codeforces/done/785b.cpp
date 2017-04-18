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

#define MAX 200005

int main() {
    int n, m;
    int l, r;
    int max_l_a = -INF, max_l_b = -INF;
    int min_r_a = INF, min_r_b = INF;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &l, &r);
        max_l_a = max(max_l_a, l);
        min_r_a = min(min_r_a, r);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &l, &r);
        max_l_b = max(max_l_b, l);
        min_r_b = min(min_r_b, r);
    }

    int sol = max(max_l_a - min_r_b, max_l_b - min_r_a);
    sol = max(0, sol);

    printf("%d\n", sol);

    return 0;
}
