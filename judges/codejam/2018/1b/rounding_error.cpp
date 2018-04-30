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

#define MAX 100005

int n, l;

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        int cnt_all = 0;
        int sol = 0;
        multiset< pair<double, int> > heap;
        multiset< pair<double, int> >::iterator it;

        scanf("%d %d", &n, &l);
        for (int i = 0; i < l; ++i) {
            int cnt;
            scanf("%d", &cnt);
            cnt_all += cnt;
            double left = 100.0 * (double) cnt / (double) n;
            double right = (100 * cnt) / n + 0.5;
            if (cmp_double(left, right) == -1) {
                heap.insert(mp(right - left, cnt));
            } else {
                sol += round((double) (100 * cnt) / (double) n);
            }
        }
        for (int i = cnt_all + 1; i <= n; ++i) {
            heap.insert(mp(0.5, 0));
        }
        for (int i = cnt_all + 1; i <= n; ++i) {
            pair<double, int> p = *heap.begin();
            heap.erase(heap.begin());
            p.se += 1;
            double left = 100.0 * (double) p.se / (double) n;
            double right = (100 * p.se) / n + 0.5;
            if (cmp_double(left, right) == -1) {
                heap.insert(mp(right - left, p.se));
            } else {
                sol += round((double) (100 * p.se) / (double) n);
            }
        }
        for (it = heap.begin(); it != heap.end(); ++it) {
            sol += round((double) (100 * it->se) / (double) n);
        }

        printf("Case #%d: %d\n", tc, sol);
    }

    return 0;
}
