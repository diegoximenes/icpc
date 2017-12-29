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

int main() {
    int n;
    set< pair<int, int> > tree;
    set< pair<int, int> >::iterator it;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            tree.insert(mp(i, j));
        }
    }

    int sol = 0;
    while (!tree.empty()) {
        sol++;
        pair<int, int> p = *tree.begin();
        tree.erase(tree.begin());
        while (!tree.empty() && tree.upper_bound(mp(p.se, -1)) != tree.end()) {
            it = tree.lower_bound(mp(p.se, -1));
            p = *it;
            tree.erase(it);
        }
    }
    printf("%d\n", sol);

    return 0;
}
