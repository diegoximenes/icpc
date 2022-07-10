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

#define MAX 1000

int p[MAX], out[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        set<int> not_taken;
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &p[i]);
            not_taken.insert(i + 1);
        }

        if (n == 1) {
            printf("-1\n");
        } else {
            for (int i = 0; i < n - 2; ++i) {
                int smallest = *not_taken.begin();
                not_taken.erase(not_taken.begin());
                if (smallest != p[i]) {
                    out[i] = smallest;
                } else {
                    int second_smallest = *not_taken.begin();
                    not_taken.erase(not_taken.begin());
                    not_taken.insert(smallest);
                    out[i] = second_smallest;
                }
            }

            int smallest = *not_taken.begin();
            not_taken.erase(not_taken.begin());
            int second_smallest = *not_taken.begin();
            if (p[n - 2] == smallest || p[n - 1] == second_smallest) {
                out[n - 2] = second_smallest;
                out[n - 1] = smallest;
            } else {
                out[n - 2] = smallest;
                out[n - 1] = second_smallest;
            }

            printf("%d", out[0]);
            for (int i = 1; i < n; ++i) {
                printf(" %d", out[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
