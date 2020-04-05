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

#define MAX 1005

pair<pair<int, int>, int> tasks[MAX];
char out[MAX];

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &tasks[i].fi.fi, &tasks[i].fi.se);
            tasks[i].se = i;
        }

        sort(tasks, tasks + n);
        int last_end_j = -1, last_end_c = -1;
        bool possible = 1;
        for (int i = 0; i < n; ++i) {
            if (tasks[i].fi.fi >= last_end_j) {
                out[tasks[i].se] = 'J';
                last_end_j = tasks[i].fi.se;
            } else if (tasks[i].fi.fi >= last_end_c) {
                out[tasks[i].se] = 'C';
                last_end_c = tasks[i].fi.se;
            } else {
                possible = 0;
                break;
            }
        }
        out[n] = 0;

        printf("Case #%d: ", tc);
        if (!possible) {
            puts("IMPOSSIBLE");
        } else {
            printf("%s\n", out);
        }
    }

    return 0;
}
