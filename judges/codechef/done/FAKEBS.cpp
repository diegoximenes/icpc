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

int a[MAX], sorted_a[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        map<int, int> pos;
        int n, q;
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            sorted_a[i] = a[i];
            pos[a[i]] = i;
        }

        map<int, int> correct_pos;
        sort(sorted_a + 1, sorted_a + n + 1);
        for (int i = 1; i <= n; ++i) {
            correct_pos[sorted_a[i]] = i;
        }

        while (q--) {
            int x;
            scanf("%d", &x);
            int cnt_bigger = 0, cnt_smaller = 0;
            int cnt_correct_smaller = 0, cnt_correct_bigger = 0;
            int lo = 1, hi = n, posx = pos[x];
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (a[mid] == x) {
                    break;
                }
                if (a[mid] > x) {
                    if (posx > mid) {
                        lo = mid + 1;
                        cnt_bigger++;
                    } else {
                        hi = mid - 1;
                        cnt_correct_bigger++;
                    }
                } else {
                    if (posx < mid) {
                        hi = mid - 1;
                        cnt_smaller++;
                    } else {
                        lo = mid + 1;
                        cnt_correct_smaller++;
                    }
                }
            }

            int sol = max(cnt_bigger, cnt_smaller);
            if (n == 2) {
                if (a[1] > a[2] && sol > 0) {
                    sol = -1;
                }
            } else {
                if ((sol > correct_pos[x] - 1 - cnt_correct_smaller) ||
                    (sol > n - correct_pos[x] - cnt_correct_bigger)) {
                    sol = -1;
                }
            }
            // printf("cnt_bigger=%d, cnt_smaller=%d, cnt_correct_smaller=%d, cnt_correct_bigger=%d, sol=%d\n",
            //        cnt_bigger, cnt_smaller, cnt_correct_smaller, cnt_correct_bigger, sol);
            printf("%d\n", sol);
        }
    }

    return 0;
}
