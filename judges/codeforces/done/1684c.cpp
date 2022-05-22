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

#define MAX 200005

int sorted[MAX];
vector<int> g[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        bool can = 1;
        int first_diff = -1, second_diff = -1;
        for (int i = 0; i < n; ++i) {
            g[i].clear();
            for (int j = 0; j < m; ++j) {
                int a;
                scanf("%d", &a);
                g[i].pb(a);
                sorted[j] = a;
            }
            sort(sorted, sorted + m);

            int cnt_diff = 0;
            for (int j = 0; j < m; ++j) {
                if (g[i][j] != sorted[j]) {
                    if (!cnt_diff) {
                        if (first_diff != -1 && j != first_diff) {
                            can = 0;
                        } else {
                            first_diff = j;
                        }
                    } else if (cnt_diff == 1) {
                        if (second_diff != -1 && j != second_diff) {
                            can = 0;
                        } else {
                            second_diff = j;
                        }
                    } else {
                        can = 0;
                    }
                    cnt_diff++;
                }
            }
            if (cnt_diff == 1) {
                can = 0;
            }
        }

        if (can && first_diff != -1) {
            for (int i = 0; i < n; ++i) {
                bool is_sorted = 1;
                for (int j = 1; j < m; ++j) {
                    if (g[i][j] < g[i][j - 1]) {
                        is_sorted = 0;
                    }
                }
                if (is_sorted && g[i][first_diff] != g[i][second_diff]) {
                    can = 0;
                }
            }
        }

        if (first_diff == -1 && second_diff == -1) {
            first_diff = second_diff = 0;
        }

        if (!can) {
            printf("-1\n");
        } else {
            printf("%d %d\n", first_diff + 1, second_diff + 1);
        }
    }

    return 0;
}
