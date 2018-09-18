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

#define MAX 100005

char row[MAX], col[MAX];
int dp_row[3][MAX], dp_col[MAX][3];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int q, n, m;
        scanf("%s %s %d", row, col, &q);
        m = strlen(row);
        n = strlen(col);

        dp_row[1][1] = (row[0] == '0') || (col[0] == '0');
        for (int j = 2; j <= m; ++j) {
            dp_row[1][j] = !dp_row[1][j - 1] || (row[j - 1] == '0');
        }
        dp_row[2][1] = !dp_row[1][1] || (col[1] == '0');
        for (int j = 2; j <= m; ++j) {
            dp_row[2][j] = !dp_row[2][j - 1] || !dp_row[1][j];
        }

        dp_col[1][1] = (row[0] == '0') || (col[0] == '0');
        for (int i = 2; i <= n; ++i) {
            dp_col[i][1] = !dp_col[i - 1][1] || (col[i - 1] == '0');
        }
        dp_col[1][2] = (row[1] == '0') || !dp_col[1][1];
        for (int i = 2; i <= n; ++i) {
            dp_col[i][2] = !dp_col[i - 1][2] || !dp_col[i][1];
        }

        while (q--) {
            int x, y;
            scanf("%d %d", &x, &y);

            if (x <= 2) {
                printf("%d", dp_row[x][y]);
            } else if (y <= 2) {
                printf("%d", dp_col[x][y]);
            } else if (x > y) {
                printf("%d", dp_col[x - (y - 2)][2]);
            } else {
                printf("%d", dp_row[2][y - (x - 2)]);
            }
        }
        puts("");
    }

    return 0;
}
