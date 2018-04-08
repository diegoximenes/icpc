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

int a;
bool mark[20][20];

int check_block(int x, int y) {
    int cnt1 = 0;
    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            cnt1 += mark[i][j];
        }
    }
    return cnt1;
}

pair<int, int> get_next_target(int lenx, int leny) {
    set< pair<int, pair<int, int> > > tree;
    for (int i = 2; i < lenx; ++i) {
        for (int j = 2; j < leny; ++j) {
            tree.insert(mp(check_block(i, j), mp(i, j)));
        }
    }
    return tree.begin()->se;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        scanf("%d", &a);

        int lenx = sqrt(a);
        int leny = a / lenx;
        lenx = max(lenx, 3);
        leny = max(leny, 3);
        if (lenx * leny < a) {
            lenx++;
        }
        memset(mark, 0, sizeof(mark));

        while (1) {
            pair<int, int> next_target = get_next_target(lenx, leny);
            printf("%d %d\n", next_target.fi, next_target.se);
            fflush(stdout);
            int x, y;
            scanf("%d %d", &x, &y);
            if (x == 0 && y == 0) {
                break;
            }
            mark[x][y] = 1;
        }
    }

    return 0;
}
