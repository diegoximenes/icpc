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

#define MAX 1005

int n;
pair<int, int> obel[MAX];
set< pair<int, int> > clues;
set< pair<int, int> >::iterator it;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &obel[i].fi, &obel[i].se);
    }
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        clues.insert(mp(x, y));
    }

    for (it = clues.begin(); it != clues.end(); ++it) {
        pair<int, int> target = mp(obel[0].fi + it->fi, obel[0].se + it->se);
        bool can = 1;
        for (int i = 1; i < n; ++i) {
            pair<int, int> search = mp(target.fi - obel[i].fi, target.se - obel[i].se);
            if (clues.find(search) == clues.end()) {
                can = 0;
                break;
            }
        }

        if (can) {
            printf("%d %d\n", target.fi, target.se);
            return 0;
        }
    }

    return 0;
}
