#include <bits/stdc++.h>
#include <unordered_set>
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

#define MAX 105

int g[MAX][MAX];

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        int trace = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &g[i][j]);
                if (i == j) {
                    trace += g[i][j];
                }
            }
        }

        int cnt_rows = 0;
        for (int i = 0; i < n; ++i) {
            bool all_different = 1;
            unordered_set<int> vals_in_row;
            for (int j = 0; j < n; ++j) {
                if (vals_in_row.find(g[i][j]) != vals_in_row.end()) {
                    all_different = 0;
                    break;
                }
                vals_in_row.insert(g[i][j]);
            }
            if (!all_different) {
                cnt_rows++;
            }
        }

        int cnt_cols = 0;
        for (int j = 0; j < n; ++j) {
            bool all_different = 1;
            unordered_set<int> vals_in_col;
            for (int i = 0; i < n; ++i) {
                if (vals_in_col.find(g[i][j]) != vals_in_col.end()) {
                    all_different = 0;
                    break;
                }
                vals_in_col.insert(g[i][j]);
            }
            if (!all_different) {
                cnt_cols++;
            }
        }

        printf("Case #%d: %d %d %d\n", tc, trace, cnt_rows, cnt_cols);
    }

    return 0;
}
